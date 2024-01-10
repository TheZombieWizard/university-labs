from numlib import integral_trapeze
from numlib import integral_simpson
from numlib import integral_cubature_simpson


# Wolfram Alpha func = (1 + 2 * x**3)**(1/2), a = 1.2, b = 2.471 -> ans = 4.72712
print("\n")
print("Trapeze: ")
print(integral_trapeze(lambda x: (1 + 2 * x**3)**(1/2), a=1.2, b=2.471, E0=1e-4))
print(integral_trapeze(lambda x: (1 + 2 * x**3)**(1/2), a=1.2, b=2.471, E0=1e-5))
print("\n")

print("Simpson: ")
print(integral_simpson(lambda x: (1 + 2 * x**3)**(1/2), a=1.2, b=2.471, E0=1e-4))
print(integral_simpson(lambda x: (1 + 2 * x**3)**(1/2), a=1.2, b=2.471, E0=1e-5))
print("\n")


# Wolfram Alpha func = (x**2 + 2*y), a = 0.0, b = 2.0, c = 0.0, d = 1.0 -> ans = 4.6667
print("Cubature Simpson: ")
print(integral_cubature_simpson(lambda x, y: (x**2 + 2*y), a=0.0, b=2.0, c=0.0, d=1.0, E0=1e-4))
print(integral_cubature_simpson(lambda x, y: (x**2 + 2*y), a=0.0, b=2.0, c=0.0, d=1.0, E0=1e-5))
print("\n")
