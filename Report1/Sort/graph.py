import matplotlib.pyplot as plt

plt.title("Execution time")

plt.plot([12500,25000,37500,50000,62500,75000,87500,100000,112500,125000], 
    [166,662,1482,2682,4174,5951,8050,10540,13333,16428], label="Selection sort")
plt.plot([12500,25000,37500,50000,62500,75000,87500,100000,112500,125000], 
    [96,380,846,1547,2360,3370,4598,5959,7368,9361], label="Insetion sort")
plt.plot([12500,25000,37500,50000,62500,75000,87500,100000,112500,125000], 
    [492,2108,4879,8935,13880,20207,27493,36012,45594,56324], label="Bubble sort")

plt.legend(loc='upper left')
plt.xlabel("Input data size")
plt.ylabel("Average of Execution time(msec)")

plt.show()