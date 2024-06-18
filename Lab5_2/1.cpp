// Найти приближающие многочлены первой и второй степени (МНК для полинома 1 и 2 степени)
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

// Функция для расчета приближающего многочлена второй степени (МНК)
    vector<double> quadraticApproximation(vector<double> x, vector<double> y) {
    int n = x.size();

    // Расчет коэффициентов МНК для полинома 2 степени
    double sum_x = accumulate(x.begin(), x.end(), 0.0);
    double sum_y = accumulate(y.begin(), y.end(), 0.0);
    double sum_x2 = inner_product(x.begin(), x.end(), x.begin(), 0.0);
    double sum_x3 = inner_product(x.begin(), x.end(), x.begin(), 0.0, std::plus<double>(), [](double i){ return pow(i, 2); });
    double sum_x4 = inner_product(x.begin(), x.end(), x.begin(), 0.0, std::plus<double>(), [](double i){ return pow(i, 3); });
    double sum_xy = inner_product(x.begin(), x.end(), y.begin(), 0.0);
    double sum_x2y = inner_product(x.begin(), x.end(), y.begin(), 0.0, std::plus<double>(), [](double i, double j){ return pow(i, 2) * j; });

    double determinant = n * sum_x2 * sum_x4 - n * sum_x3 * sum_x3 - sum_x4 * sum_x * sum_x + 2 * sum_x3 * sum_x2 - sum_x2 * sum_x2;

    double A = (n * sum_x2y * sum_x2 + sum_y * sum_x3 * sum_x - sum_x2 * sum_x * sum_y) / determinant;
    double B = (n * sum_x2 * sum_y + sum_x * sum_x2y * sum_x - sum_x3 * sum_y) / determinant;
    double C = (sum_x2 * sum_x2y + n * sum_x3 * sum_y - sum_x2 * sum_y) / determinant;

    return {A, B, C};
}

int main() {
    vector<double> x = {-1.0, 0.0, 1.0, 2.0, 3.0, 4.0};
    vector<double> y = {-0.5, 0.0, 0.5, 0.86603, 1.0, 0.86603};

    vector<double> beta_qu = {0.0, 0.0, 0.0};

    beta_qu = quadraticApproximation(x, y);
    cout << "y = " << beta_qu[0] << " + " << beta_qu[1] << " * x + " << beta_qu[2] << " * x^2" << endl;

    return 0;
}
