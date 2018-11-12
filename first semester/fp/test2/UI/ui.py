class UI:
    def __init__(self, repo, controller):
        self.__repo = repo
        self.__controller = controller

    @staticmethod
    def printMenu():
        result = ''
        result += '1. Forge new weapon\n2. Melt two weapons\n3. Defeating weapons\n'
        return result

    def start(self):
        print(UI.printMenu())
        while True:
            try:
                user = int(input("Choose your option: "))
                if user not in [1, 2, 3]:
                    raise ValueError("Please enter available command")
                if user == 1:
                    ident = int(input("Enter id: "))
                    weapon_type = input("Enter weapon type: ")
                    material = input("Enter material: ")
                    quantity = input("Enter quantity: ")
                    self.__controller.forge(ident, weapon_type, material, quantity)
                    print(self.__repo)

                if user == 2:
                    ident1 = int(input("Enter id1: "))
                    ident2 = int(input("Enter id2: "))
                    weapon_type = input("Enter weapon type: ")
                    self.__controller.melt(ident1, ident2, weapon_type)
                    print(self.__repo)

                if user == 3:
                    for x in self.__repo.getAll():
                        print(x)
                    ident = int(input("Enter id: "))
                    for x in self.__controller.defeatingWeapons(ident):
                        print(x)

            except Exception as exc:
                print(str(exc))
