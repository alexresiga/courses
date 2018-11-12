class Node:
    def __init__(self, e):
        self.info = e
        self.next = None
    
class Mylist:
    def __init__(self):
        self.head = None
        

'''
crearea unei liste din valori citite pana la 0
'''
def createList():
    alist = Mylist()
    alist.head = createList_rec()
    return alist

def createList_rec():
    x = int(input("x="))
    if x == 0:
        return None
    else:
        node = Node(x)
        node.next = createList_rec()
        return node
    
'''
tiparirea elementelor unei liste
'''
def printList(alist):
    printList_rec(alist.head)
    
    
def printList_rec(node):
    if node != None:
        print(node.info, end=' ')
        printList_rec(node.next)

def remove_recursive(alist, cur, elem):
    if cur == None:
        return None
    elif cur.info == elem:
        return cur.next # removes only the first instance of data
    else:
        cur.next = remove_recursive(alist, cur.next, elem)
        return cur

def remove(alist, data):
    alist.head = remove_recursive(alist, alist.head, data)

