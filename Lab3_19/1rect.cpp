//Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6.Метод прямоугольников.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 4) / (19 + pow(x, 2)); // Функция для интегрирования
}

int main() {
    setlocale(LC_ALL, " rus");
    cout <<"Метод прямоугольников"<<endl;
    cout << "Интегрируемая функция:(1,2) f(x) = x^4 * (19 + x^2)^(-1)"<<endl;
    double a = 1.0;
    double b = 2.0;
    double h;
    int n_point = 1;
    
    double sum = 0.0;
    double prev_sum = 0.0;
    const double desired_accuracy = 1e-6; // Задаем точность
    int max_iterations = 1000;
    int count = 0;

    do {
        prev_sum = sum;
        sum = 0.0;
        h = (b - a) / n_point;

        for (double x = a; x < b; x += h) {
            sum += f(x + h / 2); // Считаем значения в серединах прямоугольников
        }

        sum *= h;
        n_point *= 2;
        count++;

    } while (abs(prev_sum - sum) >= desired_accuracy && count < max_iterations);

    cout << "Значение определенного интеграла с точностью 10^-6: " << endl;
    cout << "I = " << fixed << setprecision(12) << sum << endl;

    return 0;
}
