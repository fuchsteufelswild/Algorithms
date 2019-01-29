t = int(input())

for i in range(t):
    n = int(input())
    arr = [int(x) for x in input().split(" ") if x != '']
    
    for j in range(1, n): # Calculate sum till every index
        arr[j] += arr[j - 1]
        
    res = 100000001
    for j in range(0, n): # arr[n - 1] - arr[j] = X + arr[j]
        temp = arr[n - 1] - 2 * arr[j]
        if(temp < 0):
            continue
        res = min(res, arr[n - 1] - 2 * arr[j])
    
    if(res == 100000001):
        res = -1
    print(res)
