import numpy as np
import matplotlib.pyplot as plt

#Problem2
data=np.loadtxt("exact_solution.dat")

x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.savefig('plot.pdf')

#Problem7
data=np.loadtxt("solution.dat")

x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.savefig('solution_plot.pdf')



