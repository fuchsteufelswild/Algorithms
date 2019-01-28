t = int(input())

for i in range(t):
    n, k = [int(x) for x in input().split(" ")]
    arr = [int(x) for x in input().split(" ") if x != '']
    A = []
    l = 0
    
    for j in range(k + 1):
        A.append(arr[j])
    m = 0
    
    for j in range(k + 1, n):
        m = max(m, A[l])     # Calculated best till lth index
        A.append(m + arr[j]) # jth number + calculated best at (j - k - 1)th index
        l += 1
    
    print(max(max(A), 0))
