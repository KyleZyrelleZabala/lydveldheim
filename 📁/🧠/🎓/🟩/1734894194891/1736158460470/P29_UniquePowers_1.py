#Problem 29
import time

def gen(arg):
    for i in range(2,arg+1):
        for j in range(2,arg+1):
            yield i**j

def main():
    arr = set(gen(100))
    print(len(arr))

if __name__ == '__main__':
    start = time.time()
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
