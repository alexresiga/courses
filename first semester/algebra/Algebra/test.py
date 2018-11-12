from itertools import *
n = 4
x = ((0, 0, 0, 1), (1, 0, 0, 0), (0, 0, 1, 1), (1, 0, 0, 1))


def subsets(iterable):
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(2, len(s)+1))

'''
sum_vector = []
newlist = []
for i in range(n):
    suma = 0
    for j in range(n - 2):
        newlist.append(x[j])
        suma += x[j][i]
    sum_vector.append(suma % 2)
    if tuple(sum_vector) == x[j+1]:
        print("Da")
        
        
        
        
        
        
        
        
    sum_vector = []
    for i in range(n):
        suma = 0
        for j in range(n - 1):
            suma += x[j][i]
        sum_vector.append(suma % 2)
        if tuple(sum_vector) == x[j+1]:
            return False
'''

for i in range(2, n):
    print("asta e elemntul:" + str(x[i]))
    pred_i = []
    for j in range(i):
        pred_i.append(x[j])
        k = j+1
    for submt in subsets(pred_i):
        sum_vector = []
        for ii in range(n):
            suma = 0
            for jj in range(len(submt)):
                # print(submt[jj][ii])
                suma += submt[jj][ii]
            sum_vector.append(suma % 2)
        print(sum_vector)
        if tuple(sum_vector) == x[i]:
            print("da")

