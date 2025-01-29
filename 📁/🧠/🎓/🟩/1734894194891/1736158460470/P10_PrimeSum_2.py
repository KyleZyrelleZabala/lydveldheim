import time

def solution(arg):
    primes = [2]
    newPrime = 1
    while (1):
        newPrime += 2
        i = 0
        isPrime = True
        while (primes[i] ** 2 <= newPrime):
            if (newPrime % primes[i] == 0):
                isPrime = False
                break
            i += 1
        if (newPrime > arg):
            break

        if (isPrime):
            primes.append(newPrime)
            yield newPrime

def main():
    sum = 2
    for x in solution(2000000):
        sum+= x
    print(sum)

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
