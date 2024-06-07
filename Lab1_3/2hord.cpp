//Метод хорд (секущих)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(double x)
{
    return exp(-x) - sqrt(x - 1);
}

double find(double x0, double x1, double eps)
{
    int iter = 0;
    double x_next = 0;
    
    do
    {
        x_next = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));
        if (fabs(func(x_next)) < eps) {
            break;
        }
        
        if (func(x_next) * func(x0) < 0) {
            x1 = x_next;
        } else {
            x0 = x_next;
        }

        iter++;
    } while (iter < 20000);

    cout << "\nNumber of iterations is " << iter  << ". " << endl;
    return x_next;
}

int main()
{
    double x0, x1, x, eps;

    cout << "a = ";
    cin >> x0;

    cout << "b = ";
    cin >> x1;

    cout << "eps = ";
    cin >> eps;

    x = find(x0, x1, eps);

    cout << "Root x = " << fixed << setprecision(16) << x << endl;
    cout << "Function value f(x) = " << func(x) << endl;

    return 0;
}

