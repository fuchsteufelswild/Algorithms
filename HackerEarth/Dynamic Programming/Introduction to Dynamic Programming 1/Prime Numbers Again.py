primes = [2, 3, 5]
primeprimes = [4, 27, 3125]
sums = [x for x in range(10001)]
sums[0] = sums[1] = 0 
sums[2] = sums[3] = sums[4] = sums[5] = sums[7] = 1
sums[6] = sums[8] = 2

# Precalculate prime array
for i in range(7, 10001):
    flag = True
    for j in primes:
        if(i % j == 0):
            flag = False
            break
    if(flag):
        primes.append(i)
        if(i < 100):
            primeprimes.append(i ** i)

primes.extend(primeprimes)
primes = sorted(primes)
for i in range(9, 10001):
    temp = 10000
    if(i in primes):
        sums[i] = 1
        continue
    for j in primes:
        if(j >= i - 1):
            break
        
        temp = min(temp, sums[i - j] + 1)
    sums[i] = temp

t = int(input())

for i in range(t):
    n = int(input())
    
    print(sums[n])
