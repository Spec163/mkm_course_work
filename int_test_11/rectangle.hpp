#include "help.hpp"

using namespace std;
using namespace std::chrono;

void thread_ih(double a, double h, double start, double end, double &sum){
    for (int i = start; i <= end; ++i) {
        sum += f(a + i*h);
    }
}

void thread_ih2(double a, double h, double start, double end, double &sum){
    for (int i = start; i <= end; ++i) {
        sum += f(a + i*h + h/2);
    }
}

double rectangle_right(double a, double b, int n){
    int range = n / 4;
    int tail = n % 4;
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double h = (b-a)/n;
    double sum = 0;

    thread t1(thread_ih, a, h, 1, range, ref(sum1));
    thread t2(thread_ih, a, h, 1+range, range*2, ref(sum2));
    thread t3(thread_ih, a, h, 1+range*2, range*3, ref(sum3));
    thread t4(thread_ih, a, h, 1+range*3, range*4+tail-1, ref(sum4));
    auto start = steady_clock::now();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    sum += sum1 + sum2 + sum3 + sum4;

    return h*sum;
}

double rectangle_middle(double a, double b, int n){
    int range = (n-1) / 4;
    int tail = (n-1) % 4;
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double h = (b-a)/n;
    double sum = 0;

    thread t1(thread_ih2, a, h, 0, range, ref(sum1));
    thread t2(thread_ih2, a, h, 1+range, range*2, ref(sum2));
    thread t3(thread_ih2, a, h, 1+range*2, range*3, ref(sum3));
    thread t4(thread_ih2, a, h, 1+range*3, range*4+tail-1, ref(sum4));
    auto start = steady_clock::now();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    sum += sum1 + sum2 + sum3 + sum4;

    return h*sum;
}

double rectangle_left(double a, double b, int n){
    int range = (n-1) / 4;
    int tail = (n-1) % 4;
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    double h = (b-a)/n;
    double sum = 0;

    thread t1(thread_ih, a, h, 0, range, ref(sum1));
    thread t2(thread_ih, a, h, 1+range, range*2, ref(sum2));
    thread t3(thread_ih, a, h, 1+range*2, range*3, ref(sum3));
    thread t4(thread_ih, a, h, 1+range*3, range*4+tail-1, ref(sum4));
    auto start = steady_clock::now();
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    auto end = steady_clock::now();
    auto exc = duration_cast<milliseconds>(end - start);
    cout << "Time = " << exc.count() << " ms" << endl;

    sum += sum1 + sum2 + sum3 + sum4;

    return h*sum;
}