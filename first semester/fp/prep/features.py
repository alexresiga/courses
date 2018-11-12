from operator import itemgetter
from domain import createCircle
from validation import validateCircle
def printCircle(circle):
    result = 'Circle: x = '
    result += str(circle['x']) + ' y = '
    result += str(float(circle['y'])) + ' radius = '
    result += str(circle['r']) + ' colour: '
    result += circle['colour'] + '\n'
    print(result)


def listCircle(alist):
    i = 1
    for x in alist:
        print(str(i)+".", end='')
        printCircle(x)
        i += 1


def addCircle(alist, x, y, r, colour):
    """

    :param alist:
    :param circle:
    :return:
    """
    circle = createCircle(x, y, r, colour)
    validateCircle(circle)
    add(alist, circle)


def add(alist, other):
    alist.append(other)


def sortList(alist):
    tmp = sorted(alist, key=itemgetter("colour"), reverse=True)
    return tmp
