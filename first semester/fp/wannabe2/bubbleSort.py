from random import shuffle


def bubble_sort(alist):
    """
    useless
    :param alist: a list of numbers
    :return: after a very long time a sorted list
    """
    n = len(alist) - 1
    done = False
    while not done:
        done = True
        for i in range(n):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
                done = False
        n -= 1

    return alist


a = [x for x in range(35)]
shuffle(a)
print(bubble_sort(a))


def insertion_sort(alist):
    """
    idk why we don't just use two fucking nested for's
    :param alist:
    :return:
    """
    for i in range(1, len(alist)):
        val = alist[i]
        j = i - 1
        while j >= 0 and alist[j] > val:
            alist[j+1] = alist[j]
            j = j - 1
        alist[j+1] = val

    return alist


assert bubble_sort(a) == insertion_sort(a)


def bubble(alist):

    n = len(alist)
    done = False
    while not done:
        done = True
        for i in range(n):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
                done = False
        n -= 1


def insert(alist):
    for i in range(1, len(alist)):
        val = alist[i]
        j = i - 1
        while j >= 0 and alist[j] > val:
            alist[j+1] = alist[j]
            j = j-1
        alist[j+1] = val
