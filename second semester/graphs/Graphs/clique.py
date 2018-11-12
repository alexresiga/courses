from main import UndirectedGraph
from collections import defaultdict


def order(graph: UndirectedGraph):
    ordering = []
    ordering_set = set()
    degrees = defaultdict(lambda: 0)
    degen = defaultdict(list)
    max_deg = -1
    for v in graph.parseX():
        deg = len(graph.parseNIn(v))
        degen[deg].append(v)
        degrees[v] = deg
        if deg > max_deg:
            max_deg = deg

    while True:
        i = 0
        while i <= max_deg:
            if len(degen[i]) != 0:
                break
            i += 1
        else:
            break
        v = degen[i].pop()
        ordering.append(v)
        ordering_set.add(v)
        for w in graph.parseX():
            if w not in ordering_set:
                deg = degrees[w]
                degen[deg].remove(w)
                if deg > 0:
                    degrees[w] -= 1
                    degen[deg - 1].append(w)
    ordering.reverse()
    return ordering


def find_cliques_pivot(graph: UndirectedGraph, r, p, x, cliques):
    if len(p) == 0 and len(x) == 0:
        cliques.append(r)
    else:
        u = iter(p.union(x)).__next__()
        for v in p.difference(graph.parseNOut(u)):
            neighs = graph.parseNOut(v)
            find_cliques_pivot(graph, r.union([v]), p.intersection(neighs), x.intersection(neighs), cliques)
            p.remove(v)
            x.add(v)


def find_cliques(graph: UndirectedGraph):
    p = set(graph.parseX())
    r = set()
    x = set()
    cliques = []

    for v in order(graph):
        neighs = graph.parseNOut(v)
        find_cliques_pivot(graph, r.union([v]), p.intersection(neighs), x.intersection(neighs), cliques)
        p.remove(v)
        x.add(v)

    return sorted(cliques, key=lambda x: len(x))


graph = UndirectedGraph("date.txt")
print(find_cliques(graph))
