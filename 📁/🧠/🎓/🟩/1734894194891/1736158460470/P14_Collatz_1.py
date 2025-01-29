import time

def solution(arg):
    num = arg
    #print(num, end=" ")
    while num != 1:
        if (num%2==0):
            num/=2
        else:
            num = num*3 + 1
        #print(num, end=" ")
        yield num

def main():
    big = 1
    enter = 1000000-1
    number = enter
    while (enter != 1):
        l = [enter]
        for x in solution(enter):
            l.append(x)
        if big<len(l):
            big, number = len(l), enter
        enter -= 1
        #print("\n")
    print(big, number)

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
