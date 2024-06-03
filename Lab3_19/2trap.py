#Найти численно значение неопределенного интеграла exp(-2*x) * sin(19*x) c точностью 10-6с. Метод трапеций с заданием точности
def trapezoid_rule(func, a, b, nseg):
    """Правило трапеций
       nseg - число отрезков, на которые разбивается [a;b]"""
    dx = 1.0 * (b - a) / nseg
    sum = 0.5 * (func(a) + func(b))
    for i in range(1, nseg):
        sum += func(a + i * dx)

    return sum * dx

def func(x):
    return exp(-2*x) * sin(19*x) 

from math import *

print("Используем метод трапеций")
print("Интегрируемая функция:(x) = e^(-2x) * sin(19x)")


a=0 # левый край отрезка интегрирования
b=1 # правый край отрезка интегрирования
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