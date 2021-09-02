
#include <iostream> //Is this neccessary here?
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>      // std::setprecision

double u(double x); //Declaration

//argc is int and stores number of command-line arguments passed by the user including the name of the program.

int main(int argc, char const *argv[]) {
    int N = 10;
    double s = 0;
    double x = 0;
    double res = 0;
    std::vector<double> u_list;
    std::vector<double> x_list;
    std::ofstream myfile;
    myfile.open ("exact_solution.dat");
    //myfile << " x  |  u(x) \n";
    //myfile << "------------\n";
    for (int i = 0; i <= N; i++){
        x = double(i)/double(N);
        res = u(x);
        x_list.push_back(x); //Append the value x to x_list.
        u_list.push_back(res);
        myfile <<std::setprecision(4)  << x_list[i] << " " << u_list[i] << std::endl;
        std::cout << x << " " << i << " " << x_list[i] << std::endl;
        }
    std::cout <<  x_list[0] << std::endl;
    std::cout << "Hello, World!\n";


    myfile.close();
    return 0;
}

double u(double x){
    //Provide definition of function here:
    return 1-(1-exp(-10))*x - exp(-10*x);
}
