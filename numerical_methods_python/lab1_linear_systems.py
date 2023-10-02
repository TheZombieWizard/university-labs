import numpy as np
import math

# TODO:
# 1. A * x = b      -> x'
# 2. A * x'         -> b'
# 3. F = b' - b     -> |F|
# 4. A * x = b'     -> x''
# 5. d = (|| x''[i] - x'[i]||) / |x'[i]|
# Чтобы повысить точность, смещаем значения в сторону десятичной части: все числа матрицы делим на наибольшее. 


def magnitude(vector):
    return math.sqrt(sum(pow(element, 2) for element in vector))


def solve_linear_system(matrix, vector):
    matrix_size = len(matrix)
    
    # Make the values of the matrix and the vector <= 1.0.
    max_num = max([max(i) for i in matrix])
    matrix = [[num/max_num for num in matrix[line]] for line in range(matrix_size)]
    vector = [num/max_num for num in vector]

    # Transform the matrix into the diagonal matrix.
    for i in range(matrix_size):
        for q in range(i+1, matrix_size):
            if matrix[i][i] != 0:
                div_multiplier = matrix[q][i] / matrix[i][i]
                for k in range(i, matrix_size):
                    matrix[q][k] = matrix[q][k] - matrix[i][k] * div_multiplier
                vector[q] = vector[q] - vector[i] * div_multiplier
    
    # Shuffle some lines to come up with true diagonal matrix (if needed).
    for i in range(matrix_size):
        for q in range(i+1, matrix_size):
            if matrix[i][i] == 0 and matrix[q][i] != 0:
                matrix[i], matrix[q] = matrix[q], matrix[i]
                vector[i], vector[q] = vector[q], vector[i]

    # Check if the system has complete solution.
    for line in range(matrix_size-1, -1, -1):
        if sum(matrix[line][:line:]) != 0:
            return None
    
    # Find the complete solution.
    matrix_parameters = [0 for _ in range(matrix_size)]
    for line in range(matrix_size-1, -1, -1):
        if matrix[line].count(0) != matrix_size:
            summed_known_parameters = sum(matrix_parameters[i] * matrix[line][i] for i in range(matrix_size) if i != line)
            matrix_parameters[line] = (vector[line] - summed_known_parameters) / matrix[line][line]
    return matrix_parameters


while True:
    test_case = int(input("Number of the test case: "))
    matrix_A = []
    vector_b = None
    with open("test_cases_for_lab1.txt", "r") as test_file:
        while True:
            line = test_file.readline().split()
            if line == '':
                raise ValueError("There is no such test case.")
            if line[0] == "test_case" and int(line[1]) == test_case:
                break
        matrix_A.append([int(num) for num in test_file.readline().split()])
        for i in range(len(matrix_A[0])-1):
            matrix_A.append([int(num) for num in test_file.readline().split()])
        vector_b = [int(num) for num in test_file.readline().split()]
    temp_matrix_A = matrix_A
    solution = solve_linear_system(temp_matrix_A, vector_b)
    print(f"Solution: {solution}")
    vector_b_reverse_ingeneered = np.matmul(matrix_A, solution)
    print(f"Reverse ingeneered b: {vector_b_reverse_ingeneered}")
    error_vector = np.subtract(vector_b_reverse_ingeneered, vector_b)
    print(f"Error vector: {error_vector}")
    temp_matrix_A = matrix_A
    solution_with_error = solve_linear_system(temp_matrix_A, vector_b_reverse_ingeneered)
    print(f"Solution with error: {solution_with_error}")
    relative_error = magnitude(np.subtract(solution_with_error, solution)) / magnitude(solution)
    print(f"Relative error: {relative_error}")