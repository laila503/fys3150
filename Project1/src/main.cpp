
#include <iostream> 
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <math.h>       //log10 
#include <stdlib.h>     //abs
#include <time.h> 
#include <chrono>    

using namespace std;

double u(double x); //Declaration

//argc is int and stores number of command-line arguments passed by the user including the name of the program.

int main(int argc, char const *argv[]) {

    // Problem 2
    int N = 10000000;
    double s = 0;
    double x = 0;

    double res = 0;
    vector<double> u_list;
    vector<double> x_list;

    ofstream myfile;
    myfile.open ("exact_solution.dat");
    for (int i = 0; i <= N+1; i++){
        x = double(i)/double(N+1);
        res = u(x);
        x_list.push_back(x); //Append the value x to x_list.
        u_list.push_back(res);
        myfile <<setprecision(4)  << x_list[i] << " " << u_list[i] << endl;
        }
    myfile.close();

    //Problem 7
    double h = 1.0/double(N+1);
    vector<double> a_list (N+2);
    vector<double> b_list (N+2);
    vector<double> c_list (N+2);
    vector<double> g_list (N+2);
    
    for (int i = 0; i < N+1; i++){
        a_list[i] = -1;
        b_list[i] = 2;
        c_list[i] = -1;
        x = h*i;
        g_list[i]= 100*exp(-10*(x))*h*h;
    }
    

    // Timing starts
    auto t1 = std::chrono::high_resolution_clock::now();

    vector<double> b_tilde (N+2);
    vector<double> g_tilde (N+2);
    b_tilde[1] = b_list[1];
    g_tilde[1] = g_list[1];
    //Forward pass
    for (int i = 2; i < N+1; i++){
        b_tilde[i] = (b_list[i] - (a_list[i])/(b_tilde[i-1]) *c_list[i-1]);
        g_tilde[i] = (g_list[i] - (a_list[i])/(b_tilde[i-1]) *g_tilde[i-1]);
    }

    vector<double> v_list (N+2);
    v_list[N] = (g_tilde[N])/(b_tilde[N]);  
    //Backwards pass
    for (int i = N-1; i > 0; i--){
        v_list[i] = (g_tilde[i] - c_list[i] * v_list[i+1])/(b_tilde[i]);
    }

    v_list[N+1] = 0;

    // Timing ends
    auto t2 = std::chrono::high_resolution_clock::now();
    // Calculate the elapsed time.
    double duration_seconds = std::chrono::duration<double>(t2 - t1).count();
    //cout << "Time: " << duration_seconds << "s, for N= " << N << endl;
    cout << duration_seconds  << endl;
   
    myfile.open ("solution_" + to_string(N) + ".dat");
    for (int i = 0; i <= N+1; i++){
        x = double(i)/double(N+1);
        myfile <<setprecision(15)  << x << " " << v_list[i] << " " << u_list[i] << endl;
        }
    myfile.close();



    return 0;
}

double u(double x){
    //Provide definition of function here:
    return 1-(1-exp(-10))*x - exp(-10*x);
}
