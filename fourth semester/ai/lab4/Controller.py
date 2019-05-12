from Domain import Temperature, Capacity
from Ruler import Ruler


class Controller:
    def __init__(self, temperature, capacity):
        self.rules = Ruler()
        self.t = Temperature(temperature)
        self.c = Capacity(capacity)

    def solve(self):
        agg = self.rules.evaluate(self.t, self.c)
        print(list(agg.items()))
        return sorted(list(agg.items()), key=lambda x: -x[1])[0][0]
