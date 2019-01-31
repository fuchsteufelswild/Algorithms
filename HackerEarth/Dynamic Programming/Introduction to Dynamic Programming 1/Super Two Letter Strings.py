N = 10001
P = 11
memo = [[1 for y in range(N)]for x in range(P)] # First row will be full of ones

# Precalculation
for i in range(2, P):
    for k in range(i - 1): # Copy (p - 1)th row's first (i - 1) columns 
        memo[i][k] = memo[i - 1][k]
    memo[i][i - 1] = memo[i - 1][i - 1] + 1
    for j in range(i, N):  # There is a pattern, each column is equal to the sum of previous 
        temp = 0           # p columns of the same row
        for k in range(1, i + 1):
            temp += memo[i][j - k]
            temp %= 1000000007
        memo[i][j] = temp
        
t = int(input())

for case in range(t):
    n, p = [int(x) for x in input().split(" ")]
    
    print(memo[p][n - 1])
