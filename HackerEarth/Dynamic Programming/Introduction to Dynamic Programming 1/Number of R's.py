t = int(input())

for case in range(t):
    arr = [1 if x == 'K' else -1 for x in input()] # Assign 1 for K and -1 for R
    rc =  0 # Count of R's in the original array 
    mcs = 0 # Max contiguous sum
    cs  = 0 # Temp contiguous sum

    for i in range(len(arr)): # Find the largest sum in array
        cs += arr[i]
        if(cs < 0):
            cs = 0
        if(mcs < cs):
            mcs = max(cs, mcs)
    
    for i in range(len(arr)):
        if(arr[i] == -1):
            rc += 1
            
    if(mcs == 0): # If there exists no K
        print(len(arr) - 1)
    else:
        print(rc + mcs)
