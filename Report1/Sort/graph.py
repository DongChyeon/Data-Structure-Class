import matplotlib.pyplot as plt

plt.title("Execution time")

plt.plot([25000,50000,75000,100000,125000], [662,2682,5951,10540,16428], label="Selection sort")
plt.plot([25000,50000,75000,100000,125000], [380,1547,3370,5959,9361], label="Insetion sort")
plt.plot([25000,50000,75000,100000,125000], [2108,8935,20207,36012,56324], label="Bubble sort")

plt.legend(loc='upper left')
plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(msec)")

plt.show()