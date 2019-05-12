from typing import Tuple, List
from collections import defaultdict


class Sudoku:
    def __init__(self, initial_state):
        self.__initial_state = initial_state[:]
        self.__first_empty = (None, None)
        for i in range(len(self.__initial_state[0])):
            for j in range(len(self.__initial_state[0])):
                if initial_state[i][j] == 0:
                    self.__first_empty = (i, j)
                    break

    def get_size(self) -> int:
        return len(self.__initial_state[0])

    def get_initial_state(self) -> List[List[int]]:
        return self.__initial_state

    def is_filled(self) -> bool:
        return self.__first_empty == (None, None)

    def get_first_empty(self) -> Tuple:
        return self.__first_empty

    def heuristics(self) -> int:
        freq = defaultdict(int)
        for i in range(self.get_size()):
            for j in range(self.get_size()):
                freq[self.__initial_state[i][j]] += 1
        return [(k, freq[k]) for k in sorted(freq, key=freq.get)][0][0]

    def __lt__(self, other: "Sudoku"):
        return self.heuristics() < other.heuristics()

    def __str__(self) -> str:
        result = ""
        for i in range(self.get_size()):
            for j in range(self.get_size()):
                result += str(self.__initial_state[i][j]) + " "
            result += '\n'
        return result
