// Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6. Метод трапеций.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 4)  / (19 + pow(x, 2)); // Функция для интегрирования
}

double integrate(double a, double b, double tolerance) {
    int n = 1;
    double h = (b - a) / n;
    double integral = 0.5 * (f(a) + f(b)); // Первое приближенное значение интеграла
    double integral_prev = 0;
    
    while (abs(integral - integral_prev) >= tolerance) {
        integral_prev = integral;
        double sum = 0;
        
        for (int i = 1; i <= n - 1; ++i) {
            sum += f(a + i * h);
        }
        
        integral = 0.5 * integral + h * sum;
        n *= 2;
        h = (b - a) / n;
    }
    
    return integral / 2;
}

int main() {
    double a = 1.0; // Пределы интегрирования 
    double b = 2.0;
    double tolerance = 1e-6; // Задаем точность

    double result = integrate(a, b, tolerance);
    
    cout << "Метод трапеций"<< endl;
    cout << "Интегрируемая функция:(1,2) f(x) = x^4 * (19 + x^2)^(-1)"<<endl;
    cout << "Значение определенного интеграла с точностью 10^-6: " << endl;
    cout << "I = " << fixed << setprecision(12) << result << endl;

    return 0;
}
