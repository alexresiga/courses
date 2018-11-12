def palindrome(n):
    ogl=0
    while n!=0:
        cifra = n%10
        ogl = ogl*10 + cifra
        n=n//10
    return ogl
n=int(input("give natural number n "))
print("The palindrome of",n,"is",palindrome(n))
