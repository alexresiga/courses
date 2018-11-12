def power(x, k):
    if k == 0:
        return 1
    if k == 1:
        return x
    aux = power(x, k//2)
    return aux ** 2 if not k & 1 else aux**2*x


print(power(2, 8))