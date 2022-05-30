#include "help.hpp"
using namespace std;

double rectangle_right(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = chrono::steady_clock::now();
    for(int i=1; i <= n; i++){
        sum += f(a + i*h)*h;
    }
    auto exc = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
    std::cout << "Time = " << exc.count() << " ms" << std::endl;

    return sum;
}

double rectangle_middle(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = chrono::steady_clock::now();
    for(int i=0; i < n-1; i++){
        sum += f(a + i*h + h/2);
    }
    auto exc = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
    std::cout << "Time = " << exc.count() << " ms" << std::endl;

    return h*sum;
}

double rectangle_left(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = chrono::steady_clock::now();
    for(int i=0; i <= n-1; i++){
        sum += f(a + i*h)*h;
    }
    auto exc = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
    std::cout << "Time = " << exc.count() << " ms" << std::endl;

    return sum;
}
