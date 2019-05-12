from math import inf


def miu(x: int, a: tuple, b: tuple) -> float:
    return a[1] + ((x - a[0]) / (b[0] - a[0])) * (b[1] - a[1])


class Temperature:
    def __init__(self, value):
        self.value = value
        self.sets = {
            'cold': [(-inf, 1), (30, 1), (50, 0), (inf, 0)],
            'cool': [(-inf, 0), (30, 0), (50, 1), (70, 0), (inf, 0)],
            'moderate': [(-inf, 0), (70, 1), (80, 0), (inf, 0)],
            'hot': [(-inf, 0), (70, 0), (90, 1), (110, 0), (inf, 0)],
            'very hot': [(-inf, 0), (90, 0), (110, 1), (inf, 1)]
        }

    def fuzzy(self):
        ret = {}
        graph = self.sets
        value = self.value
        for key in graph.keys():
            for i in range(len(graph[key]) - 1):
                if graph[key][i][0] <= value <= graph[key][i + 1][0]:
                    if graph[key][i][0] == -inf:
                        ret[key] = graph[key][i][1]
                        continue
                    if graph[key][i + 1][0] == inf:
                        ret[key] = graph[key][i + 1][1]
                        continue
                    ret[key] = miu(value, graph[key][i], graph[key][i + 1])
        return ret


class Capacity:
    def __init__(self, value):
        self.value = value
        self.sets = {
            'small': [(-inf, 1), (5, 0), (inf, 0)],
            'medium': [(-inf, 0), (3, 0), (5, 1), (7, 0), (inf, 0)],
            'high': [(-inf, 0), (5, 0), (inf, 1)]
        }

    def fuzzy(self):
        ret = {}
        graph = self.sets
        value = self.value
        for key in graph.keys():
            for i in range(len(graph[key]) - 1):
                if graph[key][i][0] <= value <= graph[key][i + 1][0]:
                    if graph[key][i][0] == -inf:
                        ret[key] = graph[key][i][1]
                        continue
                    if graph[key][i + 1][0] == inf:
                        ret[key] = graph[key][i + 1][1]
                        continue
                    delta_y = graph[key][i + 1][1] - graph[key][i][1]
                    delta_x = graph[key][i + 1][0] - graph[key][i][0]
                    ret[key] = graph[key][i][1] + ((value - graph[key][i][0]) / delta_x) * delta_y
        return ret


class Power:
    def __init__(self, value):
        self.value = value
        self.sets = {
            'small': [(-inf, 1), (10, 0), (inf, 0)],
            'medium': [(-inf, 0), (5, 0), (10, 1), (15, 0), (inf, 0)],
            'high': [(-inf, 0), (10, 0), (inf, 1)]
        }

    def fuzzy(self):
        ret = {}
        graph = self.sets
        value = self.value
        for key in graph.keys():
            for i in range(len(graph[key]) - 1):
                if graph[key][i][0] <= value <= graph[key][i + 1][0]:
                    if graph[key][i][0] == -inf:
                        ret[key] = graph[key][i][1]
                        continue
                    if graph[key][i + 1][0] == inf:
                        ret[key] = graph[key][i + 1][1]
                        continue
                    delta_y = graph[key][i + 1][1] - graph[key][i][1]
                    delta_x = graph[key][i + 1][0] - graph[key][i][0]
                    ret[key] = graph[key][i][1] + ((value - graph[key][i][0]) / delta_x) * delta_y
        return ret
