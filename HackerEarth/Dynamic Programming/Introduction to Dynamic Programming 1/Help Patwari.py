k = int(input())

memo = [0 for x in range(k + 1)]
memo[1] = 1
memo[0] = 1
# Same pattern with fibonacci numbers
for i in range(2, k + 1):
    memo[i] = memo[i - 1] + memo[i - 2]
    memo[i] %= 1000000007
        
print(memo[k - 1])
