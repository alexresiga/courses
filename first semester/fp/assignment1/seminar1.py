"""
def stringSplosion(n):
    result=""
    for i in range(len(n)):
        result = result + n[:i+1]
    return result
n=input("Give string: ")
print(stringSplosion(n))
"""
a=[1,2,3]
b=a
c=a[:]
a[0]=2
print(b,'\n',c)
