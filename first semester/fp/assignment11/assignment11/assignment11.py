def backtracking(n, m):
    x = [0]
    possible = False
    while len(x) > 0:
        ok = False
        while not ok and x[-1] < n:
            x[-1] += 1
            ok = consistent(x, m)
        if ok:
            if solution(x,n):
                solutionFound(x)
                possible = True
            else:
                x.append(0)
        else:
            x = x[:-1]
    if not possible:
        print("Impossible combination!")

def consistent(x, m):
    for i in range(len(x)-1):
        if x[i] == x[-1]:
            return False
    for i in range(len(x)-1):
        if abs(x[i]-x[i+1]) < m:
            return False
    return True

def solution(x, n):
    return len(x) == n

def solutionFound(x):
    print(x)

def back(x, n, m):
    x.append(1)
    for i in range(1,n+1):
        x[-1] = i
        if consistent(x, m):
            if solution(x, n):
                solutionFound(x)
                possible = True
            else:
                back(x[:], n, m)


n = int(input("Enter n: "))

m = int(input("Enter m: "))
v = []
back(v,n,m)