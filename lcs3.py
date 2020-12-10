#Uses python3

import sys

def lcs3(a, b, c):
    # ED is a matrix n*m*k
    n, m, k = len(a)+1, len(b)+1, len(c)+1
    ED = [[[0]*k for _ in range(m)] for _ in range(n)]
    #print(*ED)
    for i in range(1, n):
        for j in range(1, m):
            for l in range(1, k):
                if a[i-1] == b[j-1] and a[i-1] == c[l-1]:
                    diff = 1
                else:
                    diff = 0
                ED[i][j][l] = max(
                    ED[i-1][j-1][l-1] + diff,
                    ED[i-1][j][l],
                    ED[i][j-1][l],
                    ED[i][j][l-1]
                )
    return ED[n-1][m-1][k-1]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))
