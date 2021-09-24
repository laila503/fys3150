
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

//Declaration:

arma::mat create_tridiagonal(int n, double a, double d, double e); 
arma::vec find_analytical_eigvec(int n, int i);
arma::vec find_analytical_eigval(int n, double a, double d);

const double PI = 3.14159265359;


//Code of the main function:

int main() {
  //Creating a nxn tridiagonal symmetric matrix:
    int n = 6;
    double h = 1.0/float(n);
    double a = -1.0/(h*h);
    double d = 2.0/(h*h);
    double e = -1.0/(h*h);
    arma::mat A = create_tridiagonal(n, a, d, e); 
    std::cout << A << std::endl;

  //Calculation of eigenvalues and eigenvectors with armadillo
    arma::vec eigval;
    arma::mat eigvec;
    eig_sym(eigval, eigvec, A);
    std::cout << eigvec << std::endl;
    std::cout << eigval << std::endl;

  //Analytical calculation of eigenvalues and eigenvectors:
    arma::vec analytical_eigval = find_analytical_eigval(n, a, d);
    arma::vec analytical_eigvec; //hvorfor?

    std::cout << "Eigen values: \n"  << analytical_eigval << std::endl;
    for (int i = 1; i <= n; i++){
      analytical_eigvec = find_analytical_eigvec(n,i);
      std::cout << "Eigenvector " << i << ": \n" << analytical_eigvec << std::endl;
      
    } 
  //Calculate the maximum value of a symetric matrix:
    int k;
    int l;
    double max_value = max_offdiag_symmetric(A, k, l);
    std::cout << max_value << std::endl;

  //Test funtion that checks if max_offdiag_symmetric works propperly:
    test_code_max();


  //Code implementation of Jacobi's eigensolver:
  arma::vec eigenvalues = arma::vec(n);
  arma::mat eigenvectors = arma::mat(n,n);

  double eps = 1e-6;
  int maxiter = n*n;
  int iterations;
  bool converged;
  std::cout << A << std::endl;
  jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);

  std::cout << "From Jacobi \n" << eigenvalues << std::endl;
  return 0;
}


//Code block:

//FROM EXAMPLE CODE SNIPPET: https://anderkve.github.io/FYS3150/book/projects/project2.html
// Create a tridiagonal matrix tridiag(a,d,e) of size n*n, 
arma::mat create_tridiagonal(int n, double a, double d, double e)
{
  // Start from identity matrix
  arma::mat A = arma::mat(n, n, arma::fill::eye);
  // Fill the first row (row index 0), e.g.
  A(0,0) = d;
  A(0,1) = e;
  // Loop that fills rows 2 to n-1 (row indices 1 to n-2)
  for (int i = 1; i <= n-2; i++){
    for (int j = 1; j <= n-2; j++){
      if (i==j){
        A(i,j)=d;          // - main diagonal:  vector d, lenght n
        A(i,j-1)=a;        // - lower diagonal: vector a, lenght n-1
        A(i,j+1)=e;        // - upper diagonal: vector e, lenght n-1
      }
    }
  }
  // Fill last row (row index n-1)
  A(n-1,n-2) = a;
  A(n-1,n-1) = d;  
  return A;
}

arma::vec find_analytical_eigvec(int n, int i){
  arma::vec eig = arma::vec(n);
  for (int j = 0; j < n; j++){
    eig[j] = sin(((j+1)*i*PI)/(n+1));
  }

  return -arma::normalise(eig);
}

arma::vec find_analytical_eigval(int n, double a, double d){
  arma::vec eig = arma::vec(n);
  for (int j = 0; j < n; j++){
    eig[j] = d + 2*a*cos((PI*(j+1))/(n+1));
  }
  return eig;
}

