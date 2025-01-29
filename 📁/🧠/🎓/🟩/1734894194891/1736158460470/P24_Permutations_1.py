#Problem 24
import itertools, time

def solve(arg):
    arr = list(range(10))
    num = itertools.islice(itertools.permutations(arr), arg-1, None)
    return "".join(str(x) for x in next(num))

def main():
    print(solve(1000000))
    
if __name__ == '__main__':
    start = time.time()
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
