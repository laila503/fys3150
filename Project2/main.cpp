
#include <iostream> 
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <math.h>       //log10 
#include <stdlib.h>     //abs
#include <time.h> 
#include <chrono>   
#include <armadillo> 

#include "eigensolver.h"
#include "tridiagonal.h"

void solve_and_save_system(int n);
void find_and_save_analytical(int n);



//Code of the main function:

int main() {
  //Creating a nxn tridiagonal symmetric matrix:
    int n = 6;
    double h = 1.0/float(n);
    double a = -1.0/(h*h);
    double d = 2.0/(h*h);
    double e = -1.0/(h*h);
    arma::mat A = create_tridiagonal(n, a, d, e); 
    //std::cout << A << std::endl;

  //Calculation of eigenvalues and eigenvectors with armadillo
    arma::vec eigval;
    arma::mat eigvec;
    eig_sym(eigval, eigvec, A);
    //std::cout << eigvec << std::endl;
    //std::cout << eigval << std::endl;

  //Analytical calculation of eigenvalues and eigenvectors:
    arma::vec analytical_eigval = find_analytical_eigval(n, a, d);
    arma::vec analytical_eigvec; 

    //std::cout << "Eigen values: \n"  << analytical_eigval << std::endl;
    for (int i = 1; i <= n; i++){
      analytical_eigvec = find_analytical_eigvec(n,i);
      //std::cout << "Eigenvector " << i << ": \n" << analytical_eigvec << std::endl;
      
    } 
  //Calculate the maximum value of a symetric matrix:
  /*
    int k;
    int l;
    double max_value = max_offdiag_symmetric(A, k, l);
    std::cout << max_value << std::endl;
    */

  //Test funtion that checks if max_offdiag_symmetric works propperly:
    test_code_max();


  //Code implementation of Jacobi's eigensolver:
  arma::vec eigenvalues = arma::vec(n);
  arma::mat eigenvectors = arma::mat(n,n);

  double eps = 1e-3;
  int maxiter = n*n;
  int iterations;
  bool converged;

  for(int N = 2; N < 70; N++){
    maxiter = N*N*N;
    A = create_tridiagonal(N, a, d, e);
    //A = arma::mat(N, N).randn(); 
    eigenvalues = arma::vec(N);
    eigenvectors = arma::mat(N,N);

    //std::cout << "For N = " << N << " With maxiter = " << maxiter <<   std::endl;
    jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
    std::cout << N << " " << iterations << std::endl;

    //std::cout << "From Jacobi \n" << eigenvalues << std::endl;
  }


  // Problem 7

  n = 10;
  solve_and_save_system(n);
  find_and_save_analytical(n);

  n = 100;
  solve_and_save_system(n);
  find_and_save_analytical(n);
  

  return 0;
}


void find_and_save_analytical(int n){
  double h = 1.0/float(n);
  double a = -1.0/(h*h);
  double d = 2.0/(h*h);
  double e = -1.0/(h*h);
  arma::vec analytical_eigval = find_analytical_eigval(n, a, d);
  arma::mat analytical_eigvecs = arma::mat(n,n);  

  

  for (int i = 1; i <= n; i++){
    analytical_eigvecs.col(i-1) = find_analytical_eigvec(n,i);
  } 

  analytical_eigvecs.save("analytical_eigenvector_" + std::to_string(n) + ".dat", arma::raw_ascii);    
  analytical_eigval.save("analytical_eigenvalues_" + std::to_string(n) + ".dat", arma::raw_ascii);
}


void solve_and_save_system(int n){
  arma::mat A = create_tridiagonal(n);
  arma::vec eigenvalues = arma::vec(n);
  arma::mat eigenvectors = arma::mat(n,n);

  double eps = 1e-3;
  int maxiter = n*n*n;
  int iterations;
  bool converged;

  jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);

  eigenvalues.save("eigenvalues_" + std::to_string(n) + ".dat", arma::raw_ascii);
  eigenvectors.save("eigenvectors_" + std::to_string(n) + ".dat", arma::raw_ascii);

}




