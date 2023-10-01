import numpy as np
import random

# TODO:
# 1. A * x = b      -> x'
# 2. A * x'         -> b'
# 3. F = b' - b     -> |F|
# 4. A * x = b'     -> x''
# 5. d = (|| x''[i] - x'[i]||) / |x'[i]|
#
# Чтобы повысить точность, смещаем значения в сторону десятичной части: все числа матрицы делим на наибольшее. 
#

def round(number, decimals):
    return np.round(number + 10**(-(decimals+1)), decimals)


matrix_size = int(input("Matrix's size: "))
matrix_input_mode = int(input("Input mode for matrix: manual(0) or random numbers(1): "))
matrix_A = [[] for _ in range(matrix_size)]
if not matrix_input_mode:
    print("Enter matrix: ")
    for line in range(matrix_size):
        matrix_A[line] = [int(num) for num in input().split()]
        while len(matrix_A[line]) < matrix_size:
            print("Not enough numbers in matrix's line. Try again: ") 
            matrix_A[line] = [int(num) for num in input().split()]
else:
    for line in range(matrix_size):
        matrix_A[line] = [random.randint(0, 20) for _ in range(matrix_size)]

vector_input_mode = int(input("Input mode for vector: manual(0) or random numbers(1): "))
vector_b = []
if not vector_input_mode:
    print("Enter vector: ")
    vector_b = [int(num) for num in input().split()]
    while len(vector_b) < matrix_size:
        print("Not enough numbers in vector. Try again: ") 
        vector_b = [int(num) for num in input().split()]
else:
    vector_b = [random.randint(0, 20) for _ in range(matrix_size)]

print(matrix_A)
print(vector_b)


max_num = max([max(i) for i in matrix_A])
mod_matrix_A = [[num/max_num for num in matrix_A[line]] for line in range(matrix_size)]
vector_b = [num/max_num for num in vector_b]
print(mod_matrix_A)

for i in range(matrix_size):
    for q in range(i+1, matrix_size):
        div_multiplier = mod_matrix_A[q][i] / mod_matrix_A[i][i]
        for k in range(i, matrix_size):
            mod_matrix_A[q][k] = mod_matrix_A[q][k] - mod_matrix_A[i][k] * div_multiplier
        vector_b[q] = vector_b[q] - vector_b[i] * div_multiplier
print(mod_matrix_A)

for line in range(matrix_size-1, -1, -1):
    if sum(mod_matrix_A[line][:line:]) != 0:
        print("Salvation impossible x_x .")
        break
else:
    matrix_parameters = [0 for _ in range(matrix_size)]
    for line in range(matrix_size-1, -1, -1):
        summed_known_parameters = sum(matrix_parameters[i] * mod_matrix_A[line][i] for i in range(matrix_size) if i != line)
        matrix_parameters[line] = (vector_b[line] - summed_known_parameters) / mod_matrix_A[line][line]
    print("Salvation found.")
    print(matrix_parameters)
