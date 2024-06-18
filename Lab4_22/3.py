# Метод Зейделя 4 на 4 с правой частью
import numpy as np
import math 

import numpy as np

def seidel(A, b, x0, epsilon, max_iterations):
    n = len(A)
    x = x0.copy()

    # Seidel Method
    for _ in range(max_iterations):
        x_new = np.zeros(n)
        for i in range(n):
            s1 = np.dot(A[i, :i], x_new[:i])
            s2 = np.dot(A[i, i + 1:], x[i + 1:])
            x_new[i] = (b[i] - s1 - s2) / A[i, i]

        if np.allclose(x, x_new, rtol=epsilon):
            return x_new

        x = x_new

    return x

# Заполнение матрицы и правой части
A = np.array([[-18, 9, -1, -8],
              [6, 22, 9, 0],
              [-4, 2, -16, 9],
              [1, 6, -1, -14]])
b = np.array([-60, -109, -103, -33])
x0 = np.zeros(4)
eps = 1e-2  # Точность
max_iter = 100  # Число итераций

x = seidel(A, b, x0, eps, max_iter)
print(x)
