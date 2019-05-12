import statistics

from domain.Algorithm import Algorithm
from domain.Problem import Problem
import matplotlib.pyplot


class Application:
    def __init__(self):
        self.problem = Problem()
        self.algorithm = Algorithm('data/params.in')

    def run(self):
        print(self.algorithm.run())

    def run_with_plot(self):
        results = list(map(lambda x: x.fitness_score, self.algorithm.run_plot()))
        matplotlib.pyplot.plot(range(1, len(results) + 1), results)
        matplotlib.pyplot.show()
        print(self.algorithm.population.best())

    def run_statistics(self):
        results = []
        for _ in range(3):
            algorithm = Algorithm("data/params.in")
            results.append(algorithm.run().fitness_score)
        print("Average fitness: {}".format(statistics.mean(results)))
        print("Standard deviation of fitness: {}".format(statistics.stdev(results)))


if __name__ == '__main__':
    app = Application()
    app.run()
