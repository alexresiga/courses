import ui_module as ui
import test_module as test

def run():
    """
    Entry point in the program
    """
    expensesList = []
    test.testInit(expensesList)
    undoList = []
    while True:
        cmd = ui.readCommand()
        command = cmd[0]
        params = cmd[1]
        commands = {'add': ui.addExpenseCommand,
                    'insert': ui.insertExpenseCommand,
                    'remove': ui.removeExpenseCommand,
                    'filter': ui.filterExpenseCommand,
                    }
        if command in commands:
            commands[command](expensesList, params, undoList)
        elif command == 'list':
            ui.listExpenseCommand(expensesList, params)
        elif command == 'sum':
            ui.sumExpenseCommand(expensesList, params)
        elif command == 'max':
            ui.maxExpenseCommand(expensesList, params)
        elif command == 'sort':
            ui.sortExpenseCommand(expensesList, params)
        elif command == 'undo':
            ui.undoExpenseCommand(expensesList, undoList)
        elif command == 'help':
            ui.helpCommand()
        elif command == 'exit':
            print("You closed the application.")
            exit(0)
        else:
            print("invalid command. Type 'help' in order to see available commands.")


test.run_test()
run()
