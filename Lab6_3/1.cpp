//  Метод покоординатного спуска для поиска оптимума функции
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

// Функция f(x) 
double objective(double x1, double x2, double x3) {
    return exp(pow(x1, 2) + pow(x2, 2)) + log(4 + pow(x2, 2) + 2 * pow(x3, 2));
}

int main() {
    // Инициализация начальных значений
    double x1 = 0.1, x2 = 0.1, x3 = 0.1;

    // Итерации и шаг оптимизации
    const int iterations = 1000;
    const double step_size = 0.0001;

    // Векторы для хранения значений координат и функции потерь
    vector<double> x1_list, x2_list, x3_list, loss_list;

    for (int i = 0; i < iterations; ++i) {
        x1_list.push_back(x1);
        x2_list.push_back(x2);
        x3_list.push_back(x3);
        loss_list.push_back(objective(x1, x2, x3));

        // Производные
        double grad_x1 = 2 * x1 * exp(pow(x1, 2) + pow(x2, 2));
        double grad_x2 = 2 * x2 * exp(pow(x1, 2) + pow(x2, 2)) + 2 * x2 / (4 + pow(x2, 2) + 2 * pow(x3, 2));
        double grad_x3 = 4 * x3 / (4 + pow(x2, 2) + 2 * pow(x3, 2));
        
        // Обновление x1, x2, x3
        x1 = x1 - step_size * grad_x1;
        x2 = x2 - step_size * grad_x2;
        x3 = x3 - step_size * grad_x3;

        // Ограничение значений, чтобы избежать переполнения
        x1 = max(min(x1, 100.0), -100.0);
        x2 = max(min(x2, 100.0), -100.0);
        x3 = max(min(x3, 100.0), -100.0);
    }

    // Вывод оптимальных значений и максимальное значение функции
    double optimal_x1 = x1_list.back();
    double optimal_x2 = x2_list.back();
    double optimal_x3 = x3_list.back();
    cout << "Optimal values: x1 = " << optimal_x1 << ", x2 = " << optimal_x2 << ", x3 = " << optimal_x3 << endl;
    cout << "Optimal f: " << objective(optimal_x1, optimal_x2, optimal_x3) << endl;

    return 0;
}
