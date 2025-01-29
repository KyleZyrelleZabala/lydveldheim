import time
start = time.time()
limit = 1000
f=0
a=1
while (a < limit and f == 0):
    for b in range(1, limit-a-1):
        c = limit-a-b
        if (a*a + b*b == c*c):
            print(a," ",b," ",c," = ",a*b*c)
            print("Time: {:.5f} seconds".format(time.time() - start))
            f=1
    a+=1
