#Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6. Метод трапеций с заданием точности
def trapezoid_rule(func, a, b, nseg):
    """Правило трапеций
       nseg - число отрезков, на которые разбивается [a;b]"""
    dx = 1.0 * (b - a) / nseg
    sum = 0.5 * (func(a) + func(b))
    for i in range(1, nseg):
        sum += func(a + i * dx)

    return sum * dx

def func(x):
    return x**4 * (19 + x**2)**(-1)

from math import *

print("Используем метод трапеций")
print("Интегрируемая функция:(1,2) f(x) = x^4 * (19 + x^2)^(-1)")


a=1 # левый край отрезка интегрирования
b=2 # правый край отрезка интегрирования
nseg = 2 # начальное количество сегментов
eps=1e-6 # точность


print('a = ', a ,', b = ', b ,', eps = ', eps, sep='')

int_1 = trapezoid_rule(func, a, b, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, a, b, nseg)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, a, b, nseg)

print("\nОтвет: I =", int_2, "\nКоличество разбиений:", nseg)