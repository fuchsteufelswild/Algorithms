t = int(input())

for case in range(t):
    n = int(input())
    arr = [int(x) for x in input().split(" ") if x != '']
    
    mcs = -1000000 # Contiguous max sum
    cs = -1000000  # Temp contigous sum
    s = 0          # Max sum
    
    for numb in arr:
        if(numb > 0):
            s += numb
        cs = max(cs + numb, numb)
        mcs = max(cs, mcs)
        
    if(s == 0): # If all numbers are negative
        s = max(arr)
    print(mcs, s)
