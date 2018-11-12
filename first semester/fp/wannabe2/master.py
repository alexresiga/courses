def insert(n, alist):
    left = 0
    r = len(alist)
    while left < r:
        mid = (left+r)//2
        if n < alist[mid]:
            r = mid - 1
        if n > alist[mid]:
            left = mid + 1
        if n == alist[mid]:
            alist.insert(mid+1, n)
            return alist
    print(left, r)
    alist.insert(max(left, r), n)
    return alist


print(insert(1, [1, 2, 3, 5]))
