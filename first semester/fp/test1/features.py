from random import randint
from domain import createPoem
from validation import validatePoem
def addPoem(alist, poem):
    """
    add poem to poems list
    :param alist:
    :param poem:
    :return:
    """
    return alist.append(poem)


def haikus(alist):
    """
    return the poems who obey haikus rules
    :param alist:
    :return:
    """
    result = []
    for poem in alist:
        if len(poem["lyrics"]) == 1:
            poem["lyrics"] = poem["lyrics"][0].split(" ")
            for i in range(len(poem["lyrics"])-1):
                if len(poem["lyrics"][i]) == 5 and len(poem["lyrics"][i+1]) == 7:
                    result.append(poem["lyrics"])
    return result[-1:]


def dada(alist):
    """
    generate random poem
    :param alist:
    :return:
    """
    lyrics = ''
    lyrics += alist[randint(0, len(alist))]["lyrics"][0]
    lyrics += alist[randint(0, len(alist))]["lyrics"]

    poem = createPoem(randint(10, 20), lyrics)
    validatePoem(poem)
    addPoem(alist, poem)
