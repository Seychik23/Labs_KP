# //  Метод покоординатного спуска для поиска оптимума функции
import numpy as np

# Задаем функцию
def func(x):
    return np.exp(x[0]**2 + x[1]**2) + np.log(4 + x[1]**2 + 2*x[2]**2)


def gradient(x):
    grad = np.zeros(3)
    grad[0] = 2*x[0]*np.exp(x[0]**2 + x[1]**2)
    grad[1] = 2*x[1]*np.exp(x[0]**2 + x[1]**2) + 2*x[1] / (4 + x[1]**2 + 2*x[2]**2)
    grad[2] = 4*x[2] / (4 + x[1]**2 + 2*x[2]**2)
    return grad

# Реализация метода покоординатного спуска

def coordinate_descent_optimization(func, gradient, initial_x, max_iter=1000, tol=1e-6, step_size=0.01):
    x = initial_x
    for _ in range(max_iter):
        previous_x = x.copy()
        for i in range(len(x)):
            x[i] -= step_size * gradient(x)[i]
        if np.linalg.norm(x - previous_x) < tol:
            break
    return x, func(x)

initial_x = np.array([0.0, 0.0, 0.0])
result, optimal_value = coordinate_descent_optimization(func, gradient, initial_x)

print("Оптимальные значения переменных: ", result)
print("Значение функции в оптимальной точке: ", optimal_value)