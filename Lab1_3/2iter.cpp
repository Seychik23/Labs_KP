// Метод простых итераций
#include <iostream>
#include <cmath>

// Функция, корни которой требуется найти
double func(double x) {
    return exp(-x) - sqrt(x - 1);
}

// Итерационная функция для метода простых итераций
double g(double x) {
    return exp(-x);
}

// Функция метода простых итераций
double simple_iteration(double x0, double eps) {
    double x1 = g(x0);
    while (abs(x1 - x0) >= eps) {
        x0 = x1;
        x1 = g(x0);
    }
    return x1;
}

int main() {
    // x0 и точность
    double x0 = 0.0;
    double epsilon = 1e-6;

    double root = simple_iteration(x0, epsilon);
    std::cout << "Численный корень уравнения: " << root << std::endl;

    return 0;
}
