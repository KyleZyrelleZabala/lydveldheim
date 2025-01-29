import time, itertools, math

def solve():
    grid = [[int(s) for s in d.split(",")] for d in open("P81_PathSum2Ways_Source.txt","r").readlines()]
    for i in reversed(range(len(grid))):
        for j in reversed(range(len(grid))):
            if i + 1 < len(grid) and j + 1 < len(grid):
                tot = min(grid[i + 1][j], grid[i][j + 1])
            elif i + 1 < len(grid):
                tot = grid[i + 1][j]
            elif j + 1 < len(grid[i]):
                tot = grid[i][j + 1]
            else:
                tot = 0
            grid[i][j] += tot
            #print(grid[i][j],i,j)
    return str(grid[0][0])

    
def main():
    print(solve())

if __name__ == "__main__":
    start = time.time();
    main()
    print("Time: {:.5f} seconds".format(time.time() - start))
