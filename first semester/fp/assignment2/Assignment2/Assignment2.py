def readValidation(text):
    while True:
        try:
            x = int(input(text))
            return x
        except ValueError:
            print("You can only input integer values.")


def uiReadList(list):
    n = readValidation("Input the number of elements: ")
    for i in range(n):
        x = readValidation("Element " + str(i + 1) + " is ")
        list.append(x)
    return list


def showMenu(options):
    print("----------------------------------------------")
    print("Welcome to this menu based application.\n")
    print("Options available:")
    print("0. Exit the application.")
    for opt in options:
        print(options[opt][0])


def printList(list):
    result = ""
    for x in list:
        result += str(x) + ' '
    print(result)


def uiPrintList(list):
    print("The list of elements is: ")
    printList(list)


def test_prime():
    assert (isPrime(0) == False)
    assert (isPrime(1) == False)
    assert (isPrime(2) == True)
    assert (isPrime(6) == False)
    assert (isPrime(9) == False)
    assert (isPrime(11) == True)
    assert (isPrime(-1) == False)


def isPrime(n):
    """
    This function checks whether or not an integer is a prime.
    input: natural number n.
    output: True if n is prime, False otherwise.
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0 and n > 2:
        return False
    d = 3
    while d * d <= n:
        if n % d == 0:
            return False
        d += 2
    return True


def test_primeAbsDif():
    assert (primeAbsDif(1, 3) == True)
    assert (primeAbsDif(1, 4) == True)
    assert (primeAbsDif(-1, 3) == True)
    assert (primeAbsDif(-1, -3) == True)
    assert (primeAbsDif(0, 0) == False)
    assert (primeAbsDif(3, 1) == False)
    assert (primeAbsDif(10, 21) == True)


def primeAbsDif(x, y):
    """
    This function checks if the difference between the absolute value of two numbers is prime
    input: param x: integer
    input: param y: integer
    output: True if the difference is prime, False otherwise.
    """
    dif = abs(y) - abs(x)
    return isPrime(dif)


def test_maxSeq():
    assert (maxSeq([1, 3, 10, 1, 3]) == [1, 3, 10])
    assert (maxSeq([1, 3, 10, 1, 3, 10, 21]) == [1, 3, 10, 21])
    assert (maxSeq([1, 3, 101, 1, 3]) == [1, 3])
    assert (maxSeq([1, 30, 10, 1, 3]) == [1, 30])
    assert (maxSeq([1, 3, 10, 21, 37]) == [1, 3, 10, 21])


def test_longSeq():
    assert ([3, 3, 3, 3] == longSeq([1, 2, 3, 3, 3, 3, 4, 4]))
    assert ([1] == longSeq([1, 2, 3, 13, 23, 33, 24, 14]))
    assert ([3, 3, 3, 3] == longSeq([3, 3, 3, 3]))
    assert ([4, 4] == longSeq([1, 2, 3, 4, 4,]))


def longSeq(list):
    """
    the function returns the longest subsequence of identical numbers
    input: param list: a list of integers
    output: return the longest subsequence
    """
    cnt = 1
    max = 0
    final_position = -1
    for i in range(len(list)-1):
        x = list[i]
        y = list[i+1]
        if x == y:
            cnt += 1
            if cnt > max:
                max = cnt
                final_position = i + 1
        else:
            cnt = 1
    if final_position == -1:
        return list[final_position + 1 - max: final_position + 2]
    else:
        return list[final_position + 1 - max: final_position + 1]


def uiPrintSeqq(list):
    print("the longest list of identical elements is:")
    printList(longSeq(list))


def maxSeq(list):
    """
    This function returns the longest subsequence of numbers in the list whose difference between the absolute
    value of consecutive numbers is a prime number
    input: param list: a list of integers
    output: return the longest subsequence with the aforementioned property
    """
    cnt = 1
    max = -1
    final_position = -1
    for i in range(len(list) - 1):
        x = list[i]
        y = list[i + 1]
        if primeAbsDif(x, y):
            cnt += 1
            if cnt > max:
                max = cnt
                final_position = i + 1
        else:
            cnt = 1
    return list[final_position + 1 - max: final_position + 1]


def uiPrintSeq(list):
    print("The longest sequence where the difference between absolute value of consecutive numbers is a prime number:")
    longestSeq = maxSeq(list)
    if longestSeq:
        printList(longestSeq)
    else:
        print("There is no sequence that meets the requirements.")


def run_tests():
    test_prime()
    test_primeAbsDif()
    test_maxSeq()
    test_longSeq()


def run():
    elementsList = [1, 2, 3, 13, 23, 33, 33, 24, 14]
    options = {1: ["1. Read a list of integers.", uiReadList],
               2: ["2. Print the list of numbers.", uiPrintList],
               3: ["3. Print to console the longest sequence where the difference between absolute value of consecutive numbers is a prime number.", uiPrintSeq],
               4: ["4. Print to console the longest sequence made of identical numbers.", uiPrintSeqq]}
    while True:
        showMenu(options)
        userInput = readValidation("Choose option: ")
        if userInput == 0:
            print("~You closed the application.~")
            exit(0)
        if userInput in options:
            options[userInput][1](elementsList)
        else:
            print("Invalid input.")


run_tests()
run()