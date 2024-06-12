# Метод простых итераций
import math

# Функция, корни которой требуется найти
def func(x):
    return math.exp(-x) - math.sqrt(x - 1)

def g(x):
    return math.exp(-x)

# Функция метода простых итераций
def simple_iteration(x0, eps):
    x1 = g(x0)
    while abs(x1 - x0) >= eps:
        x0 = x1
        x1 = g(x0)
    return x1

# x0 и точность
x0 = 0.0
epsilon = 1e-6

root = simple_iteration(x0, epsilon)
print(f"Численный корень уравнения: {root}")
