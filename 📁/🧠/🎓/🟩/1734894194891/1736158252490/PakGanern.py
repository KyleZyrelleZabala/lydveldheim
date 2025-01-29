import time

start = time.time();

def solution(arg):
    for x in range(1,arg+1):
        pakganern = []
        for y in range(0, int(x/2) + int(x&1)): #divide by 2 since 1 ganern for every 1 pak, then add 1 to limit if number is odd
            pakganern.append((lambda: "Ganern", lambda: "Pak")[x&1]())
        print("".join(pakganern))

def main():
    solution(int(input()))

if __name__ == "__main__":
    main()

    print("Time: {:.5f} seconds".format(time.time() - start))
