from domain.Population import Population


class Algorithm:
    def __init__(self, filename):
        with open(filename, "r") as f:
            self.pop_size = int(f.readline())
            self.cp = float(f.readline())
            self.mp = float(f.readline())
            self.n_iterations = int(f.readline())
        self.population = Population(self.pop_size, self.cp, self.mp)

    def iterate(self):
        self.population.evaluate()
        self.population.selection()

    def run(self):
        num_iterations = 0
        while num_iterations < self.n_iterations:
            self.iterate()
            print("ITERATION: {} - FITTEST: {}".format(num_iterations, self.population.best().fitness_score))
            num_iterations += 1
        return self.population.best()

    def run_plot(self):
        best_fitness = []
        num_iterations = 0
        for e in self.population.individuals:
            print(e.fitness_score)

        while num_iterations < self.n_iterations:

            best_fitness.append(self.population.best())
            self.iterate()
            if self.population.best().fitness_score == 60:
                break
            print("ITERATION: {} - FITTEST: {}".format(num_iterations, self.population.best().fitness_score))
            num_iterations += 1
        return best_fitness
