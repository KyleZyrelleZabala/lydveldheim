import time, itertools, math

def main():
    count= 0
    seed = 10**6
    while seed > 68:
        new = chain([seed],seed)
        if new[0] == 60:
            seed = new[1]
            count +=1
        seed -=1
    print(count)

def stringer(num):
    return [int(c) for c in str(num)]

def chain(arg, seed):
    #print(arg[-1])
    if solve(arg[-1]) not in arg:
        return chain(arg+[solve(arg[-1])], seed)
    else:
        if len(arg) == 60:
            print('LENGTH: ',len(arg),'\t','SEED: ',seed)
        return [len(arg), seed]

def solve(num):
    return sum(math.factorial(i) for i in stringer(num))

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
