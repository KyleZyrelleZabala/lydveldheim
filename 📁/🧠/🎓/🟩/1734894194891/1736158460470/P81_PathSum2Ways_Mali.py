import time, itertools
def solution(arg):
    results = [0,0,0]
    sum,m,n = 0,0,0
    l = []

    with open(arg) as file:
        while True:
            line = next(file,None)
            if line is None:
                break
            l.append(line.split(","))
    while 1:
        if (m >= 79 or n >= 79):
            break
        results = tree(l,m,n,sum)
        print(results)
        #print(len(results))
        sum,m,n = results[0], results[1], results[2]
    print(sum)


def tree(l,m,n,sum):
    while (1):
        print(l)
        if (int(l[m+1][n]) > int(l[m][n+1])):
            m += 1
        else:
            n += 1
        sum += int(l[m][n])
        return [sum, m, n]

def main():
    solution("C:\\Users\\trender\\Desktop\\INTERN - EMREEN\\CHALLENGES\\p081_matrix.txt")

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
