primes = [2, 3, 5]
for x in range(7, 5001): # Precompute all primes
    flag = True
    for i in range(2, int(x / 2)):
        if(x % i == 0):
            flag = False
            break
    if(flag):
        primes.append(x)

n = int(input())
memo = [0 for i in range(n + 2)]
arr = [int(x) for x in (input().split(" "))]

sums = [x for x in arr]
sums = [0] + sums

for i in range(1, len(arr) + 1):
    sums[i] += sums[i - 1]

for i in range(2, n + 1): 
    memo[i] = memo[i - 1]
    for j in primes:
        if(j > i):
            continue
        if(i == j):
            memo[i] = max(memo[i], sums[i])
        else:                      # Sum between ith and (i - j)th indices + calculated best till (i - j - 1)
            memo[i] = max(memo[i], sums[i] - sums[i - j] + memo[i - j - 1])

m = 0
for i in memo:
    if(i > m):
        m = i
        
print(m)
