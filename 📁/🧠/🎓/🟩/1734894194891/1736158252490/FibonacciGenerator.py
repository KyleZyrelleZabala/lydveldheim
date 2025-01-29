import time
start = time.time()

def fib(limit):
    a, b = 0, 1
    while b < limit:
        yield a
        a, b = b, a + b

def main():
    for x in fib(1000):
        print(x)
    
if __name__ == "__main__":
    main()
    
print("Time: {:.5f} seconds".format(time.time() - start))
