m, n = [int(x) for x in input().split(" ")]
C = sorted([int(x) for x in input().split(" ")])

res = [0 for x in range(n + 1)]
res[0] = 1

for i in range(m):
    for j in range(C[i], n + 1):
        res[j] += res[j - C[i]]
        res[j] %= 1000000007

print(res[n])
