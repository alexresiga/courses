x = [1, 2, 3]
x1 = [1] + x[1:]
x2 = x[:2] + [x[-1]]
print(x1, id(x1) == id(x))
print(x2, id(x2) == id(x))
print(id(x1) == id(x2))
