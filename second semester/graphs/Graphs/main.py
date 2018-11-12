from copy import deepcopy
from queue import PriorityQueue


class Graph:
    def __init__(self, filename):
        self.dictOut = {}
        self.dictIn = {}

        with open(filename, "r") as f:
            self.n, self.m = map(int, f.readline().split(' '))
            for i in range(self.n):
                self.dictIn[i] = []
                self.dictOut[i] = []
            for line in f.readlines():
                x, y, c = map(int, line.split(' '))
                self.addEdge(x, y)

    def getVertices(self):
        return self.n

    def parseX(self):
        """
        :returns: an iterable containing all the vertices
        """
        alist = []
        for x in self.dictOut.keys():
            alist.append(x)

        return alist

    def parseNOut(self, x):
        """
        Returns an iterable containing all the outbound neighbours of the vertex x
        :param x: an existing vertex of the graph
        :return:
        """
        if x in self.dictOut.keys():
            return self.dictOut[x]

        return None

    def parseNIn(self, x):
        """
        Returns an iterable containing all the inbound neighbours of the vertex x
        :param x:
        :return:
        """

        if x in self.dictIn.keys():
            return self.dictIn[x]

        return None

    def isEdge(self, x, y):
        """
        returns True if there is an Edge between vertices x and y
        :param x: vertex
        :param y: vertex
        :return: True if edge exists, False otherwise
        """
        return x in self.dictOut.keys() and y in self.dictOut[x]

    def addEdge(self, x, y):
        """
        Add an edge from x to y
        :return:
        """
        # if not self.isEdge(x, y) and x in self.dictIn.keys() and y in self.dictIn.keys():
        self.dictOut[x].append(y)
        self.dictIn[y].append(x)
        # else:
        #   raise KeyError("non existing vertices")

    def getInDegree(self, x):
        """
        get in degree of x vertex
        :param x:
        :return:
        """
        if x in self.dictIn.keys():
            return len(self.dictIn[x])

        return None

    def getOutDegree(self, x):
        """
        get out degree of x vertex
        :param x:
        :return:
        """
        if x in self.dictOut.keys():
            return len(self.dictOut[x])

        return None

    def removeVertex(self, x):
        """
        remove an existing vertex
        :param x:
        :return:
        """
        if x in self.dictIn:
            for i in range(self.n):
                if x in self.dictOut[i]:
                    self.dictOut[i].remove(x)
                if x in self.dictIn[i]:
                    self.dictIn[i].remove(x)
            self.n = self.n - 1
            del self.dictIn[x]
            del self.dictOut[x]
            self.dictIn.pop(x, None)
            self.dictOut.pop(x, None)
        else:
            raise KeyError("non existing vertex")

    def addVertex(self, x):
        """
        add a new vertex x
        :param x:
        :return:
        """
        if x not in self.dictIn:
            self.dictIn[x] = []
            self.dictOut[x] = []
            self.n += 1
        else:
            raise KeyError("cannot add vertex")

    def copyGraph(self):
        return deepcopy(self)


class WeightedGraph(Graph):
    def __init__(self, filename):
        self.costs = {}

        super().__init__(filename)
        with open(filename, "r") as f:
            self.n, self.m = map(int, f.readline().split(' '))
            for line in f.readlines():
                x, y, c = map(int, line.split(' '))
                self.costs[(x, y)] = c
                self.costs[(y, x)] = c

    def removeEdge(self, x, y):
        """
        remove edge from x to y if it exists
        :param x:
        :param y:
        :return:
        """
        if x in self.dictIn[y] and x in self.dictOut:
            del self.costs[(x, y)]
            self.dictOut[x].remove(y)
            self.dictIn[y].remove(x)

    def getCost(self, x, y):
        """
        get cost of edge from x to y
        :param x:
        :param y:
        :return:
        """
        if self.isEdge(x, y):
            return self.costs[(x, y)]

    def setCost(self, x, y, newCost):
        """
        modify cost of edge from x to y
        :param newCost:
        :param x:
        :param y:
        :return:
        """
        if self.isEdge(x, y):
            self.costs[(x, y)] = newCost
        else:
            raise KeyError("non existing edge")


def parseNOutUI(graph: Graph):
    n = int(input("enter vertex: "))
    graph.parseNOut(n)


def parseNInUI(graph: Graph):
    n = int(input("Enter vertex: "))
    graph.parseNIn(n)


def getInbound(graph: Graph):
    n = int(input("Enter vertex: "))
    print(" ".join(map(str, graph.parseNIn(n))))


def getOutbound(graph: Graph):
    n = int(input("Enter vertex: "))
    print(" ".join(map(str, graph.parseNOut(n))))


def addVertexUI(graph: Graph):
    n = int(input("Enter new vertex: "))
    graph.addVertex(n)


def addEdgeUI(graph: Graph):
    x, y = int(input("Enter outbound vertex: ")), int(input("Enter inbound vertex: "))
    graph.addEdge(x, y)


def getCostUI(graph: WeightedGraph):
    x, y = int(input("Enter outbound vertex: ")), int(input("Enter inbound vertex: "))
    print(graph.getCost(x, y))


def setCostUI(graph: WeightedGraph):
    x, y, c = int(input("Enter outbound vertex: ")), int(input("Enter inbound vertex: ")), int(input("Enter cost: "))
    graph.setCost(x, y, c)


def isEdgeUI(graph: Graph):
    x, y = int(input("Enter outbound vertex: ")), int(input("Enter inbound vertex: "))
    if graph.isEdge(x, y):
        print("There is edge from {} to {}".format(x, y))
    else:
        print("There is no edge from {} to {}".format(x, y))


def removeEdgeUI(graph: WeightedGraph):
    x, y = int(input("Enter outbound vertex: ")), int(input("Enter inbound vertex: "))
    graph.removeEdge(x, y)


def getInDegreeUI(graph: Graph):
    n = int(input("Enter vertex: "))
    print(graph.getInDegree(n))


def getOutDegreeUI(graph: Graph):
    n = int(input("Enter vertex: "))
    print(graph.getOutDegree(n))


def getVerticesUI(graph: Graph):
    print(graph.getVertices())


def removeVertexUI(graph: Graph):
    n = int(input("Enter vertex: "))
    graph.removeVertex(n)


def listVertices(graph: Graph):
    print(graph.parseX())


def shortestPath(g, s, t):
    """

    :param g: the graph
    :param s: starting vertex
    :param t: target vertex
    :return: alist with the vertices of the path from s to t, otherwise None if t is not accessible from s
    """
    distances, fathers = bfs(g, s)
    return retrievePath(g, s, t, fathers)


def bfs(g: Graph, s):
    """

    :param g: the graph
    :param s: starting vertex
    :return: pair of dictionaries, with keys - accessible vertices and values - distances/fathers
    """
    distances = {s: 0}
    fathers = {s: None}
    queue = [s]
    while len(queue) > 0:
        node = queue[0]
        for i in g.parseNOut(node):
            if i in distances.keys():
                continue
            fathers[i] = node
            distances[i] = distances[node] + 1
            queue.append(i)
        queue.pop(0)

    return distances, fathers


def retrievePath(g: Graph, s, t, fathers):
    """
    
    :param g: the graph
    :param s: starting vertex
    :param t: target vertex
    :param fathers: dictionary with keys as accessible vertices and values as each vertex's father
    :return: a list with the vertices of the path from s to t, otherwise None if t is not accessible from s
    """
    if t not in fathers.keys():
        return None
    l = []
    c = t
    while c != s:
        l.append(c)
        c = fathers[c]
    l.append(s)
    l.reverse()
    return l


def testShortestPath():
    g = WeightedGraph("date.txt")
    print(shortestPath(g, 3, 923))


def main():
    commands = {1: ('Get the number of vertices', getVerticesUI), 2: ('Check if edge exists', isEdgeUI),
                3: ('Get the in degree of vertex', getInDegreeUI),
                4: ('Get the out degree of vertex', getOutDegreeUI), 5: ('Get outbound edges', getOutbound),
                6: ('Get inbound edges', getInbound), 7: ('Get cost of edge', getCostUI),
                8: ('Modify cost of edge', setCostUI), 9: ('Remove edge', removeEdgeUI),
                10: ('Remove vertex', removeVertexUI), 11: ('Add vertex', addVertexUI), 12: ('Add edge', addEdgeUI),
                13: ('View vertices', listVertices)}

    dirGraph = WeightedGraph('date.txt')
    print(dirGraph.costs.values())
    while True:
        try:
            print('\n' + '\n'.join(["{}: {}".format(i, c[0]) for i, c in commands.items()])+'\n')
            command = int(input("command: "))
            commands[command][1](dirGraph)
        except Exception as exc:
            print(str(exc))


# main()
# testShortestPath()


def minCostWalk(g: WeightedGraph, s, t):
    """

    :param g:
    :param s:
    :param t:
    :return:
    """
    distances = [float("Inf")] * g.n
    walk = [s]

    distances[s] = 0
    for i in range(g.n - 1):
        for row in g.costs:
            edge = tuple(row)
            if distances[edge[0]] != float("Inf") and distances[edge[0]] + g.costs[row] < distances[edge[1]]:
                distances[edge[1]] = distances[edge[0]] + g.costs[row]
                print(edge[0])
                walk.append(edge[0])
    walk.append(t)
    for row in g.costs:
        edge = tuple(row)
        if distances[edge[0]] != float("Inf") and distances[edge[0]] + g.costs[row] < distances[edge[1]]:
            print("There are negative costs cycle")
            return
    return distances[t], walk


class UndirectedGraph(WeightedGraph):
    def __init__(self, filename):
        super().__init__(filename)
        with open(filename, "r") as f:
            self.n, self.m = map(int, f.readline().split(' '))
            for line in f.readlines():
                x, y, c = map(int, line.split(' '))
                self.addEdge(y, x)


def primAlgorithm(g: UndirectedGraph):
    """

    :param g:
    :return:
    """
    priorityQueue = PriorityQueue()
    prev = {}
    dist = {}
    edges = []
    s = g.getVertices() - 1
    vertices = {s}
    for x in g.parseNIn(s):
        dist[x] = g.getCost(x, s)
        prev[x] = s
        priorityQueue.put((-dist[x], x))

    while not priorityQueue.empty():
        x = priorityQueue.get()[1]
        if x not in vertices:
            edges.append((x, prev[x]))
            vertices.add(x)
            for y in g.parseNIn(x):
                if y not in dist.keys() or g.getCost(x, y) < dist[y]:
                    dist[y] = g.getCost(x, y)
                    priorityQueue.put((dist[y], y))
                    prev[y] = x
    cost = sum(g.getCost(_[0], _[1]) for _ in edges)
    return edges, cost
