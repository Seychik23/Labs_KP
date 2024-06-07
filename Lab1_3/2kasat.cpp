// Метод Ньютона(касательных)
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(double x)
{
    return exp(-x) - sqrt(x - 1);
}

double dfunc(double x)
{
    return -exp(-x) - 1 / (2 * sqrt(x - 1));
}

double find(double x, double eps)
{
    double f, df;
    int iter = 0;

    cout << "x_0 = " << x << " ";

    do {
        f = func(x);
        df = dfunc(x);
        x = x - f / df;
        iter++;
    } while (fabs(f) > eps && iter < 20000);

    cout << "\nNumber of iterations is " << iter << endl;

    return x;
}

int main()
{
    double x0, x, eps;

    cout << "x_0 = ";
    cin >> x0;

    cout << "eps = ";
    cin >> eps;

    x = find(x0, eps);

    cout << "Root x = " << fixed << setprecision(16) << x << endl;
    cout << "Function value f(x) = " << func(x) << endl;

    return 0;
}
