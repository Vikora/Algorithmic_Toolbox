# Uses python3
def edit_distance(s, t):
    # ED is a matrix n*m
    n, m = len(s)+1, len(t)+1
    ED = [ [0]*m for _ in range(n) ]

    # fill the 0-row
    for i in range(m):
        ED[0][i] = i
    #fill the 0-column
    for i in range(n):
        ED[i][0] = i

    for i in range(1, n):
        for j in range(1, m):
            diff = 0 if s[i-1] == t[j-1] else 1
            ED[i][j] = min(
                ED[i-1][j]+1,
                ED[i][j-1]+1,
                ED[i-1][j-1]+diff
            )
    return ED[n-1][m-1]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
