# Find the smallest number m from the Fibonacci sequence, defined by f[0]=f[1]=1, f[n]=f[n- 1]+f[n-2], for n>2,
def nextFibNo(number):
    """
        This function returns the smallest number m from the Fibonacci sequence, greater than a given natural number n;
        input: n: given natural number, n>2;
        output: m: the smallest number from the Fibonacci sequence greater than the input, n.
    """
    a = 1
    b = 1
    m = a + b
    # Initializing the Fibonacci sequnce
    while m <= number:
        a = b
        b = m
        m = a + b
    return m


n = int(input("give natural number n "))
if n <= 2:
    print("Invalid input! n must be greater than 2.")
else:
    print("The smallest number from the Fibonacci sequence greater than", n, "is", nextFibNo(n))
