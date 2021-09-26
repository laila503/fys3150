import numpy as np
import matplotlib.pyplot as plt

iterations = np.loadtxt("iterations.txt")
iterations_dense = np.loadtxt("iterations_dense.txt")

plt.loglog(iterations[10:,0], iterations[10:,1], label="Tridiag")
plt.loglog(iterations_dense[10:,0], iterations_dense[10:,1], label="Dense")
plt.legend()
plt.savefig("iterations.pdf")
plt.clf()


eigenvalues_10 = np.loadtxt("eigenvalues_10.dat")
eigenvectors_10 = np.loadtxt("eigenvectors_10.dat")

eigenvalues_100 = np.loadtxt("eigenvalues_100.dat")
eigenvectors_100 = np.loadtxt("eigenvectors_100.dat")


data_10 = eigenvectors_10[:,eigenvalues_10.argsort()[:3]]
plt.plot(data_10)
plt.savefig("eigenvectors_10.pdf")
plt.clf()

data_100 = eigenvectors_100[:,eigenvalues_100.argsort()[:3]]
plt.plot(data_100)
plt.savefig("eigenvectors_100.pdf")
plt.clf()

analytical_eigenvector_10 = np.loadtxt("analytical_eigenvector_10.dat")
analytical_eigenvalues_10 = np.loadtxt("analytical_eigenvalues_10.dat")

data_ana_10 = analytical_eigenvector_10[:,analytical_eigenvalues_10.argsort()[:3]]
plt.plot(-data_ana_10)
plt.plot(data_10)
plt.savefig("analytical_eigenvectors_10.pdf")
plt.clf()


analytical_eigenvector_100 = np.loadtxt("analytical_eigenvector_100.dat")
analytical_eigenvalues_100 = np.loadtxt("analytical_eigenvalues_100.dat")

data_ana_100 = analytical_eigenvector_100[:,analytical_eigenvalues_100.argsort()[:3]]
plt.plot(-data_ana_100)
plt.plot(data_100)
plt.savefig("analytical_eigenvectors_100.pdf")
plt.clf()

