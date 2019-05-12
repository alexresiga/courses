class Problem:
    def __init__(self, filename="data/data.in"):
        self.filename = filename
        self.board = [[0 for _ in range(15)] for _ in range(15)]
        with open(self.filename, 'r') as f:
            for i in range(15):
                self.board[i] = [int(x) for x in f.readline().strip().split()]


# problem = Problem("../data/data.in")
# for row in problem.board:
#     print(str(row))
