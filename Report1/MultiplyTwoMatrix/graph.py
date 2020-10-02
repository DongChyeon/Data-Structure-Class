import matplotlib.pyplot as plt

plt.title("Execution time")

plt.plot([50000,75000,100000,125000,150000], [1961,2837,3774,4773,5696])

plt.xlabel("rows of m")
plt.ylabel("Average of Execution time(msec)")

plt.show()