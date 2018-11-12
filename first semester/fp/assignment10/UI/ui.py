from domain.Game import Game
# import time


class UI:
    def __init__(self):
        ok = True
        while ok:
            try:
                n = int(input("enter number of rows: "))
                m = int(input("enter number of columns: "))
                if n <= 0 or m <= 0:
                    raise ValueError
                self.game = Game(n, m)
                self.showBoard()
                ok = False
            except ValueError:
                print("Board sizes must be positive integers!")

    def parse_move(self):
        y = int(input("enter row: "))
        x = int(input("enter column: "))
        self.game.move_player(x, y)

    def showBoard(self):
        self.game.printBoard()

    def show_stats(self):
        player_stat = self.game.get_stats()[0]
        comp_stat = self.game.get_stats()[1]
        feel = ':(' if player_stat <= comp_stat else ':)'
        print('You: ' + player_stat + '\nComputer: ' + comp_stat + '\n' + feel)

    def start_game(self):
        try:
            while True:
                while True:
                    try:
                        self.parse_move()
                        if self.game.game_won() == 0:
                            print('You won!')
                            self.game.store_stats('player_stats.txt')
                            self.show_stats()
                            ans = input("Do you want a rematch? [y/n]")
                            if ans not in ['y', 'n']:
                                raise ValueError("invalid answer")
                            if ans == 'y':
                                ui = UI()
                                ui.start_game()
                            else:
                                print('Game over!')
                                exit(0)
                        break
                    except Exception as exc:
                        print(str(exc))

                self.game.move_computer()
                if self.game.game_won() == 0:
                    print('You lost!')
                    self.game.store_stats('comp_stats.txt')
                    self.show_stats()
                    ans = input("Do you want a rematch? [y/n]")
                    if ans not in ['y', 'n']:
                        raise ValueError("invalid answer")
                    if ans == 'y':
                        ui = UI()
                        ui.start_game()
                    else:
                        print('Game finished!')
                        exit(0)
        except Exception as exc:
            print(str(exc))
