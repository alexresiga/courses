from typing import List

from Particle import Particle


class Swarm:
    def __init__(self, swarm_size, n):
        self.v = [Particle(n) for _ in range(swarm_size)]
        self.n = swarm_size

    def get_best_particles(self, k) -> List:
        self.v.sort(key=lambda particle: particle.best_fitness)
        return self.v[:k]

    def get_best_neighbour(self):
        return self.get_best_particles(1)[0]
