import time, itertools

def fib(limit):
    a, b = 0, 1
    while len(str(a)) < limit:
        yield a
        a, b = b, a + b

def main():
    ss = [i for i in fib(1000)]
    print(len(ss))
    
if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
