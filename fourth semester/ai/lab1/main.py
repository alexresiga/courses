from controller.controller import Controller
from domain.puzzle import Sudoku
from ui.ui import UI


def read_sudoku() -> Sudoku:
    try:
        filename = "data9.in"
        grid = []
        with open(filename) as f:
            for line in f:
                line = line.replace('\n', '').rstrip(' ')
                row = list(map(int, line.split(" ")))

                grid.append(row)
    except IOError:
        raise Exception("File is missing")
    return Sudoku(grid)


sudoku = read_sudoku()
controller = Controller(sudoku=sudoku)
ui = UI(controller)
if __name__ == '__main__':
    ui.run()
