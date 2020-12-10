#Uses python3

import sys

def lcs2(a, b):
    # ED is a matrix n*m
    n, m = len(a)+1, len(b)+1
    ED = [[0]*m for _ in range(n)]
    for i in range(1, n):
        for j in range(1, m):
            diff = 1 if a[i-1] == b[j-1] else 0
            ED[i][j] = max(
                ED[i-1][j-1] + diff,
                ED[i-1][j],
                ED[i][j-1]
            )
    #print(*ED)
    i, j = n-1, m-1
    L = []
    # start from right bottom corner
    while i>0 and j>0:
        l = ED[i][j]
        if a[i-1] == b[j-1]:
            L.insert(0, a[i-1])
            i, j = i-1, j-1
        elif ED[i][j-1] >= ED[i-1][j]:
            j -= 1
        else:
            i -= 1
    #print(*L)
    return ED[n-1][m-1]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))

    n = data[0]
    data = data[1:]
    a = data[:n]

    data = data[n:]
    m = data[0]
    data = data[1:]
    b = data[:m]

    print(lcs2(a, b))
