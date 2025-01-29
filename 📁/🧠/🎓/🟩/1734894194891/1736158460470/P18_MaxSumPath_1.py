import time

tree = []

def get():
    data = open("Problem_67_MaxSumPath.txt","r").readlines()
    for i in data:
        row = []
        for num in i.split():
            row.append(int(num))
        tree.append(row)
        #print(row)
        
def solve():
    get()
    for i in range(len(tree)-2,-1,-1):
        for j in range(0,i+1):
            tree[i][j] += max(tree[i+1][j],tree[i+1][j+1])
            #print("ROW ",i+1,": COL ",j+1,": ",tree[i][j]," >> ",i,j,":",i+1,j,"/",i+1,j+1)
    print(tree[0][0])
def main():
    solve()

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
