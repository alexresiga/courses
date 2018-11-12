from random import shuffle
from main import mergeSort


def binary_search_recursive(alist, key, left, right):
    if right < left:
        return None
    middle = (left+right)//2
    if key < alist[middle]:
        return binary_search_recursive(alist, key, left, middle-1)
    if key > alist[middle]:
        return binary_search_recursive(alist, key, middle+1, right)
    if alist[middle] == key:
        return middle


def binary_search_iterative(alist, key):
    left = 0
    right = len(alist)

    while left <= right:
        middle = (left+right)//2
        if key < alist[middle]:
            right = middle - 1
        if key > alist[middle]:
            left = middle + 1
        if alist[middle] == key:
            return middle

    return None


a = [x for x in range(23)]
shuffle(a)


assert binary_search_recursive(a, 12, 0, len(a)) == binary_search_iterative(a, 12)


n = input()
v = [0 for i in range(int(n))]
for i in range(int(n)):
    v[i] = int(input())

mergeSort(v)

for i in v:
    print(i, end=", ")


def seq(alist, key):
    for i in range(len(alist)):
        if alist[i] == key:
            return i
    return -1
