from math import exp, inf
from random import random
from copy import deepcopy
from typing import List
import matplotlib.pyplot
import statistics

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


class Swarm:
    def __init__(self, swarm_size, n):
        self.v = [Particle(n) for _ in range(swarm_size)]
        self.n = swarm_size

    def get_best_particles(self, k) -> List:
        self.v.sort(key=lambda particle: particle.best_fitness)
        return self.v[:k]

    def get_best_neighbour(self):
        return self.get_best_particles(1)[0]


class Controller:
    def __init__(self, problem):
        self.problem = problem
        self.params = {}
        self.load_parameters()
        self.swarm = Swarm(self.params["swarmSize"], len(self.problem.data.set))

    def load_parameters(self):
        try:
            f = open("params.in", "r")
            for x in filter(None, f.read().split('\n')):
                (param, value) = x.split(' =')
                value = int(value)
                self.params[param] = value
        except Exception as e:
            print("Exception Controller::loadParameters(fileName): " + str(e))

    def iteration(self):
        for i in range(self.params["swarmSize"]):
            current = self.swarm.v[i]
            p = self.swarm.get_best_neighbour()
            current.update(p, i)
            current.evaluate(self.problem)

    def run(self):
        for i in range(self.params["iterations"]):
            print(i)
            self.iteration()
        return self.swarm.get_best_particles(1)[0]

    def print_run(self):
        best = self.run()
        first, second = [], []
        for i in range(len(best.position)):
            if best.position[i] == 0:
                first.append(i + 1)
            else:
                second.append(i + 1)
        print("first: {}\nsecond: {}".format(first, second))

    def run_with_plot(self):
        best_particles = []
        num_iterations = 0
        while num_iterations < self.params["iterations"]:
            best_particles.append(self.swarm.get_best_particles(1)[0].best_fitness)
            self.iteration()
            num_iterations += 1
        return best_particles

    def print_plot(self):
        results = self.run_with_plot()
        matplotlib.pyplot.plot(range(1, len(results) + 1), results)
        matplotlib.pyplot.show()
        best = self.swarm.get_best_particles(1)[0]
        first, second = [], []
        for i in range(len(best.position)):
            if best.position[i] == 0:
                first.append(i + 1)
            else:
                second.append(i + 1)
        print("first: {}\nsecond: {}".format(first, second))

    def run_statistics(self):
        best_runs = []
        for run in range(self.params["runs"]):
            print("Running %d" % (run + 1))
            best_runs.append(self.run().best_fitness)
        with open("statistics.data", "a") as g:
            g.write("Average fitness: {}\n".format(statistics.mean(best_runs)))
            g.write("Standard deviation of fitness: {}\n\n".format(statistics.stdev(best_runs)))


class Data:
    def __init__(self, input_set, subsets):
        self.set = input_set
        self.subsets = subsets


class Problem:
    def __init__(self, file_name="data.in"):
        self.data = self.load_data(file_name)

    @staticmethod
    def load_data(file_name):
        with open(file_name, "r") as f:
            input_set = f.readline().split(",")
            lst = []
            for element in input_set:
                lst.append(int(element))

            nr_subsets = int(f.readline())
            subsets = []
            for i in range(nr_subsets):
                line = f.readline().split(",")
                subset = []
                for element in line:
                    subset.append(int(element))
                subsets.append(subset)
        return Data(lst, subsets)


p = Problem("data.in")
ctrl = Controller(p)
ctrl.print_plot()
