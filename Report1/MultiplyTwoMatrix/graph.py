import matplotlib.pyplot as plt

plt.title("Execution time")

plt.plot([20000,40000,60000,80000,100000], [6,13,23,32,50])

plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(msec)")

plt.show()