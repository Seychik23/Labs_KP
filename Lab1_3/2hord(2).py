#Метод хорд (секущих)

import math

def example_function(x):
    if x.real < 1:
        return complex(math.exp(-x.real), math.sqrt(abs(x.real - 1)))
    return math.exp(-x.real) - math.sqrt(x.real - 1)

def secant_method(f, x_0, x_1, epsilon, max_iter):
    iteration = 0

    while iteration < max_iter:
        f_x0 = f(x_0)
        f_x1 = f(x_1)
        if abs(f_x1 - f_x0) < 1e-15:  # Avoid division by very small numbers
            break

        x_2 = x_1 - f_x1 * (x_1 - x_0) / (f_x1 - f_x0)

        if abs(x_2 - x_1) < epsilon:
            return x_2, iteration

        x_0 = x_1
        x_1 = x_2
        iteration += 1

    raise Exception("Не удалось найти корень методом секущих")

a = 0 
b = 3 
epsilon = 1e-6 
max_iter = 100 
root, iterations = secant_method(example_function, a, b, epsilon, max_iter)

if isinstance(root, complex):
    print(f"Корень уравнения: {root.real:.12f} + {root.imag:.12f}j")
else:
    print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun = example_function(root)
print(f"Значение функции: f({root}) =", fun)

