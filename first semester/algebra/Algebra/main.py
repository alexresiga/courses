from itertools import *


def subsets(iterable):
    """
    returns the subsets of predecessors of the k-th vector in order to check for linearly independence
    :param iterable:
    :return:
    """
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(2, len(s)+1))


def number_of_bases(n):
    """
    returns number of bases based on mathematical formula
    used for verification for real counter of generated bases
    :param n:
    :return:
    """
    counter = 1
    for i in range(n):
        p = 2**n - 2**i
        counter = counter * p
    return counter


def is_basis(x):
    """
    check if n vectors can create basis
    first if checks for any vector to be different from the 0 vector of the n-th dimension
    second if check to see if all vectors are distinct
    third structure checks if any of the vectors are linear combinations of any other vectors
    """
    verif = tuple([0] * n)
    if verif in x:
        return False
    if len(set(x)) != len(x):
        return False
    for i in range(2, n):
        pred_i = []
        for j in range(i):
            pred_i.append(x[j])
        for submt in subsets(pred_i):
            sum_vector = []
            for ii in range(n):
                suma = 0
                for jj in range(len(submt)):
                    suma += submt[jj][ii]
                sum_vector.append(suma % 2)
            if tuple(sum_vector) == x[i]:
                return False
    return True


def create_basis(alist, m):
    return permutations(alist, m)


try:
    n = int(input("Enter n natural number different from 0: "))
    if n <= 0:
        raise ValueError
    
    vector_list = []
    for i in range(2**n):
        vector_list.append(tuple(map(int, str(bin(i))[2:].zfill(n))))
    print(vector_list)
    c = 0
    print(number_of_bases(n))
    with open("n=1.txt", "w") as f:
        f.write("Expected number of bases given by formula: " + str(number_of_bases(n)) + '\n')
        for x in permutations(vector_list, n):
            if is_basis(x):
                f.write(str(x) + '\n')
                print(str(x))
                c += 1
        f.write("Counter of bases printed by the program: " + str(c))

except ValueError:
    print("Invalid integer value")
