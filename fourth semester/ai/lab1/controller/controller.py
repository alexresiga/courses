from typing import List
from domain.puzzle import Sudoku
from copy import deepcopy
from math import sqrt
from random import shuffle


class Controller:

    def __init__(self, sudoku: Sudoku):
        self.__sudoku = sudoku

    def get_sudoku(self):
        return self.__sudoku

    @staticmethod
    def is_solution(s: Sudoku) -> bool:
        return s.is_filled()

    @staticmethod
    def validate_line(alist: List[List[int]], i: int) -> bool:
        return len([x for x in alist[i] if x != 0]) == len(set([x for x in alist[i] if x != 0]))

    @staticmethod
    def validate_column(alist: List[List[int]], j: int) -> bool:
        return len([row[j] for row in alist if row[j] != 0]) == len(set(row[j] for row in alist if row[j] != 0))

    @staticmethod
    def validate_square(alist: List[List[int]], i: int, j: int, e: int) -> bool:
        count = 0
        n = int(sqrt(len(alist[0])))
        sec_top_x, sec_top_y = n * (i // n), n * (j // n)
        for x in range(sec_top_x, sec_top_x + n):
            for y in range(sec_top_y, sec_top_y + n):
                if alist[x][y] == e:
                    count += 1
        return True if count == 1 else False

    @staticmethod
    def order_states(states: List[Sudoku]) -> List[Sudoku]:
        sort_states = sorted(states)
        return sort_states

    @staticmethod
    def expand(s: Sudoku) -> List[Sudoku]:
        children = []
        interval = [x for x in range(1, s.get_size() + 1)]
        shuffle(interval)
        # for i in interval:
        for i in range(1, s.get_size() + 1):
            tmp = deepcopy(s.get_initial_state())
            row, column = s.get_first_empty()[0], s.get_first_empty()[1]
            tmp[row][column] = i
            if Controller.validate_line(tmp, row) and Controller.validate_column(tmp, column) and \
                    Controller.validate_square(tmp, row, column, i):
                children.append(Sudoku(tmp))
        return children

    def bfs(self) -> Sudoku:
        queue = [self.__sudoku]
        while len(queue) > 0:
            current_state = queue.pop(0)
            if self.is_solution(current_state):
                return current_state
            queue = queue + Controller.expand(current_state)

    def gbfs(self) -> Sudoku:
        queue: List[Sudoku] = [self.__sudoku]
        while len(queue) > 0:
            current_state = queue.pop(0)
            if self.is_solution(current_state):
                return current_state
            queue = queue + Controller.order_states(Controller.expand(current_state))
