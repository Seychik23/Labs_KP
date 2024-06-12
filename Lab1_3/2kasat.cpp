// Метод Ньютона(касательных)
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

// Функция, возвращающая значение функции в точке x
complex<double> func(complex<double> x) {
    return exp(-x) - sqrt(x - 1.0);
}

// Производная функции
complex<double> derivative_func(complex<double> x) {
    return -exp(-x) - 1.0 / (2.0 * sqrt(x - 1.0));
}

// Метод Ньютона для нахождения корня уравнения
complex<double> newton_method(complex<double> x0, double eps) {
    complex<double> x_prev = x0;
    complex<double> x_curr = x_prev - func(x_prev) / derivative_func(x_prev);

    // Итерационный процесс до достижения необходимой точности
    while (abs(x_curr - x_prev) > eps) {
        x_prev = x_curr;
        x_curr = x_prev - func(x_prev) / derivative_func(x_prev);
    }

    return x_curr;
}

int main() {
    complex<double> initial_guess = 2.0;
    double epsilon = 1e-6;

    complex<double> root = newton_method(initial_guess, epsilon);

    cout << "Численный корень уравнения: " << root << endl;

    return 0;
}
