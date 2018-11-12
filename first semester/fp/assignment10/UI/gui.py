from tkinter import *
from domain.Game import Game
from tkinter import messagebox


class GUI:
    def __init__(self, master):
        self.master = master

        self.start()

    def start(self):

        self.master.geometry('{}x{}'.format(320, 300))
        self.master.title("OBSTRUCTION")
        Label(root, text="Enter board size:").grid(row=0, column=1, sticky=N)
        Label(root, text="Rows: ").grid(row=1)
        Label(root, text="Columns: ").grid(row=2)

        r = Entry(root)
        c = Entry(root)

        r.grid(row=1, column=1)
        c.grid(row=2, column=1)
        Button(root, text="Start game!", command=lambda: self.new_game(int(r.get()), int(c.get()))).grid(row=3, column=1)

    def new_game(self, n, m):
        window = Toplevel(self.master)
        window.title("Game of {}x{} in progress..".format(n, m))
        game = Game(n, m)
        game.printBoardGUI(window)

        def update_board(a, b):
            try:
                game.move_player(int(a), int(b))
                game.printBoardGUI(window)
                if game.game_won() == 0:
                    messagebox.showinfo(title=':)', message='YOU WON!!!')
                    exit(0)
                game.move_computer()
                game.printBoardGUI(window)
                if game.game_won() == 0:
                    messagebox.showinfo(title=':(', message='YOU LOST!!!')
                    exit(0)
                c.focus_set()
            except Exception as exc:
                messagebox.showerror(title="Error occurred :(", message=str(exc))

        button1 = Button(window, text="Make move", command=lambda: update_board(int(r.get()), int(c.get())))
        button1.grid(row=n+5, columnspan=m)
        r = Entry(window)
        c = Entry(window)
        c.focus_set()
        r.grid(row=n+4, columnspan=m)
        label2 = Label(window, text="Column: ")
        label2.grid(row=n+3, columnspan=m)

        c.grid(row=n+2, columnspan=m)
        Label(window, text="Row: ").grid(row=n+1, columnspan=m)
        Label(window, text="Enter move coordinates:").grid(row=n, columnspan=m)


root = Tk()
gui = GUI(root)
root.mainloop()
