from math import exp, inf
from random import random
from copy import deepcopy

from utils import partition_distance, num_of_subsets_included, random_num


def s(v):
    return 1 / (1 + exp(-v))


W, C1, C2 = 0.5, 0.5, 1.5


class Particle:
    global W, C1, C2

    def __init__(self, size):
        self.size = size
        self.position = [round(random_num()) for _ in range(self.size)]
        self.velocity = [random_num() for _ in range(self.size)]
        self.fitness = 0
        self.best_position = deepcopy(self.position)
        self.best_fitness = inf
        self.w = W

    def evaluate(self, problem):
        first_partition, second_partition = [], []
        for i in range(self.size):
            if self.position[i] == 0:
                first_partition.append(problem.data.set[i])
            else:
                second_partition.append(problem.data.set[i])

        self.fitness = partition_distance(first_partition, second_partition, problem.data.set) \
            + num_of_subsets_included(first_partition, second_partition, problem.data.subsets)

        if self.fitness < self.best_fitness:
            self.best_fitness = self.fitness
            self.best_position = deepcopy(self.position)

    def update(self, particle: "Particle", t):
        global W, C1, C2
        for i in range(self.size):
            if random_num() < s(self.velocity[i]):
                self.position[i] = 1 - self.position[i]
                self.velocity[i] = self.w * self.velocity[i] + \
                    C1 * random_num() * (particle.best_position[i] - self.position[i]) + \
                    C2 * random() * (self.best_position[i] - self.position[i])
            self.w = W / (t + 1)

    def __str__(self):
        return ' '.join(map(str, self.position))
