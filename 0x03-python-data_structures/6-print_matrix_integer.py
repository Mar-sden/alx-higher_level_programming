#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    if matrix:
        for row in matrix:
            if row:
                for idx, col in enumerate(row):
                    if idx == (len(row) - 1):
                        print("{:d}".format(col))
                    else:
                        print("{:d}".format(col), end=" ")
            else:
                print()
