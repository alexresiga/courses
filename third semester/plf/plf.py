import copy
from lista import *

def find(elem, alist):
    if not alist.head:
        return 0
    if elem == alist.head.info:
        ceva = copy.deepcopy(alist.head.info)
        tmp = copy.deepcopy(alist)
        tmp.head = alist.head.next
        return 1+find(elem, tmp)
    else:
        ceva = copy.deepcopy(alist.head.info)
        tmp = copy.deepcopy(alist)
        tmp.head = alist.head.next
        return find(elem, tmp)


def makeSet(alist, tmp):
    if not tmp.head:
        return None
    if find(tmp.head.info, alist) == 1:        
        tmp.head = tmp.head.next
        return makeSet(alist, tmp)
    else:
        remove(alist, tmp.head.info)
        tmp.head = tmp.head.next
        return makeSet(alist, tmp)


def makeUnion(alist, atmp, blist, btmp):
    if not atmp.head and not btmp.head:
        return None
    if atmp.head is not None:
        if find(atmp.head.info, alist) + find(atmp.head.info, blist) == 1:
            atmp.head = atmp.head.next
            return makeUnion(alist, atmp, blist, btmp)
        else:
            remove(alist, atmp.head.info)
            atmp.head = atmp.head.next
            return makeUnion(alist, atmp, blist, btmp)
    elif btmp.head is not None:
        if find(btmp.head.info, alist) + find(btmp.head.info, blist) == 1:
            btmp.head = btmp.head.next
            return makeUnion(alist, atmp, blist, btmp)
        else:
            remove(blist, btmp.head.info)
            btmp.head = btmp.head.next
            return makeUnion(alist, atmp, blist, btmp)


def main():
    newlist = createList()
    makeSet(newlist)
    printList(newlist)
    print()
    alist = createList()
    atmp = copy.deepcopy(alist)
    blist = createList()
    btmp = copy.deepcopy(blist)
    makeUnion(alist, atmp, blist, btmp)
    printList(alist)
    printList(blist)
    print()

main()