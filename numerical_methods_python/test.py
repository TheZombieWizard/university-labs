from numlib import LSM_approximation
import matplotlib.pyplot as plt
import numpy as np

values = [
          #[25, 30, 40, 50, 60, 70, 80, 90, 100],
          [1/(i+273) for i in [25, 30, 40, 50, 60, 70, 80, 90, 100]],
          #[1.41, 1.26, 0.93, 0.61, 0.53, 0.34, 0.27, 0.23, 0.172],
          #[np.log(1/i) for i in [1.41, 1.26, 0.93, 0.61, 0.53, 0.34, 0.27, 0.23, 0.172]],
          #[0.164, 0.167, 0.172, 0.175, 0.181, 0.188, 0.191, 0.201, 0.21],
          #[142.3, 123.1, 83.5, 71.3, 46.7, 29.1, 23.4, 19.7, 13.5],
          [np.log(1/i) for i in [142.3, 123.1, 83.5, 71.3, 46.7, 29.1, 23.4, 19.7, 13.5]],
]

a = LSM_approximation(values=values, m=1)
x = values[0]
#x = [i for i in range(20, 106)]
if x[0] > x[-1]:
    x = x[::-1]

y = [sum([x[i]**k * a[k] for k in range(len(a))]) for i in range(len(x))]
print()
print([round(i, 3) for i in y])

fig, ax = plt.subplots()
ax.plot(x, y, color="orange")
ax.set_xlim([x[0], x[-1]])
#ax.set_xlabel("t,°C")
#ax.set_ylabel("R3, кОм")
ax.set_xlabel("1/T, 1/K")
ax.set_ylabel("ln(1/R1)")
ax.scatter(values[0], values[1], color="black", marker=".")
plt.show()