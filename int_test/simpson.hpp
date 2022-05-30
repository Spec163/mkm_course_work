#include "help.hpp"
using namespace std::chrono;

double simpson(double a, double b, int n){
    double h = (b-a)/(2*n);
    double S1 = 0;
    double S2 = 0;
    double sum = f(a) + f(b);

    auto start = steady_clock::now();
    for(int i = 1; i < n-1; ++i) {
        S1 += f(a+2*h*(i+1));
        S2 += f(a+2*i*h);
    }
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end-start);
    std::cout << "Time = " << exc.count() << " ms" << std::endl;

    return h/3*(sum + 4*S1 + 2*S2);
}

