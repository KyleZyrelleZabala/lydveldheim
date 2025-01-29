#!/usr/bin/python

###############################################################################
#
# Project Euler Problem 81
# found online at projecteuler.net/problem=81
# Solution by Timothy Reasa
#
###############################################################################

import os, time
dimension = 80

def solve(self):
    if os.path.exists("C:\\Users\\trender\\Desktop\\INTERN - EMREEN\\CHALLENGES\\p081_matrix.txt"):
        f = open("C:\\Users\\trender\\Desktop\\INTERN - EMREEN\\CHALLENGES\\p081_matrix.txt", 'r')

    matrix = []
    for line in f:
        matrix.append([int(r) for r in line.split(',')])

    f.close()
    print (len(matrix))
    # initialize the top row of the matrix
    for i in range(1, len(matrix[0])):
        matrix[0][i] += matrix[0][i - 1]

    # initialize the first column of the matrix
    for i in range(1, len(matrix)):
        matrix[i][0] += matrix[i - 1][0]

    # fill in the rest of the matrix
    for i in range(1, len(matrix)):
        for j in range(1, len(matrix[1])):
            matrix[i][j] += min(matrix[i - 1][j], matrix[i][j - 1])

    return matrix[dimension - 1][dimension - 1]


###############################################################################
#
# If executed as a script/not imported
#
###############################################################################
if __name__ == '__main__':
    start = time.time();
    print (solve(None))
    print("Time: {:.5f} seconds".format(time.time() - start))