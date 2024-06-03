#Найти численно значение неопределенного интеграла exp(-2*x) * sin(19*x) c точностью 10-6. Метод прямоугольников.  
def _rectangle_rule(func, a, b, nseg, frac):
    dx = 1.0 * (b - a) / nseg
    sum = 0.0
    xstart = a + frac * dx 
    for i in range(nseg+1):
        sum += func(xstart + i * dx)
    return sum * dx

def func(x):
    return exp (-2*x) * sin(19*x)

from math import *

print("Используем метод прямоугольников.")
print("Интегрируемая функция: f(x) = e^(-2x) * sin(19x).")

a = 0  # Левый край отрезка интегрирования
b = 1  # Правый край отрезка интегрирования
nseg = 2  # Начальное количество сегментов
eps = 1e-6  # Точность
frac = 0.5

print('a =', a, ', b =', b, ', frac =', frac, ', eps =', eps)

int_1 = _rectangle_rule(func, a, b, nseg, frac)
nseg *= 2
int_2 = _rectangle_rule(func, a, b, nseg, frac)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = _rectangle_rule(func, a, b, nseg, frac)
    nseg *= 2
    int_2 = _rectangle_rule(func, a, b, nseg, frac)

print("\nОтвет: I =", int_2, "\nКоличество разбиений:", nseg)
