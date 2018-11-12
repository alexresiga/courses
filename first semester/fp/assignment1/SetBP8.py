# Determine the twin prime numbers p1 and p2 immediately larger than the given non-null natural number n. Two prime numbers p and q are called twin if q-p = 2.
def isPrime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True


def twinPrimes(n):
    p1 = n + 1
    while True:
        p2 = p1 + 2
        if isPrime(p1) and isPrime(p2):
            break
        p1 += 1
    return p1, p2


n = int(input("Give non-null number n "))
print("Twin prime numbers are", twinPrimes(n))
