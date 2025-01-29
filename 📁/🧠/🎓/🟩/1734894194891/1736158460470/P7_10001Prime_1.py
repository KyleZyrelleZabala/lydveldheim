primes = [2]
newPrime = 1
while (len(primes) < 10001):
    newPrime += 2
    i = 0
    isPrime = True
    while (primes[i] ** 2 <= newPrime):
        if (newPrime % primes[i] == 0):
            isPrime = False
            break
        i += 1
    if (isPrime):
        primes.append(newPrime)
        #print(newPrime, " ", len(primes))
print(primes[-1])
