from typing import List

from domain.Problem import Problem
from itertools import groupby, cycle
from domain.Color import *
from random import shuffle, random, randint, sample


class Individual:
    def __init__(self, problem: Problem, words):
        self.problem = problem
        self.board = problem.board[:]
        self.words: List = words[:]
        self.used = words[:]
        self.fitness_score = 0

    @staticmethod
    def spaces_available(alist) -> List:
        """
        :param alist:
        :return: a list of lists of elements of the form [start_index, length]
        """
        groups = groupby(alist)
        result = [[label, sum(1 for _ in group)] for label, group in groups]
        index = 0
        for re in result:
            re.append(index)
            index += re[1]
        return [re[:0:-1] for re in result if re[0] != 0]

    @staticmethod
    def fit_column(alist) -> List:
        groups = groupby(alist, key=lambda x: x != 0)
        result = [[label, sum(1 for _ in group)] for label, group in groups]
        index = 0
        for re in result:
            re.append(index)
            index += re[1]
        return [re[:0:-1] for re in result if re[0] != 0]

    def fitness(self):
        self.fitness_score = 0
        self.used = self.words[:]
        self.board = Problem().board
        for i, row in enumerate(self.board):
            for space in self.spaces_available(row):
                candidates: List[List[int, int]] = list(filter(lambda x: len(x) == space[1], self.used))
                if len(candidates) == 0:
                    continue
                word = candidates[0]
                # insert word in available space
                row[space[0]: sum(space)] = word
                self.used.remove(word)

        transpose = [[row[i] for row in self.board] for i in range(len(self.board[0]))]

        for j, column in enumerate(transpose):
            for space in self.fit_column(column):
                candidates: List[List[int, int]] = list(filter(lambda x: len(x) == space[1], self.used))
                if len(candidates) == 0:
                    continue
                word = candidates[0]
                # increase letter match score
                for ii in range(space[0], sum(space)):
                    if self.board[ii][j] != 1:
                        if word[ii - space[0]] == self.board[ii][j]:
                            self.fitness_score += 1
                # insert word in available space
                column[space[0]: sum(space)] = word
                self.used.remove(word)

        self.board = [[row[i] for row in transpose] for i in range(len(transpose[0]))]

    def mutation(self, mp: float):
        if random() > mp:
            first, second, ff, ss = randint(0, len(self.words) - 1), randint(0, len(self.words) - 1), randint(0, len(
                self.words) - 1), randint(0, len(self.words) - 1)
            self.words[first], self.words[second] = self.words[second], self.words[first]
            self.words[ff], self.words[ss] = self.words[ss], self.words[ff]

    def crossover(self, other: "Individual"):

        offspring = Individual(Problem("data/data.in"), [])
        offspring.words = [None for _ in range(34)]
        offspring.words[:17] = self.words[:17]
        i = 17

        for word in other.words:
            if word not in offspring.words:
                offspring.words[i] = word
                i += 1
        # ind1 = self.words[:]
        # ind2 = other.words[:]
        # size = min(len(ind1), len(ind2))
        # cxpoint1 = randint(1, size)
        # cxpoint2 = randint(1, size - 1)
        # if cxpoint2 >= cxpoint1:
        #     cxpoint2 += 1
        # else:
        #     cxpoint1, cxpoint2 = cxpoint2, cxpoint1
        #
        # ind1[cxpoint1:cxpoint2], ind2[cxpoint1:cxpoint2] \
        #     = ind2[cxpoint1:cxpoint2], ind1[cxpoint1:cxpoint2]
        # offspring.words = ind1[:]
        return offspring

    def __lt__(self, other: "Individual"):
        return self.fitness_score < other.fitness_score

    def __eq__(self, other):
        return self.words == other.words

    def __str__(self):
        # return str(self.fitness_score)
        result = ""
        for r in self.board:
            for e in r:
                if e != 0:
                    result += Color.F_Red + e + Color.F_Default + " "
                else:
                    result += Color.F_Cyan + "█" + Color.F_Default + " "
            result += '\n'
        return result

# ceva = Individual(Problem("../data/data.in"))
# ceva.fitness()
# print(ceva)
