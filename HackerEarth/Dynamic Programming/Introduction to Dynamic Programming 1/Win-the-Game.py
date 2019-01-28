t = int(input())

for x in range(t):
    inp = input().split()
    nr = int(inp[0])
    ng = int(inp[1])
    if(ng == 0):
        print("%.6f" % 1)
        continue
    arr = [[[float(-1) for z in range(2)] for y in range(ng + 1)] for x in range(nr + 1)]

    arr[0][0][0] = 0.0
    arr[0][0][1] = 1.0
    
    for i in range(nr + 1):
        for j in range(ng + 1):
            for z in range(2):
                if(arr[i][j][z] != -1): # If not assigned a value
                    continue
                opposite = 0.0 # opposite of Z where z = 0 for satyam and z = 1 for kunkal
                if(z == 0):
                    opposite = 1.0
                if(j == 0):    # If ng == 0
                    arr[i][j][z] = float(z)
                elif(i == 0):  # If nr == 0
                    arr[i][j][z] = float(opposite)
                else:          # Prob. of drawing red + Prob. of drawing green + Prob. that other pl. is not winning
                    arr[i][j][z] = float((i / (i + j))) + (float(j / (j + i))) * (1 - arr[i][j - 1][int(opposite)])

    print("%.6f" % arr[nr][ng][0])
    
    
