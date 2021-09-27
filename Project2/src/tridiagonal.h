#include <armadillo> 
#include <math.h>

#pragma once

//Declaration:
arma::mat create_tridiagonal(int n, double a, double d, double e); 
arma::mat create_tridiagonal(int n);
arma::vec find_analytical_eigvec(int n, int i);
arma::vec find_analytical_eigval(int n, double a, double d);