from interval import interval
from operator import itemgetter
from copy import deepcopy

def addExpense(expensesList, expense):
    """
    this function adds an expense to  the list expenses
    :param expensesList: a list of expenses
    :param expense: a tuple representing the expense
    :return: True if the adding was done successfully, False otherwise
    """
    expensesList.append(expense)
    return True

def insertExpense(expensesList, expense):
    """
    this function inserts an expense to the list expenses
    :param expensesList: a list of expenses
    :param expense: a tuple representing the expense
    :return: True if the inserting was done successfully, False otherwise
    """
    expensesList.append(expense)
    return True

def removeExpense(expensesList, params, type):
    """
    remove an element from the list based on given parameters
    :param expensesList: a list of expenses
    :param params: parameters for removal
    :param type: the type of removal
    :return: True if the removing was done successfully, False otherwise
    """
    if type == 1:
        expensesList[:] = [x for x in expensesList if x[0] != params[0]]
    elif type == 2:
        expensesList[:] = [y for y in expensesList if y[2] != params[0]]
    else:
        expensesList[:] = [z for z in expensesList if z[0] not in interval[params[0], params[2]]]
    return True


def listExpenses(expensesList, params):
    """
    this functions returns all the elements of the expenses list based on the parameters
    :param expensesList: a list of expenses
    :param params: parameters representing what elements to be shown
    :return: returns the list of specified elements
    """
    result = []
    if len(params) == 1:
        for a in expensesList:
            if a[2] == params[0]:
                result.append(a)
    else:
        listcategory = params[0]
        listsign = params[1]
        listvalue = int(params[2])
        if listsign == '<':
            for b in expensesList:
                if b[2] == listcategory and int(b[1]) < listvalue:
                    result.append(b)
        elif listsign == '=':
            for c in expensesList:
                if c[2] == listcategory and int(c[1]) == listvalue:
                    result.append(c)
        else:
            for d in expensesList:
                if d[2] == listcategory and int(d[1]) > listvalue:
                    result.append(d)
    return result


def sumExpense(expensesList, params):
    """
    this function returns the sum of all expenses in a specified category in parameters list
    :param params: category of the expenses
    :param expensesList: the list of expenses
    :return: sum of expenses
    """
    sumE = 0
    for x in expensesList:
        if x[2] == params[0]:
            sumE += int(x[1])
    return sumE


def maxExpense(expensesList):
    """
    this function finds the day with most expenses based on a frequency array of expenses and days
    :param expensesList: the list of expenses consisting of tuples of (day, amount, category)
    :return: the day with most expenses spent
    """
    maxi = -1
    pos = -1
    v = 31*[0]
    for x in expensesList:
        v[int(x[0])-1] += int(x[1])
    for i in range(len(v)):
        if v[i] > maxi:
            maxi = v[i]
            pos = i
    return pos+1


def sortExpenseDay(expensesList):
    """
    this functions sorts daily expenses based on their amount in ascending order
    :param expensesList: the list of expenses consisting of tuples
    :return: a sorted list of expenses
    """
    alist = []
    v = 31 * [0]
    for x in expensesList:
        v[int(x[0]) - 1] += int(x[1])
    alist[:] = [(i+1, v[i]) for i in range(len(v))]
    alist[:] = sorted(alist, key=itemgetter(1))
    alist[:] = [(x, y) for x, y in alist if y != 0]
    return alist


def sortExpenseCategory(expensesList, params):
    """
    this functions sorts daily expenses based on their amount in ascending order
    :param params: the category for which we sort the list
    :param expensesList:the list of expenses consisting of tuples
    :return: a sorted list of expenses
    """
    alist = []
    anewlist = [x for x in expensesList if x[2] == params[0]]
    v = 31 * [0]
    for x in anewlist:
        v[int(x[0]) - 1] += int(x[1])
    alist[:] = [(i + 1, v[i], params[0]) for i in range(len(v))]
    alist[:] = sorted(alist, key=itemgetter(1))
    alist[:] = [(x, y, z) for x, y, z in alist if y != 0]
    return alist


def filterExpense(expensesList, params):
    """
    this function filters the list of expenses based on the category passed in the parameters list
    :param expensesList:the list of expenses consisting of tuples
    :param params: the category to be filtered
    :return: the updated expensesList
    """
    if len(params) == 1:
        expensesList[:] = [x for x in expensesList if x[2] == params[0]]
    else:
        listcategory = params[0]
        listsign = params[1]
        listvalue = int(params[2])
        if listsign == '<':
            expensesList[:] = [x for x in expensesList if x[2] == listcategory and int(x[1]) < listvalue]
        elif listsign == '=':
            expensesList[:] = [x for x in expensesList if x[2] == listcategory and int(x[1]) == listvalue]
        else:
            expensesList[:] = [x for x in expensesList if x[2] == listcategory and int(x[1]) > listvalue]

def undoExpenses(alist, anotherlist):
    """
    the last operation that has modified program data will be reversed.
    :type anotherlist: list
    :param alist: the list which suffers the modifications
    :anotherlist: backup list in which we save the state of the initial list before applying any operation on the list
    :return:
    """
    alist[:] = deepcopy(anotherlist.pop())
