import matplotlib.pyplot as plt
from numlib import LSM_approximation

values = [[float(i) for i in range(0, 101, 5)],
          [1.00762, 1.00392, 1.00153, 1.00000, 0.99907, 0.99852,
            0.99826, 0.99818, 0.99828, 0.99849, 0.99878, 0.99919,
              0.99967, 1.00024, 1.00091, 1.00167, 1.00253, 1.00351,
                1.00461, 1.00586, 1.00721]]

a = LSM_approximation(values=values, m=5)

x = [i for i in range(int(values[0][0])-1, int(values[0][-1])+1)]
print(a)
print(x)

y = [sum([x[i]**k * a[k] for k in range(len(a))]) for i in range(len(x))]

fig, ax = plt.subplots()
ax.plot(x, y, color="blue")
ax.plot(values[0], values[1], color="red")
ax.legend(labels=["approximated function", "plot from values"])
plt.show()