# Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6 Метод Симпсона c заданием точности
def simpson_rule(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx = 1.0 * (b - a) / nseg
    sum = (func(a) + 4 * func(a + dx) + func(b))
    nseg = int(nseg / 2)
    for i in range(1, nseg):
        sum += 2 * func(a + (2 * i) * dx) + 4 * func(a + (2 * i + 1) * dx)

    return sum * dx / 3

def func(x):
    return x**4 * (19 + x**2)**(-1)

from math import *

print("Используем метод Симпсона")
print("Интегрируемая функция: f(x) = sin(x) / x")

a=1 # левый край отрезка интегрирования
b=2 # правый край отрезка интегрирования
nseg = 2 # начальное количество сегментов
eps=1e-6 # точность

print('a = ', a ,', b = ', b ,', eps = ', eps, sep='')

int_1 = simpson_rule(func, a, b, nseg)
nseg *= 2
int_2 = simpson_rule(func, a, b, nseg)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = simpson_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = simpson_rule(func, a, b, nseg)

print("\nОтвет: I =", int_2, "\nКоличество разбиений:", nseg)