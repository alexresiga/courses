# For a given natural number n find the minimal natural number m formed with the same digits. E.g. n=3658, m=3568.
def min_number(n):
    """
        This function returns the minimal natural number m formed with the same digits as the input natural number n
        using a frequency array.
        Shorter implementation: print("The minimal number formed with the same digits is",int("".join(sorted(str(n))))),
        not working for 0 digit.
        input: n (natural number).
        output: m (natural number) minimal number formed with the digits of n.
    """
    v = []
    m = ""
    string = str(n)
    for i in range(10):
        v.append(0)
    for i in range(len(string)):
        v[int(string[i])] += 1
    for i in range(1, 10):
        if v[i]:
            m += str(i)
            v[i] -= 1
            break
    for i in range(v[0]):
        m += '0'
    for i in range(1, 10):
        for j in range(v[i]):
            m += str(i)
    return m


n = int(input("Give natural number n "))
print("The minimal number formed with the same digits is", int(min_number(n)))
