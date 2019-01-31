t = int(input())

for case in range(t):
    n = int(input())
    arr = [int(x) for x in input().split(" ") if x != '']
    
    memo = [[0, 0] for x in range(n)] # Store previous max points memo[0..n][0..1] 
    memo[0][1] = arr[0]               # 0 for not taken 1 for taken
    
    for i in range(1, n):
        memo[i][0] = max(memo[i - 1][0], memo[i - 1][1])
        memo[i][1] = memo[i - 1][0] + arr[i]
    
    print("Case {}: {}".format(case + 1,max(memo[n - 1][0], memo[n - 1][1])))
    
    
