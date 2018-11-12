from UI import *
from domain import createCircle
from validation import validateCircle
from tests import testInit


def readCommand():
    """
    read the user command
    :return:
    """
    cmd = input(">>>")
    if cmd.find(' ') == -1:
        command = cmd
        params = ""
    else:
        command = cmd[0:cmd.find(' ')]
        params = cmd[cmd.find(' ')+1:]
        params = params.split(' ')
    return command, params


def run():
    repo = []
    testInit(repo)
    while True:

        cmd = readCommand()
        command = cmd[0]
        params = cmd[1]
        commands = {'add': addCircleCommand,
                    'update': updateCircleCommand,
                    'sort': sortCircleCommand,
                    'list': listCircleCommand}
        try:
            if command in commands:
                commands[command](repo, params)
        except ValueError as ve:
            print(str(ve))


run()
