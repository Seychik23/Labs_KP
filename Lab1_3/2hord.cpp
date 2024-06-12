//Метод хорд (секущих)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Функция, вычисляющая значение функции в точке x
double func(double x)
{
    return exp(-x) - sqrt(x - 1);
}

// Метод хорд (метод секущих) для нахождения корня уравнения f(x) = 0
double find(double x0, double x1, double eps)
{
    int iter = 0;
    double x_next = 0;

    do
    {
        // Вычисление следующей аппроксимации корня по методу хорд
        x_next = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));
        
        // Проверка на достижение необходимой точности
        if (fabs(func(x_next)) < eps) {
            break;
        }
        
        // Обновление интервала, содержащего корень
        if (func(x_next) * func(x0) < 0) {
            x1 = x_next;
        } else {
            x0 = x_next;
        }

        iter++;
    } while (iter < 20000); // Ограничение на количество итераций для избежания зацикливания

    cout << "\nNumber of iterations is " << iter  << ". " << endl;
    return x_next;
}

int main()
{
    double x0, x1, x, eps = 1e-6; // Начальные приближения, корень и требуемая точность

    cout << "a = ";
    cin >> x0;

    cout << "b = ";
    cin >> x1;

    cout << "eps = " << eps;

    // Поиск корня уравнения f(x) = 0 с помощью метода хорд
    x = find(x0, x1, eps);

    // Вывод найденного корня и значения функции в этой точке
    cout << "Root x = " << fixed << setprecision(16) << x << endl;
    cout << "Function value f(x) = " << func(x) << endl;

    return 0;
}
