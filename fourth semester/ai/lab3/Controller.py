import statistics

import matplotlib.pyplot

from Swarm import Swarm


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
