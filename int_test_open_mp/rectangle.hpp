#include "help.hpp"

using namespace std;
using namespace std::chrono;

double rectangle_right(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = steady_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for(int i=1; i < n; i++){
        sum += f(a + i*h);
    }
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    return h*sum;
}

double rectangle_middle(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = steady_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i < n-1; i++){
        sum += f(a + i*h + h/2);
    }
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    return h*sum;
}

double rectangle_left(double a, double b, int n){
    double h = (b-a)/n;
    double sum = 0;

    auto start = steady_clock::now();
    #pragma omp parallel for reduction(+:sum)
    for(int i=0; i < n-1; ++i){
        sum += f(a + i*h);
    }
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    return h*sum;
}