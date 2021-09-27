#include "eigensolver.h"

double max_offdiag_symmetric(const arma::mat& A, int& k, int &l){
  double tmp_max = -100000;
  int max_i, max_j;
  int n = A.n_cols;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j) {
        if (fabs(A(i,j))>tmp_max){
          tmp_max = fabs(A(i,j));
          max_i = i;
          max_j = j;
        }
      } 
    }
  }
  k=max_i;
  l=max_j;
  return tmp_max;
}

void test_code_max(){
  arma::mat A = "1 0 0 0.5; 0 1 -0.7 0; 0 -0.7 1 0; 0.5 0 0 1;";

  double correct_max = 0.7;

  int k;
  int l;
  double max_value= max_offdiag_symmetric(A, k, l);

  if (max_value != correct_max){
    std::cout << "Got wrong max value: " << max_value << ", correct value: " << correct_max << std::endl;
  }
  assert(max_value==correct_max);

}

// The code for using the Jacobi method is heavyly inspired by the lectur book:
// Computational Physics by Hjorth-Jensen, Morten.

// Performs a single Jacobi rotation, to "rotate away"
// the off-diagonal element at A(k,l).
// - Assumes symmetric matrix, so we only consider k < l
// - Modifies the input matrices A and R
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l){
  double s, c;
  if ( A(k,l) != 0.0 ) {
    double t, tau;
    tau = (A(l,l) - A(k,k))/(2*A(k,l));
    if ( tau > 0 ) {
      t = 1.0/(tau + sqrt(1.0 + tau*tau));
    } else {
      t = -1.0/( -tau + sqrt(1.0 + tau*tau));
    }
  c = 1.0/sqrt(1+t*t);
  s = c*t;
  } else {
      c = 1.0;
      s = 0.0;
  }

  double a_kk, a_ll, a_ik, a_il, r_ik, r_il;
  a_kk = A(k,k);
  a_ll = A(l,l);
  // changing the matrix elements with indices k and l
  A(k,k) = c*c*a_kk - 2.0*c*s*A(k,l) + s*s*a_ll;
  A(l,l) = s*s*a_kk + 2.0*c*s*A(k,l) + c*c*a_ll;
  A(k,l) = 0.0; // hard-coding of the zeros
  A(l,k) = 0.0;

  int n = A.n_cols;
  // and then we change the remaining elements
  for ( int i = 0; i < n; i++ ) {
    if ( i != k && i != l ) {
      a_ik = A(i,k);
      a_il = A(i,l);
      A(i,k) = c*a_ik - s*a_il;
      A(k,i) = A(i,k);
      A(i,l) = c*a_il + s*a_ik;
      A(l,i) = A(i,l);
    }
    // Finally, we compute the new eigenvectors
    r_ik = R(i,k);
    r_il = R(i,l);
    R(i,k) = c*r_ik - s*r_il;
    R(i,l) = c*r_il + s*r_ik;
  }
  return;
}

void jacobi_eigensolver(arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, const int maxiter, int& iterations, bool& converged){


    int n = A.n_cols;
    // Setting up the eigenvector matrix
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
        if ( i == j ) {
            eigenvectors(i,j) = 1.0;
        } else {
            eigenvectors(i,j) = 0.0;
        }
        }
    }
    int k, l;
    double epsilon = 1.0e-8;
    iterations = 0;
    double max_offdiag = max_offdiag_symmetric( A, k, l);
    while ( fabs(max_offdiag) > epsilon && (double) iterations < maxiter ) {
        max_offdiag = max_offdiag_symmetric( A, k, l);
        jacobi_rotate ( A, eigenvectors, k, l);
        iterations++;
    }
    //std::cout << "Number of iterations: " << iterations << "\n";

    eigenvalues = A.diag();
    return;
    

}