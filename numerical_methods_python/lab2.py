import math


def functions_system(x1, x2):
    return [
        math.cos(0.4 * x2 + x1**2) + x2**2 + x1**2 - 1.6,
        1.5 * x1**2 - x2**2 / 0.36
    ]

def derivative_functions_system(x1, x2):
    return [
        math.cos(0.4 * x2 + x1**2) + x2**2 + x1**2 - 1.6,
        1.5 * x1**2 - x2**2 / 0.36
    ]
