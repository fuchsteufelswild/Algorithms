memo = [0 for x in range(114)]
memo[10] = memo[12] = 1

# Precompute
for i in range(13, 114):
    temp = 1000001
    if(memo[i - 10] > 0):
        temp = min(temp, memo[i - 10] + 1)
    if(memo[i - 12] > 0):
        temp = min(temp, memo[i - 12] + 1)
    if(temp == 1000001):
        memo[i] = 0
    else:
        memo[i] = temp

t = int(input())

for case in range(t):
    n = int(input())
    
    if(memo[n] == 0):
        print(-1)
    else:
        print(memo[n])
    
    
