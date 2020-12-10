# Week 6. Maximum Amount of Gold
# Uses python3

import sys

def optimal_weight(W, w):
    n = len(w)
    # K - matrix n x W
    # K[i][j] - optimal weight for a knapsack
    # of total weight i uses 1 to j items 
    K = [[None] * (n + 1) for _ in range(W + 1)]
    
    # fill the first row: knapsack of weight zero
    for j in range(n + 1):
        K[0][j] = 0
    #fill the first column: knapsack wit no items
    for i in range(1, W+1):
        K[i][0] = 0

    for i in range(1, W+1): # weight
        for j in range(1, n + 1): # items
            item = w[j-1] # shift
            K[i][j] = K[i][j-1] # the same?
            if item <= i:
                K[i][j] = max(K[i - item][j-1] + item, K[i][j])

    return K[W][n]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
