import numpy as np
from numlib import euler_explicit_method

def dU(U, t):
    if t == 0:
        return [0, -U[1]*U[1] + sum([(2.5 + w/40)*t / (1 + t*t) for w in range(25, 49, 1)])]
    return [-U[0]*U[1] + np.sin(t) / t, -U[1]*U[1] + sum([(2.5 + w/40)*t / (1 + t*t) for w in range(25, 49, 1)])]

U0 = np.array([0, -0.412])
u, t = euler_explicit_method(F=dU, U0=U0)

with open("lab3_explicit_euler_data.txt", "w") as output_file:
    for i in range(len(u)):
        line = str(i) + "   " + str(u[i]) + "   " + str(t[i]) + "\n"
        output_file.write(line)