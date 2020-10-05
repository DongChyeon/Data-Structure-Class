import matplotlib.pyplot as plt

plt.title("Execution time")

plt.plot([100,150,200,250,300,350,400,450,500,550], 
    [5,14,30,60,114,197,289,408,591,778])

plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(msec)")

plt.show()