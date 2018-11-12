import datetime
import features_module as feature
from interval import interval
categoryList = ['housekeeping', 'food', 'transport', 'clothing', 'internet', 'others']

def readCommand():
    """
    reading the user command
    """
    cmd = input('>>> ')
    if cmd.find(' ') == -1:
        command = cmd
        params = ""
    else:
        command = cmd[0:cmd.find(' ')]
        params = cmd[cmd.find(' ')+1:]
        params = params.split(' ')
    return command, params


def readInt(var):
    """
    check if given value is integer
    :param var: given value
    :return: returns the value if integer, False otherwise
    """
    try:
        n = int(var)
        return n
    except ValueError:
        return False


def listToString(alist):
    """
    prints a list in the form of a string
    """
    r = ""
    if not alist:
        print("No expenses.")
    else:
        for x in alist:
            r += "On day " + str(x[0]) + " you spent " + str(x[1]) + "$ on " + x[2] + '.\n'
    print(r)


def addExpenseCommand(expensesList, params, undoList):
    """
    based on the parameters input, handles the add command
    """
    if len(params) != 2:
        print("Invalid parameters list")
    else:
        if not readInt(params[0]):
            print("Please input positive integer value")
            return
        else:
            sum = int(params[0])
        day = datetime.datetime.now().day
        category = params[1]
        if sum < 0 or len(category) == 0 or category not in categoryList:
            print("Invalid parameters")
        else:
            expense = (day, sum, category)
            undoList.append(expensesList[:])
            if not feature.addExpense(expensesList, expense):
                print("Expense was not added.")
            else:
                print("Expense added.")


def insertExpenseCommand(expensesList, params, undoList):
    """
        based on the parameters input, handles the insert command
        """
    if len(params) != 3:
        print("Invalid parameters list")
    else:
        if readInt(params[0]) == False or readInt(params[1]) == False:
            print("Please input positive integer value")
            return
        else:
            day = int(params[0])
            sum = int(params[1])
        category = params[2]
        if day < 1 or day > 31 or sum < 0 or len(category) == 0 or category not in categoryList:
            print("Invalid parameters")
        else:
            expense = (day, sum, category)
            undoList.append(expensesList[:])
            if not feature.insertExpense(expensesList, expense):
                print("Expense was not added.")
            else:
                print("Expense inserted.")

def removeExpenseCommand(expensesList, params, undoList):
    """
        based on the parameters input, handles the remove command
        """
    if len(params) == 1:
        if readInt(params[0]):
            if 0 < int(params[0]) < 32:
                undoList.append(expensesList[:])
                # passing the type of removal by last parameter
                if not feature.removeExpense(expensesList, params, 1):
                    print("Expenses not removed.")
                else:
                    print("Expenses removed.")
            else:
                print("Invalid integer value")
        elif params[0] not in categoryList:
            print("Invalid parameter")
        else:
            undoList.append(expensesList[:])
            if not feature.removeExpense(expensesList, params, 2):
                print("Expenses not removed.")
            else:
                print("Expenses removed.")
    elif len(params) == 3:
        if not readInt(params[0]) or readInt(params[0]) not in interval[1, 31] or params[1] != 'to' or not readInt(params[2]) or readInt(params[2]) not in interval[1, 31] or readInt(params[0]) > readInt(params[2]):
            print("Invalid parameters")
        else:
            undoList.append(expensesList[:])
            if not feature.removeExpense(expensesList, params, 3):
                print("Expenses not removed.")
            else:
                print("Expenses removed.")
    else:
        print("Invalid parameters")


def listExpenseCommand(expensesList, params):
    """
    based on the parameters input, handles the list command
    """
    if params == "":
        # if there are no parameters we print the entire list of expenses
        listToString(expensesList)
    elif len(params) == 1:
        if params[0] not in categoryList:
            print("Invalid parameter")
        else:
            listToString(feature.listExpenses(expensesList, params))
    elif len(params) == 3:
        if params[0] not in categoryList or params[1] not in ['<', '=', '>'] or int(params[2]) < 0:
            print("Invalid parameters")
        else:
            listToString(feature.listExpenses(expensesList, params))
    else:
        print("Invalid Command")


def sumExpenseCommand(expensesList, params):
    if len(params) != 1:
        print("Invalid parameters")
    elif params[0] not in categoryList:
        print("Invalid category type")
    else:
        print("You spent " + str(feature.sumExpense(expensesList, params)) + " on " + str(params[0]))


def maxExpenseCommand(expensesList, params):
    if len(params) != 1:
        print("Invalid parameters")
    elif params[0] != "day":
        print("Invalid parameter")
    else:
        print("The day with most expenses this month is: " + str(feature.maxExpense(expensesList)))


def filterExpenseCommand(expensesList, params, undoList):
    if len(params) == 1:
        if params[0] not in categoryList:
            print("Invalid parameter")
        else:
            undoList.append(expensesList[:])
            try:
                feature.filterExpense(expensesList, params)
                print("Expenses filtered")
            except ValueError:
                print("Expenses not filtered")
    elif len(params) == 3:
        if params[0] not in categoryList or params[1] not in ["<", "=", ">"] or int(params[2]) < 0:
            print("Invalid parameters")
        else:
            undoList.append(expensesList[:])
            try:
                feature.filterExpense(expensesList, params)
                print("Expenses filtered")
            except ValueError:
                print("Expenses not filtered")


def printSortedDays(alist):
    res = ""
    for x, y in alist:
        res += "On day " + str(x) + " you spent " + str(y) + '$\n'
    print(res)


def sortExpenseCommand(expensesList, params):
    """

    :param expensesList:
    :type params: list
    """
    if len(params) != 1:
        print("Invalid parameters")
    elif params[0] == "day":
        printSortedDays(feature.sortExpenseDay(expensesList))
    elif params[0] in categoryList:
        listToString(feature.sortExpenseCategory(expensesList, params))
    else:
        print("Invalid parameter")

def undoExpenseCommand(expensesList, undoList):
    """

    :param undoList:
    :param expensesList:
    :return:
    """
    try:
        feature.undoExpenses(expensesList, undoList)
        print("Last command was reverted")
    except IndexError:
        print("There are no commands left to undo")


def helpCommand():
    print("Valid commands:")
    print("\t add <sum> <category>")
    print("\t insert <day> <sum> <category>")
    print("\t remove <day>")
    print("\t remove <category>")
    print("\t remove <start day> to <end day>")
    print("\t list")
    print("\t list <category>")
    print("\t list <category> [ < | = | > ] <value>")
    print("\t filter <category>")
    print("\t filter <category> [ < | = | > ] <value>")
    print("\t undo")
    print("\t help")
    print("\t exit")
