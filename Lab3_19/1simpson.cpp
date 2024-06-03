// Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6. Метод Симпсона с заданием точности
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

typedef double(*pointFunc)(double);
double f(double x) {
  return pow(x, 4) * 1 / (19 + pow(x, 2)); //Функция для интегрирования
}
double simpson_integral(pointFunc f, double a, double b, int n) {
  const double h = (b-a)/n;
  double k1 = 0, k2 = 0;
  for(int i = 1; i < n; i += 2) {
    k1 += f(a + i*h);
    k2 += f(a + (i+1)*h);
  }
  return h/3*(f(a) + 4*k1 + 2*k2);
}
int main() {
  setlocale(LC_ALL, "rus");
  double a, b, eps;
  double s1, s;
  int n = 1; //начальное число шагов
  cout << "Введите левую границу интегрирования a=";
  cin >> a;
  cout << "\nВведите правую границу интегрирования b=";
  cin >> b;
  cout << "\nВведите требуемую точность eps = ";
  cin >> eps;
  s1 = simpson_integral(f, a, b, n); //первое приближение для интеграла
  do {
    s = s1;     //второе приближение
    n = 2 * n;  //увеличение числа шагов в два раза,
                //т.е. уменьшение значения шага в два раза
    s1 = simpson_integral(f, a, b, n);
  }
  while (fabs(s1 - s) > eps);  //сравнение приближений с заданной точностью
  cout << "\nЗначение интеграла I = " <<fixed<<setprecision(12)<< s1 << endl;
cout << "\nКоличество разбиений n = " << n << endl;
}
