from domain import createPoem
from validation import validatePoem
from features import *
from random import random

def addPoemCommand(alist, idP, params):
    """

    :param alist:
    :param params:
    :return:
    """
    id = idP
    lyrics = params[:]
    poem = createPoem(id, lyrics=lyrics)
    if validatePoem(poem):
        addPoem(alist, poem)
        print("poem added")
    else:
        print("invalid poem")


def printHaikus(alist):
    """

    :param alist:
    :param params:
    :return:
    """
    result = haikus(alist)
    print(result)
    if not result:
        print("no haikus")



def generateDadaPoem(alist):
    pass