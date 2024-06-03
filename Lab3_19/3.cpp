/*
Численно найти сумму числового ряда (k=1, infty) 19.0 / (pow(2, k) - 1) + pow(-1, k - 1) / (2.0 * pow(3, k - 1)) 
с точностью 10^-6
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Числовой ряд
double calculateTerm(int k) {
    return 19.0 / (pow(2, k) - 1) + pow(-1, k - 1) / (2.0 * pow(3, k - 1)); // Числовой ряд
}

// Функция для вычисления суммы ряда с заданной точностью
double calculateSum(double tolerance) {
    double sum = 0.0;
    double term = 0.0;
    int k = 1;

    do {
        term = calculateTerm(k); // вычисляем член ряда
        sum += term; //прибавляем  к сумме
        k++; // к следующему
    } while (abs(term) >= tolerance); // 

    return sum;
}

int main() {
    double tolerance = 1e-6; // Задаем точность
    double result = calculateSum(tolerance);
    cout << "Ряд (k=1, infty) 19.0 / (pow(2, k) - 1) + pow(-1, k - 1) / (2.0 * pow(3, k - 1))"<<endl;
    cout << "Сумма функционального ряда с точностью 10^-6: " << endl;
    cout << "Sum = " << fixed << setprecision(12) << result << endl;

    return 0;
}
