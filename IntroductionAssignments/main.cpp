#include <iostream>
using namespace std;

double f(double x); //Declaration

int main(int argc, char const *argv[]) {
    double x = 2;
    double res = f(x); //Should return 2*2 = 4.
    std::cout << res << endl;
    return 0;
}

double f(double x){
    //Provide definition of function here:
    return x*x;
}
