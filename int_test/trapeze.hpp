#include "help.hpp"
using namespace std::chrono;

double trapeze(double a, double b, int n){
    double h = (b-a)/n;
    double sum = (f(a) + f(b))/2;

    auto start = steady_clock::now();
    for(int i = 1; i < n-1; i++) {
        sum += f(a + i*h);
    }
    auto exc = duration_cast<milliseconds>(steady_clock::now() - start);
    std::cout << "Time = " << exc.count() << " ms" << std::endl;


    return h*sum;
}
