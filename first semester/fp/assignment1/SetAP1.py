def isPrime(n):
    if n<2:
        return False
    if n==2:
        return True
    if n>2 and n%2==0:
        return False
    i=3
    while(i*i<=n):
        if n%i==0:
            return False
    return True
def nextPrime(n):
    a=n+1
    while True:
        if isPrime(a):
            break
        a+=1
    return a
n=int(input("Give integer n "))
print("The next prime number after ",n, " is ",nextPrime(n))
    
