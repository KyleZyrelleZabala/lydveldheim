import time
start = time.time()

def fib(limit):
    a, b = 0, 1
    while a < limit:
        yield a
        a, b = b, a + b

def main():
    ss = []
    for x in fib(4000000):
        if (x%2==0):
            ss.append(x)
    print(sum(ss))
    
if __name__ == "__main__":
    main()
    
print("Time: {:.5f} seconds".format(time.time() - start))
