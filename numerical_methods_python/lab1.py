import numpy as np
from numlib import solve_linear_system_gauss, solve_linear_system_ldlt_factorisation

# TODO:
# 1. A * x = b      -> x'
# 2. A * x'         -> b'
# 3. F = b' - b     -> |F|
# 4. A * x = b'     -> x''
# 5. d = (|| x''[i] - x'[i]||) / |x'[i]|
# Чтобы повысить точность, смещаем значения в сторону десятичной части: все числа матрицы делим на наибольшее. 


if __name__ == "__main__":
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