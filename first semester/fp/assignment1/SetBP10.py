# Consider a given natural number n. Determine the product p of all the proper factors of n.
def productOfProperFactors(n):
    """
        This function returns the product of all proper factor of a given natural number n.
        input: n natural number.
        output: a string with the proper factors and the reuslt of their product.
    """
    result=""
    p=1
    d=2
    while d<=n//2:
        if n%d==0:
            p*=d
            result+=str(d)+'*'
        d+=1
    result=result[:-1]
    result+='='+ str(p)
    return result
n=int(input("Give natural number n: "))
print("The product of all proper factors of",n,"is",productOfProperFactors(n))
