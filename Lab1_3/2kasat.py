# Метод Ньютона(касательных)
import cmath

def example_function(x):
    if x.real < 1:
        return cmath.exp(-x) - cmath.sqrt(abs(x - 1))
    return cmath.exp(-x) - cmath.sqrt(x - 1)

def derivative_example_function(x):
    if x == 1:
        return cmath.inf
    return -cmath.exp(-x) - 1 / (2 * cmath.sqrt(x - 1))

def tangent_method(f, df, x0, epsilon, max_iter):
    x = x0
    for i in range(max_iter):
        f_x = f(x)
        f_derivative = df(x)
        x_new = x - f_x / f_derivative

        if abs(x_new - x) < epsilon:
            return x_new, i + 1
        x = x_new

    return None, max_iter

x0 = 1  
epsilon = 1e-6 
max_iter = 100 
root, iterations = tangent_method(example_function, derivative_example_function, x0, epsilon, max_iter)

print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun = example_function(root)
print(f"Значение функции: f({root}) =", fun)
