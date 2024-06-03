/*
Численно найти сумму функционального ряда (k=1, infty)(-1)**k / (sin(k * x) + 19 + k**2) с точностью 10^-6
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функциональный ряд
double calculateTerm(int k, double x) {
    return pow(-1, k) / (sin(k * x) + 19 + pow(k, 2));
}

// Функция для вычисления суммы ряда с заданной точностью
double calculateSum(double x, double tolerance) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;

    do {
        term = calculateTerm(k, x);// Вычисляем очередной член ряда
        sum += term;//приибавляем 
        k++; // к следующему
    } while (std::abs(term) >= tolerance);//остановка при достижении точности

    return sum;
}

int main() {
    double tolerance = 1e-6; // Устанавливаем требуемую точность
    double x = 5.0; // Устанавливаем значение x
    double result = calculateSum(x, tolerance); // Вычисляем сумму функционального ряда

    cout << "Ряд (k=1, infty)(-1)**k / (sin(k * x) + 19 + k**2)"<< endl;
     cout << "Сумма функционального ряда с точностью 10^-6 при x = " << x << ":" << std::endl;
     cout << "Sum = "<< fixed << setprecision(12) << result << endl;
    
    return 0;
}