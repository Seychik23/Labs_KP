# Метод дихотомии (половинного деления)
import math

# Функция
def func(x):
    return math.exp(-x) - math.sqrt(x - 1)

# Метод половинного деления для нахождения корня уравнения
def find_root(a, b, eps):
    while abs(b - a) > eps:
        mid = (a + b) / 2
        if func(mid) == 0:
            return mid
        elif func(a) * func(mid) < 0:
            b = mid
        else:
            a = mid

    return (a + b) / 2

# Начальные границы интервала и требуемая точность
a = 1.0
b = 3.0
epsilon = 1e-6


root = find_root(a, b, epsilon)
print(f"Численный корень уравнения: {root}")
