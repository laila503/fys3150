#include "tridiagonal.h"

const double PI = 3.14159265359;

//Code block:
//FROM EXAMPLE CODE SNIPPET: https://anderkve.github.io/FYS3150/book/projects/project2.html
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

arma::mat create_tridiagonal(int n){
    double h = 1.0/float(n);
    double a = -1.0/(h*h);
    double d = 2.0/(h*h);
    double e = -1.0/(h*h);
    return create_tridiagonal(n, a, d, e); 
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