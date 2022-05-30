#include <bits/stdc++.h>
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "simpson.hpp"
#include <locale.h>

using namespace std;
using namespace std::chrono;

double a,b;
int n;

int main () {
    setlocale(LC_ALL, "rus");
    cout << "Параллельное интегрирование функции при помощи OpenMP " << endl
         << "Введите нижнюю границу интегрирования:"; cin >> a;
    cout << "Введите верхнюю границу интегрирования:"; cin >> b;

    while (a > b ) {
        cout << "\nНижняя граница должна быть меньше верхней!\n"
             << "Введите нижнюю границу ещё раз:"; cin >> a;
        cout << "Введите верхнюю границу ещё раз:"; cin >> b;
    }

    cout << "Введите количество интервалов:"; cin >> n;
    while (n <= 0) {
        cout << "\nКол-во интервалов не может быть меньше или равно 0\n"
             << "Введите количество интервалов ещё раз:"; cin >> n;
    }

    cout << endl;

    double right = rectangle_right(a, b, n);
    cout << "Метод правых прямоугольников = " << right << endl;
    double middle = rectangle_middle(a, b, n);
    cout << "Метод средних прямоугольников = " << middle << endl;
    double left = rectangle_left(a, b, n);
    cout << "Метод левых прямоугольников = " << left << endl;
    double trap = trapeze(a, b, n);
    cout << "Метод трапеций = " << trap << endl;
    double simp = simpson(a,b,n);
    cout << "Метод Симпсона (метод парабол) = " << simp << endl << endl;

    system("pause");
    return 0;
}
