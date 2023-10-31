import numpy as np

# TODO:
# 1. A * x = b      -> x'
# 2. A * x'         -> b'
# 3. F = b' - b     -> |F|
# 4. A * x = b'     -> x''
# 5. d = (|| x''[i] - x'[i]||) / |x'[i]|
# Чтобы повысить точность, смещаем значения в сторону десятичной части: все числа матрицы делим на наибольшее. 


def find_main_element(matrix, column):
    line = column
    for i in range(column + 1, len(matrix)):
        if abs(matrix[i][column]) > abs(matrix[line][column]):
            line = i
    return line

def solve_linear_system_gauss(matrix, vector):
    matrix_size = len(matrix)
    # Make the values of the matrix and the vector <= 1.0.
    max_num = max([max(i) for i in matrix])
    if max_num == 0:
        raise ValueError("Zero divison. There is no solution to this linear system.")
    matrix = [[num/max_num for num in matrix[line]] for line in range(matrix_size)]
    vector = [num/max_num for num in vector]
    
    # Transform the matrix into the \| matrix.
    for i in range(matrix_size):
        k = find_main_element(matrix, i)
        if k != i:
            matrix[k], matrix[i] = matrix[i], matrix[k]
            vector[k], vector[i] = vector[i], vector[k]
        if matrix[i][i] == 0:
            raise ValueError("Zero divison. There is no solution to this linear system.")
        vector[i] = vector[i] / matrix[i][i]
        matrix[i] = [num/matrix[i][i] for num in matrix[i]]
        for q in range(i+1, matrix_size):
                if matrix[q][i] != 0:
                    vector[q] = vector[q] / matrix[q][i]
                    matrix[q] = [num/matrix[q][i] for num in matrix[q]]
                    for k in range(matrix_size):
                        matrix[q][k] -= matrix[i][k]
                    vector[q] = vector[q] - vector[i]

    print(matrix)
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


def solve_linear_system_ldlt_factorisation(matrix, vector):
    # - Матрица должна быть симметричной
    # O(n^3 / 6)
    # + Метод является устойчивым к ошибкам округления и 
    # не требует перестановок строк и столбцов.
    # + По времени решения приблизительно в 2 раза быстрее метода Гаусса
    matrix_size = len(matrix)
    L = [[0 for _ in range(matrix_size)] for _ in range(matrix_size)]
    D = [[0 for _ in range(matrix_size)] for _ in range(matrix_size)]
    Lt = None

    for i in range(matrix_size):
        D[i][i] = matrix[i][i] - sum([D[k][k]*L[i][k]*L[i][k] for k in range(i)])
        L[i][i] = 1
        for q in range(i+1, matrix_size):
            substraction_unit = 0
            for m in range(i):
                substraction_unit = D[m][m]
                for k in range(m, matrix_size):
                    substraction_unit *= L[k][m]
            L[q][i] = (matrix[q][i] - substraction_unit) / D[i][i]
    
    L = np.array(L)
    D = np.array(D)
    Lt = np.transpose(L)

    print(L)
    print(D)
    print(Lt)

    y_solution = [0 for _ in range(matrix_size)]
    for i in range(matrix_size):
        y_solution[i] = (vector[i] - sum([L[i][k] * y_solution[k] for k in range(i)])) / L[i][i]

    z_solution = [0 for _ in range(matrix_size)]
    for i in range(matrix_size):
        z_solution[i] = y_solution[i] / D[i][i]
    
    x_solution = [0 for _ in range(matrix_size)]
    for i in range(matrix_size-1, -1, -1):
        x_solution[i] = (z_solution[i] - sum([Lt[i][k] * x_solution[k] for k in range(i+1, matrix_size)])) / Lt[i][i]

    print(y_solution)
    print(z_solution)
    print("Solution (x): ", x_solution)

while True:
    test_case = input("Number of the test case: ")
    matrix_A = []
    vector_b = None
    with open("lab1_test_cases.txt", "r") as test_file:
        while True:
            line = test_file.readline().split()
            if line == '':
                raise ValueError("There is no such test case.")
            if line[0] == "test_case" and line[1] == test_case:
                break
        matrix_A.append([float(num) for num in test_file.readline().split()])
        for i in range(len(matrix_A[0])-1):
            matrix_A.append([float(num) for num in test_file.readline().split()])
        vector_b = [float(num) for num in test_file.readline().split()]
    
    method = int(input("Method (Gauss - 0, LDLt - 1): "))
    if not method:
        solution = solve_linear_system_gauss(matrix_A, vector_b)
        print(f"Solution: {solution}")

        vector_b_reverse_ingeneered = np.matmul(matrix_A, solution)
        print(f"Reverse ingeneered b: {vector_b_reverse_ingeneered}")

        error_vector = np.subtract(vector_b_reverse_ingeneered, vector_b)
        print(f"Error vector: {error_vector}")
        max_abs_error_val = max([abs(i) for i in error_vector])
        print(f"Error vectors' norm: {max_abs_error_val}")

        solution_with_error = solve_linear_system_gauss(matrix_A, vector_b_reverse_ingeneered)
        print(f"Solution with error: {solution_with_error}")

        relative_error = max([abs(i) for i in np.subtract(solution_with_error, solution)]) / max([abs(i) for i in solution])
        print(f"Relative error: {relative_error}")
    else:
        solve_linear_system_ldlt_factorisation(matrix_A, vector_b)