// Метод наискорейшего спуска для поиска оптимума функции
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <iomanip>

using namespace std;

// Функция f(w1, w2) 
double objective(double w1, double w2) {
    return pow(w1, 2) + exp(pow(w1, 2) + pow(w2, 2)) + 4*w1 + 3*w2;
}

// Частная производная функции f по переменной w1
double partial_1(double w1, double w2) {
    return 2*w1 + 2*w1*exp(pow(w1, 2) + pow(w2, 2)) + 4;
}

// Частная производная функции f по переменной w2
double partial_2(double w1, double w2) {
    return 2*w2*exp(pow(w1, 2) + pow(w2, 2)) + 3;
}

int main() {
    double w1 = 3, w2 = 4;
    int iter = 100;
    double learning_rate = 0.05;

    vector<double> w1_list, w2_list, l_list;

    for (int i = 0; i < iter; ++i) {
        w1_list.push_back(w1);
        w2_list.push_back(w2);
        l_list.push_back(objective(w1, w2));

        double par_1 = partial_1(w1, w2);
        double par_2 = partial_2(w1, w2);

        // Ограничение значений, чтобы избежать переполнения
        if (!isfinite(par_1) || !isfinite(par_2)) {
            cout << "Gradient overflow at iteration " << i << endl;
            break;
        }

        w1 = w1 - learning_rate * par_1;
        w2 = w2 - learning_rate * par_2;

        // Ограничение значений, чтобы избежать переполнения
        if (!isfinite(w1) || !isfinite(w2)) {
            cout << "Weight overflow at iteration " << i << endl;
            break;
        }
    }

    cout << "Optimal weights: " << w1 << ", " << w2 << endl;
    cout << "Optimal value: " << objective(w1, w2) << endl;

    return 0;
}
