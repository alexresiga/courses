from domain.Individual import Individual
from domain.Problem import Problem
from random import randint, random, sample

WORDS = ["guarantees", "aura", "taken", "orchestra", "spelling",
         "creed", "dawning", "deadpan", "nodules", "citizen", "idles",
         "lifeboat", "incurable", "fatty", "soda", "persistent", "guts",
         "identities", "ask", "pawed", "lucid", "annul", "illusory",
         "tooting", "soluble", "encaged", "coffers", "merchant", "buffs",
         "untie", "pizza", "toe", "abandoning", "cyst"]


class Population:
    def __init__(self, size, crossover_probability, mutation_probability):
        self.size = size
        self.individuals = []
        for _ in range(size):
            # first, second, ff, ss = randint(0, 33), randint(0, 33), randint(0, 33), randint(0, 33)
            # WORDS[first], WORDS[second] = WORDS[second], WORDS[first]
            # WORDS[ff], WORDS[ss] = WORDS[ss], WORDS[ff]
            self.individuals.append(Individual(Problem("data/data.in"), sample(WORDS, 34)))
        for i in self.individuals:
            i.fitness()
        self.cp = crossover_probability
        self.mp = mutation_probability

    def tournament_selection(self):
        # return sorted(self.individuals, reverse=True)[0]
        return sorted([self.individuals[randint(0, len(self.individuals) - 1)] for _ in range(10)], reverse=True)

    def crossover(self):
        for _ in self.individuals:
            first, second = self.tournament_selection()[:2]
            first_parent = first

            first_parent.fitness()
            second_parent = second
            second_parent.fitness()
            if random() < self.cp:
                offspring = first_parent.crossover(second_parent)

                offspring.fitness()
                if random() < self.mp:
                    offspring.mutation(self.mp)
                    offspring.fitness()

                if offspring not in self.individuals:
                    self.individuals.append(offspring)

    def selection(self):

        self.individuals = sorted(self.individuals, reverse=True)[:self.size]

    def evaluate(self):
        self.crossover()

    def best(self):
        sorted(self.individuals, key=lambda x: -x.fitness_score)
        best = self.individuals[0]

        return best
