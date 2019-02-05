t = int(input())

for case in range(t):
    arr = [1 if x == 'G' else -1 for x in input()] # Assign 1 for G and -1 for A
    rc =  0 # Count of A's in the original array 
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
            
    if(mcs == 0): # If there exists no G
        print(len(arr) - 1)
    else:
        print(rc + mcs)
