# Метод наискорейшего спуска для поиска оптимума функции
import numpy as np
import matplotlib.pyplot as plt

# Пропишем функцию f(x)
def objective(w1, w2):
    try:
        return w1**2 + np.exp(w1**2 + w2**2) + 4*w1 + 3*w2
    except OverflowError:
        return float('inf')

# Производная функции f по переменной x1
def partial_1(w1, w2):
    try:
        return 2*w1 + 2*w1*np.exp(w1**2 + w2**2) + 4
    except OverflowError:
        return float('inf')

# Производная функции f по переменной x2
def partial_2(w1, w2):
    try:
        return 2*w2*np.exp(w1**2 + w2**2) + 3
    except OverflowError:
        return float('inf')

# Изначальные веса (точка старта)
w1, w2 = 3, 4

# Количество итераций
iterations = 100

# Скорость обучения
learning_rate = 0.05

w1_list, w2_list, l_list = [], [], []

# В цикле с заданным количеством итераций
for i in range(iterations):
    w1_list.append(w1)
    w2_list.append(w2)
    l_list.append(objective(w1, w2))

    par_1 = partial_1(w1, w2)
    par_2 = partial_2(w1, w2)

    # Обновление весов
    w1 = w1 - learning_rate * par_1
    w2 = w2 - learning_rate * par_2

    # Ограничение значений для предотвращения переполнения
    if not np.isfinite(w1) or not np.isfinite(w2) or np.abs(w1) > 100 or np.abs(w2) > 100:
        print(f"Weight overflow at iteration {i}")
        break

print('Optimal weights:', w1, w2)
print('Optimal value:', objective(w1, w2))
