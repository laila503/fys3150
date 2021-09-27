import numpy as np
import matplotlib.pyplot as plt

#Problem 6a:
iterations = np.loadtxt("iterations.txt")

plt.loglog(iterations[10:,0], iterations[10:,1], label="Tridiag")
plt.xlabel("N")
plt.ylabel("iterations")
plt.legend()
plt.title("Plot of iterations vs. matrix size")
plt.savefig("iterations_a.pdf")
plt.clf()

#Problem 6b:
iterations_dense = np.loadtxt("iterations_dense.txt")

plt.loglog(iterations[10:,0], iterations[10:,1], label="Tridiag")
plt.loglog(iterations_dense[10:,0], iterations_dense[10:,1], label="Dense")
plt.xlabel("N")
plt.ylabel("iterations")
plt.legend()
plt.title("Plot of iterations vs. matrix size")
plt.savefig("iterations_b.pdf")
plt.clf()

#Problem7a

eigenvalues_10 = np.loadtxt("eigenvalues_10.dat")
eigenvectors_10 = np.loadtxt("eigenvectors_10.dat")

data_10 = eigenvectors_10[:,eigenvalues_10.argsort()[:3]]
data_10_1 = np.array(data_10[:,0])
data_10_2 = np.array(data_10[:,1])
data_10_3 = np.array(data_10[:,2])

#adding boundary values:
data_10_1 = np.insert(data_10_1, 0,0)
data_10_1 = np.append(data_10_1, 0)
data_10_2 = np.insert(data_10_2, 0,0)
data_10_2 = np.append(data_10_2, 0)
data_10_3 = np.insert(data_10_3, 0,0)
data_10_3 = np.append(data_10_3, 0)

#Making the x vector
x_10 = np.linspace(0,1,12)
x_100 = np.linspace(0,1,102)

plt.plot(x_10, data_10_1, label=r" $v_1$")
plt.plot(x_10, data_10_2, label=r"$v_2$")
plt.plot(x_10, data_10_3, label=r"$v_3$")
plt.legend()
plt.xlabel(r"$\hat{x}$")
plt.ylabel(r"$v$")
plt.title("Plot of the three eigenvectors for N=10")
plt.savefig("eigenvectors_10.pdf")
plt.clf()

#Analytical
analytical_eigenvector_10 = np.loadtxt("analytical_eigenvector_10.dat")
analytical_eigenvalues_10 = np.loadtxt("analytical_eigenvalues_10.dat")
data_ana_10 = analytical_eigenvector_10[:,analytical_eigenvalues_10.argsort()[:3]]

data_10_ana_1 = np.array(data_ana_10[:,0])
data_10_ana_2 = np.array(data_ana_10[:,1])
data_10_ana_3 = np.array(data_ana_10[:,2])

#adding boundary values:
data_10_ana_1 = np.insert(data_10_ana_1, 0,0)
data_10_ana_1 = -np.append(data_10_ana_1, 0)
data_10_ana_2 = np.insert(data_10_ana_2, 0,0)
data_10_ana_2 = -np.append(data_10_ana_2, 0)
data_10_ana_3 = np.insert(data_10_ana_3, 0,0)
data_10_ana_3 = -np.append(data_10_ana_3, 0)

plt.plot(x_10, data_10_ana_1, label=r" $v_1$ ana", c="red")
plt.plot(x_10, data_10_ana_2, label=r"$v_2$ ana", c="red")
plt.plot(x_10, data_10_ana_3, label=r"$v_3$ ana", c="red")
plt.plot(x_10, data_10_1, label=r" $v_1$ jacobi", c="green", linestyle=":")
plt.plot(x_10, data_10_2, label=r"$v_2$ jacobi", c="green", linestyle=":")
plt.plot(x_10, data_10_3, label=r"$v_3$ jacobi", c="green", linestyle=":")
plt.legend()
plt.xlabel(r"$\hat{x}$")
plt.ylabel(r"$v$")
plt.title("Plot of the three eigenvectors for N=10")
plt.savefig("eanalytical_igenvectors_10.pdf")
plt.clf()

#Problem7b
eigenvalues_100 = np.loadtxt("eigenvalues_100.dat")
eigenvectors_100 = np.loadtxt("eigenvectors_100.dat")
data_100 = eigenvectors_100[:,eigenvalues_100.argsort()[:3]]

data_100_1 = np.array(data_100[:,0])
data_100_2 = np.array(data_100[:,1])
data_100_3 = np.array(data_100[:,2])

analytical_eigenvector_100 = np.loadtxt("analytical_eigenvector_100.dat")
analytical_eigenvalues_100 = np.loadtxt("analytical_eigenvalues_100.dat")
data_ana_100 = analytical_eigenvector_100[:,analytical_eigenvalues_100.argsort()[:3]]

data_100_ana_1 = np.array(data_ana_100[:,0])
data_100_ana_2 = np.array(data_ana_100[:,1])
data_100_ana_3 = np.array(data_ana_100[:,2])

#adding boundary values:
data_100_ana_1 = np.insert(data_100_ana_1, 0,0)
data_100_ana_1 = -np.append(data_100_ana_1, 0)
data_100_ana_2 = np.insert(data_100_ana_2, 0,0)
data_100_ana_2 = -np.append(data_100_ana_2, 0)
data_100_ana_3 = np.insert(data_100_ana_3, 0,0)
data_100_ana_3 = -np.append(data_100_ana_3, 0)

data_100_1 = np.insert(data_100_1, 0,0)
data_100_1 = np.append(data_100_1, 0)
data_100_2 = np.insert(data_100_2, 0,0)
data_100_2 = np.append(data_100_2, 0)
data_100_3 = np.insert(data_100_3, 0,0)
data_100_3 = np.append(data_100_3, 0)



plt.plot(x_100, data_100_ana_1, label=r" $v_1$ ana", c="red")
plt.plot(x_100, data_100_ana_2, label=r"$v_2$ ana", c="red")
plt.plot(x_100, data_100_ana_3, label=r"$v_3$ ana", c="red")
plt.plot(x_100, data_100_1, label=r" $v_1$ jacobi", c="green", linestyle=":")
plt.plot(x_100, data_100_2, label=r"$v_2$ jacobi", c="green", linestyle=":")
plt.plot(x_100, data_100_3, label=r"$v_3$ jacobi", c="green", linestyle=":")
plt.legend()
plt.xlabel(r"$\hat{x}$")
plt.ylabel(r"$v$")
plt.title("Plot of the three eigenvectors for N=100")
plt.savefig("eanalytical_igenvectors_100.pdf")
plt.clf()

