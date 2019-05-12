import os


def set_difference(set_a, set_b):
    a = set(set_a)
    b = set(set_b)
    c = a & b
    return len(list(a - c))


def check_partition(set_a, set_b, set_c):
    a = set(set_a)
    b = set(set_b)
    c = set(set_c)
    return a | b == c and a & b == set()


def partition_distance(set_a, set_b, set_c):
    a = set(set_a)
    b = set(set_b)
    c = set(set_c)

    return max(len((a | b) - c), len(c - (a | b)))


def num_of_subsets_included(set_a, set_b, subs_lst):
    a = set(set_a)
    b = set(set_b)
    num_ap = 0
    for subset in subs_lst:
        c = set(subset)

        if c <= a or c <= b:
            num_ap += 1

    return num_ap


def random_num():
    return int.from_bytes(os.urandom(8), byteorder='big') / ((1 << 64) - 1)
