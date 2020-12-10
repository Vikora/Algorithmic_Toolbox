# Week 6. Partitioning Souvenirs
# Uses python3

import sys
import itertools

def partition3_brute_force(A):
    for c in itertools.product(range(3), repeat=len(A)):
        sums = [None] * 3
        for i in range(3):
            sums[i] = sum(A[k] for k in range(len(A)) if c[k] == i)

        if sums[0] == sums[1] and sums[1] == sums[2]:
            return 1

    return 0

def partition3_recur(T, A, i, x, y, z):
    if x == 0 and y == 0 and z == 0:
        return 1
    
    if A[i] <= x:
        tr = (x - A[i], y, z)
        if tr not in T:
            T[tr] = partition3_recur(T, A, i+1, *tr)

    if A[i] <= y:
        tr = (x, y - A[i], z)
        if tr not in T:
            T[tr] = partition3_recur(T, A, i+1, *tr)

    if A[i] <= z:
        tr = (x, y, z - A[i])
        if tr not in T:
            T[tr] = partition3_recur(T, A, i+1, *tr)

    return 0

def partition3(A):
    total_value = sum(a for a in A)
    if total_value % 3 != 0:
        return 0
    target = total_value // 3


    T = {}
    T[(total_value // 3, total_value // 3, total_value // 3)] = 1
    partition3_recur(T, A, 0, target, target, target)
    
    #for i in T:
    #    print(i, T[i])

    return 1 if (0, 0, 0) in T else 0


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    #print(partition3_brute_force(A))
    print(partition3(A))

