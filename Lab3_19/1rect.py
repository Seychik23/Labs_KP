# Найти численно значение определенного интеграла (1,2) x^4*(19+x^2)^(-1) с точностью до 10^-6. Метод прмоугольников
def _rectangle_rule(func, a, b, nseg, frac):
    dx = 1.0 * (b - a) / nseg
    sum = 0.0
    xstart = a + frac * dx 
    for i in range(nseg+1):
        sum += func(xstart + i * dx)
    return sum * dx

def func(x):
    return x**4 * (19 + x**2)**(-1)

from math import *

print("Используем метод прямоугольников.")
print("Интегрируемая функция: f(x) = (1,2) x^4 * (19 + x^2)^(-1).")

a = 1  # Левый край отрезка интегрирования
b = 2  # Правый край отрезка интегрирования
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
