#include <armadillo> 
#include <math.h>
#include <assert.h>

#pragma once

double max_offdiag_symmetric(const arma::mat& A, int& k, int &l);
void test_code_max();
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l);
void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged);
