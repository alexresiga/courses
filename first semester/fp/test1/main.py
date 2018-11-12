"""
managing poems
poem
-lyrics = ["...", "...."]
addPoem(id, "v1#v2#")
ultimele 3 caractere de la fiecare vers sa fie comune
poezie invalida

printHaikus 5litere 7litere: lista de poezii

generateDadaPoem()
"""
import UI
import test


def readCommand():
    """
    function for handling user input
    :return:
    """
    cmd = input(">>>")
    if cmd.find(' ') == -1:
        command = cmd
        id = None
        params = ""
    else:
        command = cmd[0:cmd.find(" ")]
        id = cmd[cmd.find(" ")+1:cmd.find(" ")+2]
        params = cmd[cmd.find(" ")+3:]
        params = params.split("#")
    return command, id, params


def run():
    """
    entry point in the program
    :return:
    """
    poemlist = []
    test.testInit(poemlist)
    while True:
        try:
            cmd = readCommand()
            command = cmd[0]
            idP = cmd[1]
            params = cmd[2]
            if command == "add":
                UI.addPoemCommand(poemlist, idP, params)
            elif command == "haikus":
                UI.printHaikus(poemlist)
            elif command == "dada":
                UI.generateDadaPoem(poemlist)
            elif command == "print":
                print(poemlist)
            else:
                print("invalid command")
        except ValueError as ve:
            print(str(ve))


run()
