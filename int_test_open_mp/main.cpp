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
    cout << "������������ �������������� ������� ��� ������ OpenMP " << endl
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
    cout << "����� ������ ��������������� = " << right << endl;
    double middle = rectangle_middle(a, b, n);
    cout << "����� ������� ��������������� = " << middle << endl;
    double left = rectangle_left(a, b, n);
    cout << "����� ����� ��������������� = " << left << endl;
    double trap = trapeze(a, b, n);
    cout << "����� �������� = " << trap << endl;
    double simp = simpson(a,b,n);
    cout << "����� �������� (����� �������) = " << simp << endl << endl;

    system("pause");
    return 0;
}
