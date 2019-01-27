t = int(input())

# Number of all letters must be even
for i in range(t):
    flag = True
    st = input()
    cDict = {}
    
    for x in st:
        if(ord(x) in cDict):
            cDict[ord(x)] += 1
        else:
            cDict[ord(x)] = 1
    
    for key, val in cDict.items():
        if(val % 2 != 0):
            print(-1)
            flag = False
            break
        
    if(flag):
        print(1)
