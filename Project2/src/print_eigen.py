import numpy as np

values_anal = np.sort(np.loadtxt("analytical_eigenvalues_6.dat"))
values = np.sort(np.loadtxt("eigenvalues_6.dat"))

print("Jacobi      Analytical")
for i in range(len(values)):
    print("%.3f     %.3f"%(values[i],values_anal[i]))

