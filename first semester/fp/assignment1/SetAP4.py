# For a given natural number n find the largest natural number m formed with the same digits. E.g. n=3658, m=8653.
def minNumber(n):
    """
        This function returns the largest natural number m formed with the same digits as the inputed natural number n using a frequency array.
        Shorter implementation: print("The largest number formed with the same digits is",int("".join(sorted(str(n),reverse=True)))), not working for 0 digit.
        input: n (natural number).
        output: m (natural number) largest number formed with the digits of n.
    """
    v=[]
    m=""
    string=str(n)
    for i in range(10):
        v.append(0)
    for i in range(len(string)):
        v[int(string[i])]+=1
    for i in range(9,0,-1):
        for j in range(v[i]):
            m+=str(i)
    for i in range(v[0]):
        m+='0'
    return m
n=int(input("Give natural number n "))
print("The largest number formed with the same digits is",int(minNumber(n)))

