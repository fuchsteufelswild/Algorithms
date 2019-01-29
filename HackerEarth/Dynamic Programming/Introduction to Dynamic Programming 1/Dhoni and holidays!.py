n = int(input())
arr = [int(x) for x in input().split(' ') if x != '']

memo = [[0, 0, 0 ]for x in range(n)]

if(arr[0] == 3):
    memo[0] = [0, 0, 1]
elif(arr[0] == 2):
    memo[0] = [0, 10000000, 1]
elif(arr[0] == 1):
    memo[0] = [10000000, 0, 1]
else:
    memo[0] = [10000000, 10000000, 1]

# [n = day][0, 1, 2] 0 = driving, 1 = going to academy, 2 = relaxing
# 100000000 means cannot perform this activity on that day
for i in range(1, n):
    if(arr[i] == 0):
        memo[i][0] = 10000000
        memo[i][1] = 10000000
        memo[i][2] = min(min(memo[i - 1][0], memo[i - 1][1]), memo[i - 1][2]) + 1
    
    elif(arr[i] == 1):
        memo[i][0] = 10000000
        memo[i][1] = min(memo[i - 1][0], memo[i - 1][2])
        memo[i][2] = min(min(memo[i - 1][1], memo[i - 1][0]), memo[i - 1][2]) + 1
        
    elif(arr[i] == 2):
        memo[i][1] = 10000000
        memo[i][0] = min(memo[i - 1][1], memo[i - 1][2])
        memo[i][2] = min(min(memo[i - 1][0], memo[i - 1][1]), memo[i - 1][2]) + 1
    
    else:
        memo[i][0] = min(memo[i - 1][1], memo[i - 1][2])
        memo[i][1] = min(memo[i - 1][0], memo[i - 1][2])
        memo[i][2] = min(min(memo[i - 1][0], memo[i - 1][1]), memo[i - 1][2]) + 1
        
print(min(min(memo[n - 1][0], memo[n - 1][1]), memo[n - 1][2]))
