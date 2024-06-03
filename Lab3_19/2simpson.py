#Найти численно значение неопределенного интеграла exp(-2*x) * sin(19*x) c точностью 10-6с.Метод Симпсона c заданием точности
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
    return exp(-2*x) * sin(19*x)

from math import *

print("Используем метод Симпсона")
print("Интегрируемая функция: f(x) = e^(-2x) * sin(19x")

a=0 # левый край отрезка интегрирования
b=1 # правый край отрезка интегрирования
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