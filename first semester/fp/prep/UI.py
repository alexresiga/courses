from domain import createCircle
from validation import *
from features import *


def addCircleCommand(alist, params):
    if len(params) != 4:
        raise ValueError("invalid params list")
    else:
        x = params[0]
        y = params[1]
        r = params[2]
        colour = str(params[3])
        addCircle(alist, x, y, r, colour)


def listCircleCommand(alist, params):
    if not params:
        listCircle(alist)


def updateCircleCommand(alist, params):
    pass


def sortCircleCommand(alist, params):
    if not params:
        listCircle(sortList(alist))