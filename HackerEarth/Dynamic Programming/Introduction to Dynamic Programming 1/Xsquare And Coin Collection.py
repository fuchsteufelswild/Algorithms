t = int(input())

for i in range(t):
    n, k = [int(x) for x in input().split(" ")]
    numbs = [int(x) for x in input().split(" ") if x != '']
    
    m = 0
    s = 0
    for numb in numbs:
        if(numb <= k): # while height <= k
            s += numb
        else:
            m = max(m, s)
            s = 0
        
    print(max(m, s))
