// # Метод Зейделя 4 на 4 с правой частью
#include <iostream>
#include <cmath>

using namespace std;

const int n = 4;

// Метод Зейделя для решения систем линейных уравнений Ax = b
double* seidel(double A[n][n], double b[n], double x0[n], double epsilon, int max_iterations) {
    double* x = new double[n];
    for (int i = 0; i < n; i++) {
        x[i] = x0[i];
    }

    // Итерационный процесс
    for (int iteration = 0; iteration < max_iterations; iteration++) {
        double* x_new = new double[n];
        for (int i = 0; i < n; i++) {
            double sum1 = 0.0;
            double sum2 = 0.0;
            for (int j = 0; j < i; j++) {
                sum1 += A[i][j] * x_new[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum2 += A[i][j] * x[j];
            }
            x_new[i] = (b[i] - sum1 - sum2) / A[i][i];
        }

        // Проверка на достижение необходимой точности
        bool close_enough = true;
        for (int i = 0; i < n; i++) {
            if (std::abs(x[i] - x_new[i]) > epsilon) {
                close_enough = false;
                break;
            }
        }

        // Если достигнута необходимая точность, возвращаем результат
        if (close_enough) {
            delete[] x;
            x = x_new;
            return x;
        }

        delete[] x;
        x = x_new;
    }

    return x;
}

int main() {
    double A[n][n] = {
        {-18, 9, -1, -8},
        {6, 22, 9, 0},
        {-4, 2, -16, 9},
        {1, 6, -1, -14}
    };
    double b[n] = {-60, -109, -103, -33};
    double x0[n] = {0.0, 0.0, 0.0, 0.0};
    double epsilon = 1e-2; // Точность
    int max_iterations = 100; // Число итераций

    double* x = seidel(A, b, x0, epsilon, max_iterations);
    cout << "Solution: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    delete[] x;

    return 0;
}
