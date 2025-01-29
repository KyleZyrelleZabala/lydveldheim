#Double-base palindromes
import time

def solution(dec):
    i = 0
    while (i<dec):
        s = str(i)
        binary = str(bin(i))[2:]
        if(s == s[::-1]) and (binary == binary[::-1]):
            yield i
        i += 1

def main():
    sum = 0
    for num in solution(1000000):
        sum += num
    print (sum)

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
