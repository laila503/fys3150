
#include <iostream> //Is this neccessary here?
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>      // setprecision

using namespace std;

double u(double x); //Declaration

//argc is int and stores number of command-line arguments passed by the user including the name of the program.

int main(int argc, char const *argv[]) {



    // Problem 2
    int N_exact = 100;
    double s = 0;
    double x = 0;
    double res = 0;
    vector<double> u_list;
    vector<double> x_list;
    ofstream myfile;
    myfile.open ("exact_solution.dat");
    for (int i = 0; i <= N_exact; i++){
        x = double(i)/double(N_exact);
        res = u(x);
        x_list.push_back(x); //Append the value x to x_list.
        u_list.push_back(res);
        myfile <<setprecision(4)  << x_list[i] << " " << u_list[i] << endl;
        }
    myfile.close();

    //Problem 7
    int N = 100;
    double h = 1.0/double(N);
    vector<double> a_list;
    vector<double> b_list;
    vector<double> c_list;
    vector<double> g_list;
    
    for (int i = 0; i < N; i++){
        a_list.push_back(-1);
        b_list.push_back(2);
        c_list.push_back(-1);

        g_list.push_back(100*exp(-10*(double(i)/double(N)))*h*h);
    }
    
    vector<double> b_tilde;
    vector<double> g_tilde;
    b_tilde.push_back(b_list[0]);
    g_tilde.push_back(g_list[0]);
    //Forward pass
    for (int i = 1; i < N; i++){
        b_tilde.push_back(b_list[i] - (a_list[i])/(b_tilde[i-1]) *c_list[i-1]);
        g_tilde.push_back(g_list[i] - (a_list[i])/(b_tilde[i-1]) *g_tilde[i-1]);
    }

    vector<double> v_tilde (N);
    v_tilde[N-1] = (g_tilde[N-1])/(b_tilde[N-1]);  
    //Backwards pass
    for (int i = N-2; i >= 0; i--){
        v_tilde[i] = (g_tilde[i] - c_list[i] * v_tilde[i+1])/(b_tilde[i]);
    }

    myfile.open ("solution.dat");
    for (int i = 0; i <= N; i++){
        x = double(i)/double(N);
        myfile <<setprecision(5)  << x << " " << v_tilde[i] << endl;
        }
    myfile.close();
    return 0;
}

double u(double x){
    //Provide definition of function here:
    return 1-(1-exp(-10))*x - exp(-10*x);
}
