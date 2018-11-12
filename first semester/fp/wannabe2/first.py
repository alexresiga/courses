def sumOfEven(alist):

    if type(alist) != list:
        raise TypeError("invalid type")
    suma = 0
    cnt = 0
    for x in alist:
        if not x & 1:
            suma += x
            cnt += 1
    if not cnt:
        raise ValueError("zero")
    return suma


a = [1, 2, 3, 4, 0, 5, 6, 6, 3, 2]
b = (0, 1, 2)
try:
    sumOfEven([1, 3])
    sumOfEven(b)
    assert False
except TypeError:
    assert True
except ValueError:
    assert True

assert sumOfEven(a) == 20, sumOfEven(a)


for i in range(len(a)-1):
    if not a[i] ^ a[i+1]:
        print("egale")