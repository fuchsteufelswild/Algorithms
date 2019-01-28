t = int(input())

for i in range(t):
    st = input()
    l = len(st)
    A = [x for x in range(l + 1)]
    
    if(l < 3): # If length < 3 cannot partition
        print(l)
        break
    
    for j in range(l - 3, -1, -1): # Find first encounter of 3 consecutive bars between j and l with step of 3
        if(st[j] == st[j + 1] and st[j] == st[j + 2]): # If consecutive 3 bars are same then
            A[j] = j                                   # store the index 
        else:                                                             
            A[j] = A[j + 3]                            
        
    res = [A[x] - x for x in range(len(A))]
        
    print(l - max(res))
