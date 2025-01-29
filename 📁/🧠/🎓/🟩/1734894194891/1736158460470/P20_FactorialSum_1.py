import time
import math

def splitter(s):
    return [ch for ch in s]

def solve(arg):
    num = [int(x) for x in splitter(str(math.factorial(arg)))]
    print(sum(num))
    
def main():
    solve(100)

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
