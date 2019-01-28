inp = input().split(" ")
n, q = [int(x) for x in inp]

inp = input().split(" ")
if(inp[len(inp) - 1] == ''):
    inp.pop()
A = [int(x) for x in inp]

inp = input().split(" ")
if(inp[len(inp) - 1] == ''):
    inp.pop()
B = [int(x) for x in inp]

Atype1 = [A[0]]
Atype2 = [0]
# Type1 even Type2 odd
for i in range(1, len(A)):
    if(i % 2 == 0): # Even index
        Atype1.append(Atype1[i - 2] + A[i])
        Atype2.append(Atype2[i - 1])
    else:           # Odd index
        Atype1.append(Atype1[i - 1])
        Atype2.append(Atype2[i - 2] + A[i])

Btype1 = [B[0]]
Btype2 = [0]

for i in range(1, len(B)):
    if(i % 2 == 0): # Even index
        Btype1.append(Btype1[i - 2] + B[i])
        Btype2.append(Btype2[i - 1])
    else:           # Odd index
        Btype1.append(Btype1[i - 1])
        Btype2.append(Btype2[i - 2] + B[i])

for i in range(q):
    inp = input().split(" ")
    inp = [int(x) for x in inp]
    
    inp[1] -= 1
    inp[2] -= 1
    t, s, e = inp
    
    res = 0
    if(t == 1): # If starts with A
        if(s % 2 == 0):   # Starts with even index
            res = Atype1[e] + Btype2[e]
            if(s != 0):
                res -= (Atype1[s - 1] + Btype2[s - 1])
        else:             # Starts with odd index
            res = Atype2[e] + Btype1[e]
            if(s != 0):
                res -= (Atype2[s - 1] + Btype1[s - 1])
    else:       # If starts with B
        if(s % 2 != 0):
            res = Atype1[e] + Btype2[e]
            if(s != 0):
                res -= (Atype1[s - 1] + Btype2[s - 1])
        else:
            res = Atype2[e] + Btype1[e]
            if(s != 0):
                res -= (Atype2[s - 1] + Btype1[s - 1])
    
    print(res)
            
