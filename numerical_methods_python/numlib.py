import numpy as np

#----------------------------------------------  general  ---------------------------------------------
def centered_print(*args, n=20, sep=" "):
    for arg in args:
        print(arg.center(n, sep), end="")
    print("\n")

#-----------------------------------------------  lab1  ----------------------------------------------- 
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

    # print(matrix)
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
#-----------------------------------------------  lab3  ----------------------------------------------- 

def euler_explicit_method(F, U0, T = 1, E = 1e-3, tau_max = 0.01):
    yk = [U0]
    tk = [0]
    while tk[-1] < T:
        Fk = np.array(F(yk[-1], tk[-1]))
        tau_k = E / (max([abs(i) for i in Fk]) + E/tau_max)
        yk.append([yk[-1][i] + tau_k * Fk[i] for i in range(len(Fk))])
        tk.append(tk[-1] + tau_k)
    return yk, tk 

def euler_implicit_method(F, U0, T = 1, E = 1e-3, tau_min = 0.001, tau_max = 0.01):
    from scipy import optimize
    tk = [0]
    yk_prev = U0
    yk = [U0]
    yk_next = U0
    tau_k_prev = tau_min
    tau_k = tau_min
    tk.append(tk[-1] + tau_k)
    def Phi(z, t, v):
        return z - tau_k * F(z, t) - v

    yk_next = optimize.newton(Phi, yk[-1], args=(tk[-1], yk[-1]))
    Ek = [-tau_k/(tau_k + tau_k_prev) * (yk_next[i] - yk[-1][i] - tau_k/tau_k_prev * (yk[-1][i] - yk_prev[i])) for i in range(len(yk[0]))]
    

    pass
#-----------------------------------------------  lab5  ----------------------------------------------- 
def integral_trapeze(function, a: float = 0.0, b: float = 1.0, n: int = 100, E0: float = 1e-5):
    iter: int = 1
    h = (b - a) / n
    sum_function_i = 0
    xi = a+h
    while xi < b-h:
        sum_function_i += function(xi)
        xi += h    
    Ih = h / 2 * (function(a) + 2 * sum_function_i + function(b))
    
    while True:
        iter += 1
        h /= 2    
        sum_function_i = 0
        xi = a+h
        while xi < b-h:
            sum_function_i += function(xi)
            xi += h
        Ihdiv2 = h / 2 * (function(a) + 2 * sum_function_i + function(b))

        if abs(Ihdiv2 - Ih) < 3 * E0:
            return Ihdiv2, iter
        Ih = Ihdiv2

def integral_simpson(function, a: float = 0.0, b: float = 1.0, m: int = 50, E0: float = 1e-5):
    iter: int = 1
    h = (b - a) / (2*m)
    x = [a]
    while len(x) <= 2*m:
        x.append(x[-1] + h)
    
    sum_function_2imin1 = 0
    for i in range(1, m+1):
        sum_function_2imin1 += function(x[2*i-1])
    
    sum_function_2i = 0
    for i in range(1, m):
        sum_function_2i += function(x[2*i])

    Ih = h / 3 * (function(a) + 4 * sum_function_2imin1 + 2 * sum_function_2i + function(b))
    
    while True:
        iter += 1
        m *= 2
        h = (b - a) / (2*m)
    
        x = [a]
        while len(x) < 2*m:
            x.append(x[-1] + h)
    
        sum_function_2imin1 = 0
        for i in range(1, m+1):
            sum_function_2imin1 += function(x[2*i-1])
    
        sum_function_2i = 0
        for i in range(m):
            sum_function_2i += function(x[2*i])

        Ihdiv2 = h / 3 * (function(a) + 4 * sum_function_2imin1 + 2 * sum_function_2i + function(b))
        
        if abs(Ihdiv2 - Ih) < 15 * E0:
            return Ihdiv2, iter
        Ih = Ihdiv2

def integral_cubature_simpson(function, 
                              a: float = 0.0, b: float = 1.0,
                              c: float = 0.0, d: float = 1.0, 
                              n: int = 50, m: int = 50, 
                              E0: float = 1e-5):
    hx = (b - a) / (2*n)
    hy = (d - c) / (2*m)

    Ih = 0
    for i in range(n):
        for j in range(m):
            Ih += function(a + (2*i)*hx, c + (2*j)*hy)
            Ih += 4 * function(a + (2*i+1)*hx, c + (2*j)*hy)
            Ih += function(a + (2*i+2)*hx, c + (2*j)*hy)
            Ih += 4 * function(a + (2*i)*hx, c + (2*j+1)*hy)
            Ih += 16 * function(a + (2*i+1)*hx, c + (2*j+1)*hy)
            Ih += 4 * function(a + (2*i+2)*hx, c + (2*j+1)*hy)
            Ih += function(a + (2*i)*hx, c + (2*j+2)*hy)
            Ih += 4 * function(a + (2*i+1)*hx, c + (2*j+2)*hy)
            Ih += function(a + (2*i+2)*hx, c + (2*j+2)*hy)
    Ih *= (hy * hx / 9)
    return Ih        
#------------------------------------------------------------------------------------------------------ 

def LSM_approximation(values: list[list] = [[0, 1],[0, 1]], m: int = 1):
    x: list = values[0]
    y: list = values[1]
    N: int = len(y)
    if (len(y) != len(x)) or len(x) == 0 or len(y) == 0:
        raise ValueError("Something wrong with input data.")
    
    POWERX: list = [0 for _ in range(2*m)]
    for k in range(2*m):
        for i in range(N):
            POWERX[k] += x[i]**(k+1)
    print("POWERX: ", POWERX)

    SUMX: list[list] = [[0 for i in range(m+1)] for q in range(m+1)]
    for l in range(m+1):
        for j in range(m+1):
            SUMX[l][j] = POWERX[l + j - 1]
    SUMX[0][0] = N
    print("SUMX: ", SUMX)
    
    PRAW: list = [0 for _ in range(m+1)]
    for l in range(m+1):
        PRAW[l] = sum([y[i]*x[i]**l for i in range(N)])
    print("PRAW: ", PRAW)

    a: list = solve_linear_system_gauss(SUMX, PRAW)
    S_squared: float = 1 / (N - m - 1) * sum([(y[i] - sum([a[m]*x[i]**m for m in range(m)]))**2 for i in range(N)])
    variance: float = np.sqrt(S_squared)
    print("S squared: ", S_squared)
    print("Variance: ", variance)
    
    return a