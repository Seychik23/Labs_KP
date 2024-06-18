# Метод Якоби 3 на 3 с правой частью

import numpy as np

# Функция метода Якоби
def jacobi_iteration(A, b, initial_guess, max_iterations=100, tolerance=1e-6):
    n = len(A)
    x = initial_guess.copy()

    for iteration in range(max_iterations):
        x_new = np.zeros_like(x)

        for i in range(n):
            s = np.dot(A[i, :i], x[:i]) + np.dot(A[i, i+1:], x[i+1:])
            x_new[i] = (b[i] - s) / A[i, i]

        if np.linalg.norm(x_new - x) < tolerance:
            return x_new

        x = x_new

    return x
# Ввод коэф. матрицы:
A = np.array([[5, -2, -1], [2, -1, -1], [2, -4, -8]])
b = np.array([0, -1, 1])
initial_guess = np.zeros_like(b)
solution = jacobi_iteration(A, b, initial_guess)
print("Solution:", solution)