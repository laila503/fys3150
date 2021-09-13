import numpy as np
import matplotlib.pyplot as plt


#Problem2
"""
data=np.loadtxt("exact_solution.dat")

x = data[:,0]
y = data[:,1]

plt.plot(x,y,label="Exact")
plt.title('Problem 2: Plot of the exact solution')
plt.xlabel('x')
plt.ylabel('u(x)') 
plt.savefig('plot_exact_solution.pdf')
"""


#Problem7
ns = [10,100,1000,10000, 100000, 1000000, 10000000]

results = {}

for n in ns:
    print(f"Loading data for N={n}")
    data=np.loadtxt(f"solution_{n}.dat")
    

    x = data[:,0]
    y = data[:,1]
    exact_y = data[:,2]

    result = {
        "x": x,
        "y": y,
        "exact": exact_y,
        "abs_error": abs(y[1:-1]-exact_y[1:-1]), #Remove ends to not have zeros in division and log
        "rel_error": abs((y[1:-1]-exact_y[1:-1])/exact_y[1:-1]), #Remove ends to not have zeros in division and log
    }

    results[n] = result



# Plots numerical results
for n in ns:
    plt.plot(results[n]["x"],results[n]["y"], label=f"N={n}")
    
plt.title('Problem 7: Plot of the numerical solution')
plt.xlabel('x')
plt.ylabel('u(x)') 
plt.legend()
plt.savefig('plot_numeric_solution.pdf')
plt.clf()


# Plots relative errors in log log plot
for n in ns:
    plt.semilogy(results[n]["x"][1:-1],results[n]["rel_error"], label=f"N={n}")

plt.xlabel("x")
plt.ylabel(r"$\Delta$")
plt.title("Relative Error")
plt.legend()
plt.savefig('plot_rel_error.pdf')
plt.clf()

# Plots absolute errors in log log plot
for n in ns:
    plt.semilogy(results[n]["x"][1:-1],results[n]["abs_error"], label=f"N={n}")

plt.xlabel("x")
plt.ylabel(r"$\epsilon$")
plt.title("Absolute Error")
plt.legend()
plt.savefig('plot_abs_error.pdf')
plt.clf()


max_errors = []

# Plots max of absolute error in log log plot
for n in ns:
    max_errors.append(np.max((results[n]["rel_error"])))

plt.loglog(ns, max_errors, ".-")
plt.xlabel("N")
plt.ylabel(r"$\max(\epsilon_i)$")
plt.savefig("plot_max_rel_error.pdf")

"""
"""
