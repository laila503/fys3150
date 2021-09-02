import numpy as np
import matplotlib.pyplot as plt


data=np.loadtxt("exact_solution.dat")

x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.savefig('plot.pdf')
