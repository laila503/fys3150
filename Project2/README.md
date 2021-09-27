# Project 2

In this project we use the Jacobi method to solve a eigenvalue problem. This eigenvalue problem is a discretized solution of the buckling beam equation.

## The Code
The code can be found [here](https://github.com/laila503/fys3150/tree/main/Project2/src). The code has three files:

- [main.cpp](https://github.com/laila503/fys3150/blob/main/Project2/src/main.cpp) which calles all the functions
- [tridiagonal.cpp](https://github.com/laila503/fys3150/blob/main/Project2/src/tridiagonal.cpp) which holds functions for creating tridiagonal matrices, and finding the analytical eigenvalues and -vectors.
- [eigensolver.cpp](https://github.com/laila503/fys3150/blob/main/Project2/src/eigensolver.cpp) which contains functions for solving the eigenvalue system using Jacobi rotation.

To compile and run the code run the [makefile](https://github.com/laila503/fys3150/blob/main/Project2/src/makefile) using the command line 

```
make
```

## The Report
The report can be found [here](https://github.com/laila503/fys3150/blob/main/Project2/report/Project2_ComPhys_Andersland.pdf).