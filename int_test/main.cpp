#include "rectangle.hpp"
#include "trapeze.hpp"
#include "simpson.hpp"
#include <locale.h>

using namespace std;

double a,b;
int n;

int main () {
    setlocale(LC_ALL, "rus");
    cout << "Последовательное интегрирование функции " << endl
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
    cout << "Метод правых прямоугольников = " << setprecision(10) << right << endl;
    double middle = rectangle_middle(a, b, n);
    cout << "Метод средних прямоугольников = " << setprecision(10) << middle << endl;
    double left = rectangle_left(a, b, n);
    cout << "Метод левых прямоугольников = " << setprecision(10) << left << endl;
    double trap = trapeze(a, b, n);
    cout << "Метод трапеций = " << setprecision(10) << trap << endl;
    double simp = simpson(a,b,n);
    cout << "Метод Симпсона (метод парабол) = " << setprecision(10) << simp << endl << endl;

    system("pause");
    return 0;
}
