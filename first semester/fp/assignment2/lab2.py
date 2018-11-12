"""
top down programming-using abstract general functions and then get to more concrete functions
feature driven development-code dev based on features, one coder does one feature
test-driven development
problema 7
"""


def showMenu(options):
    print("Welcome :D!")
    print("Options:")
    print("0.Exit")
    for opt in options:
        print(options[opt][1])


def readInt(text):
    while True:
        try:
            x = int(input(text))
            return x
        except ValueError:
            print("Illegal integer value!")


def uiReadList(l):
    n = readInt("input the number of elements")
    for i in range(n):
        l.append(readInt("input the " + str(i + 1) + "th element:"))


def printList(l):
    s = ""
    for x in l:
        s += str(x) + ' '
    print(s)


def uiPrintList(l):
    print("The elements of the list are: ")
    printList(l)


def testIsPrime():
    assert (isPrime(-2) == False)
    assert (isPrime(0) == False)
    assert (isPrime(1) == False)
    assert (isPrime(2) == True)
    assert (isPrime(3) == True)
    assert (isPrime(6) == False)
    assert (isPrime(11) == True)


def isPrime(n):
    """
    a function that tests if the integer n is prime or not
    input data: n- integer
    output data: True if n is prime, False otherwise
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    d = 3
    while d * d <= n:
        if n % d == 0:
            return False
        d += 2
    return True


def primesInList(l):
    result = []
    for x in l:
        if isPrime(x):
            result.append(x)
    return result


def uiPrimeList(l):
    primes = primesInList(l)
    print("the prime numbers in the list are: ")
    printList(primes)


def runTests():
    testIsPrime()


def run():
    l = []
    options = {1: [uiReadList, "1.read list elements"], 2: [uiPrintList, "2.Print the list of integers"],
               3: [uiPrimeList, "3.show primes list"]}  # dictionary pair of unique keys and values
    while True:
        showMenu(options)
        cmd = readInt("Please input command: ")
        if cmd == 0:
            return
        if cmd in options:
            options[cmd][0](l)
        else:
            print("Invalid command!")


runTests()
run()
