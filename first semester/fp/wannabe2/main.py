def mergeSort(alist):
    """

    :param alist:
    :return:
    """
    if len(alist) > 1:
        middle = len(alist)//2
        leftHalf = alist[:middle]
        rightHalf = alist[middle:]

        mergeSort(leftHalf)
        mergeSort(rightHalf)

        merge(leftHalf, rightHalf, alist)


def merge(data1, data2, result):

    i = 0
    j = 0
    aux = []

    while i < len(data1) and j < len(data2):
        if data1[i] < data2[j]:
            aux.append(data1[i])
            i = i + 1
        else:
            aux.append(data2[j])
            j = j + 1

    while i < len(data1):
        aux.append(data1[i])
        i = i + 1

    while j < len(data2):
        aux.append(data2[j])
        j = j + 1

    result.clear()
    result.extend(aux)


lista = [4, 5, 2, 1, 1, 6, 4, 7, 2, 9, 9, 3]
mergeSort(lista)
print(lista)