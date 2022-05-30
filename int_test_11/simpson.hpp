#include "help.hpp"

using namespace std;
using namespace std::chrono;

void thread_simp(double a, double h, int start, int end, double &S1, double &S2){
    for (int i = start; i <= end; ++i) {
        S1 += f(a+2*h*(i+1));
        S2 += f(a+2*h*(i+1));
    }
}

double simpson(double a, double b, int n){
    int range = (n-1) / 4;
    int tail = (n-1) % 4;
    double s11 = 0, s12 = 0, s13 = 0, s14 = 0;
    double s21 = 0, s22 = 0, s23 = 0, s24 = 0;
    double h = (b-a)/(2*n);
    double S1 = 0;
    double S2 = 0;
    double sum = f(a) + f(b);

    thread t1(thread_simp, a, h, 1, range, ref(s11), ref(s21));
    thread t2(thread_simp, a, h, 1+range, range*2, ref(s12), ref(s22));
    thread t3(thread_simp, a, h, 1+range*2, range*3, ref(s13), ref(s23));
    thread t4(thread_simp, a, h, 1+range*3, range*4+tail-1, ref(s14), ref(s24));
    auto start = steady_clock::now();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end-start);
    cout << "Time = " << exc.count() << " ms" << endl;
    S1 = s11 + s12 + s13 + s14;
    S2 = s21 + s22 + s23 + s24;
    return h/3*(sum + 4*S1 + 2*S2);
}

