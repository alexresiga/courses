from tkinter import *


class Board:
    def __init__(self, n, m):
        self.__board = [['_' for x in range(m)] for y in range(n)]
        self.rows = n
        self.columns = m

    def print_board(self):
        """
        custom print of game board
        :return:
        """
        print(' |', end=' ')
        for a in range(self.columns):
            print(str(a), end=' '*5)
        print()
        print('-+', end='')
        print('-'*(self.columns*6-2), end='')
        print()
        for i in range(self.rows):
            print(str(i)+'|', end=' ')
            for j in range(self.columns):
                print(self.__board[i][j], end=' '*5)
            print()
            if i != self.rows-1:
                print(' |')
                print(' |')
        print()

    def gui_board(self, frame):
        for i in range(self.rows):
            for j in range(self.columns):
                w = Label(frame, text='{}'.format(self.__board[i][j]), font=("Helvetica", 32))
                w.grid(row=i, column=j, padx=30, pady=10)

    def is_empty(self, x, y):
        """
        determine if space is empty
        :param x: coords
        :param y: coords
        :return: True if empty, false otherwise
        """
        return self.__board[x][y] == '_'

    def get_empty_squares(self):
        rez = []
        for i in range(self.rows):
            for j in range(self.columns):
                if self.__board[i][j] == '_':
                    rez.append((i, j))
        return rez

    def is_won(self):
        return len(self.get_empty_squares())

    def fill_territory(self, x, y, p):
        """
        fill the surroundings of the position played with specific symbol based on player
        :param x: x coordinate
        :param y: y coordinate
        :param p: player's symbol
        :return: number of filled spaces(min: 1, max:8)
        """
        fill = 0
        territory = {'X': '+', 'O': '*'}
        self.__board[x][y] = p
        dirs = [(-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
        for d in dirs:
            j = y + d[0]
            i = x + d[1]
            if i in range(self.rows) and j in range(self.columns) and self.is_empty(i, j):
                self.__board[i][j] = territory[p]
                fill += 1
        return fill

    def count_territory(self, x, y):
        """
        count the number of spaces filled
        :param x: x coordinate
        :param y: y coordinate
        :return: number of filled spaces(min: 1, max:8)
        """
        fill = 0
        dirs = [(-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)]
        for d in dirs:
            j = y + d[0]
            i = x + d[1]
            if i in range(self.rows) and j in range(self.columns) and self.is_empty(i, j):
                fill += 1
        return fill

    def strategy(self, alist):
        """
        implement strategy for computer in order to increase chances to win the game
        :param alist: list of empty squares
        :return: best position to play, based on the filling of that move
        """
        alist.sort(key=lambda x: self.count_territory(x[0], x[1]), reverse=True)
        return alist[len(alist)//2:], alist[:len(alist)//2]

    def move(self, x, y, p):
        """
        place move on board
        :param x: x coordinate
        :param y: y coordinate
        :param p: pawn symbol
        """
        if x < 0 or x > self.columns or y < 0 or y > self.rows:
            raise Exception("invalid move")
        if not self.is_empty(x, y):
            raise Exception("space not empty")
        self.fill_territory(x, y, p)
