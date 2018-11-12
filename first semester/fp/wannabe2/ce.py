import itertools
import math

perms = itertools.permutations(range(1, 16))
print(perms)
exit(0)
forbidden = set()
for i, p in enumerate(perms):
    print(i/1.3076744e+12)
    ok = True
    for i in range(1, 16):
        if p[:i] in forbidden:
            ok = False
            break
    if ok:
        continue
    ok = True
    for i in range(1, 15):
        if math.sqrt(p[i] + p[i - 1]) != int(math.sqrt(p[i] + p[i - 1])):
            if perms[:i] not in forbidden:
                forbidden.add(perms[:i])
            ok = False
            break
    if ok:
        print(list(p))