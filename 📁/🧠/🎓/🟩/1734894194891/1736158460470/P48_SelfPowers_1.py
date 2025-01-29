import time

def solve():
    return sum(pow(i,i,10**10) for i in range(1,1001)) % 10**10

def main():
    print(solve())

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
