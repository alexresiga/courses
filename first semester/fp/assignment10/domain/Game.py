import time

from domain.Board import Board
from random import randint


class Game:
    def __init__(self, n, m):
        self.__board = Board(n, m)
        self.limit = n+m

    def move_player(self, i, j):
        self.__board.move(j, i, 'X')

    def move_matei(self, i, j):
        self.__board.move(j, i, 'O')

    def move_computer(self):
        """
        determine best position to place computer's move based on how much territory it can fill
        depending on number of squares left empty
        :return:
        """
        # time.sleep(2)
        empty = self.__board.get_empty_squares()
        low_fill, high_fill = self.__board.strategy(empty)
        found = False
        for a in high_fill:
            if self.__board.count_territory(a[0], a[1]) == self.__board.is_won()-1 and found is False:
                self.__board.move(a[0], a[1], 'O')
                found = True
        if found is False:
            if self.__board.is_won() >= self.limit:
                e = randint(0, len(high_fill)-1)
                self.__board.move(high_fill[e][0], high_fill[e][1], 'O')
            else:
                found = False
                for a in low_fill:
                    if self.__board.count_territory(a[0], a[1]) == self.__board.is_won()-1 and found is False:
                        self.__board.move(a[0], a[1], 'O')
                        found = True
                if found is False:
                    e = randint(0, len(low_fill)-1)
                    self.__board.move(low_fill[e][0], low_fill[e][1], 'O')
        self.__board.print_board()

    def printBoard(self):
        self.__board.print_board()

    def printBoardGUI(self, frame):
        self.__board.gui_board(frame)

    def game_won(self):
        return self.__board.is_won()

    @staticmethod
    def store_stats(filename):
        """
        save stats to file
        :param filename:
        :return:
        """
        with open(filename, 'r') as f:
            counter = int(f.readline()) + 1

        with open(filename, 'w') as f:
            f.write(str(counter))

    @staticmethod
    def get_stats():
        """
        read stats from file
        :return:
        """
        with open('player_stats.txt', 'r') as f:
            with open('comp_stats.txt', 'r') as g:
                return f.readline(), g.readline()
