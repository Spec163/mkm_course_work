#include "rectangle.hpp"
#include "trapeze.hpp"
#include "simpson.hpp"
#include <locale.h>

using namespace std;

double a,b;
int n;

int main () {
    setlocale(LC_ALL, "rus");
    cout << "���������������� �������������� ������� " << endl
         << "������� ������ ������� ��������������:"; cin >> a;
    cout << "������� ������� ������� ��������������:"; cin >> b;

    while (a > b ) {
        cout << "\n������ ������� ������ ���� ������ �������!\n"
             << "������� ������ ������� ��� ���:"; cin >> a;
        cout << "������� ������� ������� ��� ���:"; cin >> b;
    }

    cout << "������� ���������� ����������:"; cin >> n;
    while (n <= 0) {
        cout << "\n���-�� ���������� �� ����� ���� ������ ��� ����� 0\n"
             << "������� ���������� ���������� ��� ���:"; cin >> n;
    }

    cout << endl;

    double right = rectangle_right(a, b, n);
    cout << "����� ������ ��������������� = " << setprecision(10) << right << endl;
    double middle = rectangle_middle(a, b, n);
    cout << "����� ������� ��������������� = " << setprecision(10) << middle << endl;
    double left = rectangle_left(a, b, n);
    cout << "����� ����� ��������������� = " << setprecision(10) << left << endl;
    double trap = trapeze(a, b, n);
    cout << "����� �������� = " << setprecision(10) << trap << endl;
    double simp = simpson(a,b,n);
    cout << "����� �������� (����� �������) = " << setprecision(10) << simp << endl << endl;

    system("pause");
    return 0;
}
