from time import time


class UI:
    def __init__(self, ctrl):
        self._ctrl = ctrl

    @staticmethod
    def menu():
        print("1. BFS")
        print("2. GBFS")
        print("x. Exit")

    def run(self):

        while True:
            UI.menu()
            op = input("Input command: ")
            with open('log.txt', 'a') as f:

                if op == "x":
                    return
                elif op == "1":
                    print("BFS:\n")
                    start = time()
                    print(str(self._ctrl.bfs()))
                    print("Took {} seconds to complete.".format(time() - start))

                    f.write("\nBFS:  {}".format(time()-start))

                elif op == "2":
                    print("GBFS:\n")
                    start = time()
                    print(str(self._ctrl.gbfs()))
                    print("Took {} seconds to complete.".format(time() - start))

                    f.write("\nGBFS: {}".format(time()-start))
                    f.write("\n=====================================\n\n\n")
                else:
                    print("Wrong command")
