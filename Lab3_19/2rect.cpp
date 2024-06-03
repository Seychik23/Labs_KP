//Найти численно значение неопределенного интеграла exp(-2*x) * sin(19*x) с точностью до 10^-6.Метод прямоугольников.
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return exp(-2*x) * sin(19*x); // Функция для интегрирования
}

int main() {
    setlocale(LC_ALL, " rus");
    cout <<"Метод прямоугольников"<<endl;
    cout << "Интегрируемая функция: exp(-2*x) * sin(19*x)"<<endl;
    double a = 0.0;
    double b = 1.0;
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

    cout << "Значение неопределенного интеграла с точностью 10^-6: " << endl;
    cout << "I = " << fixed << setprecision(12) << sum << endl;

    return 0;
}
