n = int(input())

A = [0 for x in range(n)]
s = [0 for x in range(n)]
A[0] = s[0] = 1
arr = []
arr.append(int(input()))

c = 0
for i in range(1, n):
    temp = int(input())
    if(temp <= arr[i - 1]):
        if(temp == arr[i - 1]): # If ratings are same
            A[i] = 1
            if(c > 0): # If there was previous smaller ones
                s[i] = s[i - (c + 1)] + int(((c + 2) * (c + 1)) / 2) + A[i]
                if(A[i - (c + 1)] <= c + 1):
                    s[i] -= A[i - (c + 1)]
                else:
                    s[i] -= (c + 1)
                c = 0
            else:
                s[i] = s[i - 1] + 1
        else: # If smaller than the previous one
            c += 1
            if(i == n - 1): # If that is the last patient
                s[i] = s[i - c] + int(((c + 2) * (c + 1)) / 2) + 2
                if(A[i - c] <= c + 1):
                    s[i] -= A[i - c]
                else:
                    s[i] -= (c + 1)
    elif(c > 0): # If rating is greater than the previous one
        A[i - 1] = 1
        A[i] = 2
        s[i] = s[i - (c + 1)] + int(((c + 2) * (c + 1)) / 2) + A[i] # Calculate gained sum
        if(A[i - (c + 1)] <= c + 1):
            s[i] -= A[i - (c + 1)]
        else:
            s[i] -= (c + 1)
        c = 0  # Reset c
    else:
        A[i] = A[i - 1] + 1
        s[i] = s[i - 1] + A[i]
    arr.append(temp)

print(s[n - 1])
