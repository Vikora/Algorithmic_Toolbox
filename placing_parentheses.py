# Maximum Value of an Arithmetic Expression
# Uses python3

def evalt(a, b, op):
    a, b = int(a), int(b)
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    dt_size = len(dataset)//2 + 1
    X = [[None] * dt_size for _ in range(dt_size)]
    N = [[None] * dt_size for _ in range(dt_size)]
    for i in range(dt_size):
        X[i][i] = dataset[2*i]
        N[i][i] = dataset[2*i]
    for d in range(1, dt_size): # distance 
        for j in range(d, dt_size):
            i = j-d # i < j
            for k in range(i, j):
                XX = evalt(X[i][k], X[k+1][j], dataset[2*k+1])
                XN = evalt(X[i][k], N[k+1][j], dataset[2*k+1])
                NX = evalt(N[i][k], X[k+1][j], dataset[2*k+1])
                NN = evalt(N[i][k], N[k+1][j], dataset[2*k+1])
                
                if X[i][j] != None:
                    X[i][j] = max(X[i][j], XX, XN, NX, NN)
                else:
                    X[i][j] = max(XX, XN, NX, NN)

                if N[i][j] != None:
                    N[i][j] = min(N[i][j], XX, XN, NX, NN)
                else:
                    N[i][j] = min(XX, XN, NX, NN)

    #print(X)
    #print(N)
    return X[0][dt_size-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))
