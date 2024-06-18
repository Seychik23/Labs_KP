import numpy as np
import matplotlib.pyplot as plt

# Пропишем функцию f(x) = x1^2 + e^(x1^2+x2^2) + 4x1+3x2
def objective(w1, w2):
    return w1**2 + np.exp(w1**2 + w2**2) + 4*w1 + 3*w2

# Производная функции f по переменной x1
def partial_1(w1, w2):
    return 2*w1 + 2*w1*np.exp(w1**2 + w2**2) + 4

# Производная функции f по переменной x2
def partial_2(w1, w2):
    return 2*w2*np.exp(w1**2 + w2**2) + 3

# Изначальные веса (точка старта)
w1, w2 = 3, 4

# Количество итераций
iter = 100

# Скорость обучения
learning_rate = 0.05

w1_list, w2_list, l_list = [], [], []

# В цикле с заданным количеством итераций
for i in range(iter):
    w1_list.append(w1)
    w2_list.append(w2)
    l_list.append(objective(w1, w2))

    par_1 = partial_1(w1, w2)
    par_2 = partial_2(w1, w2)

    w1 = w1 - learning_rate * par_1
    w2 = w2 - learning_rate * par_2

# Вывод итоговых весов и значения функции потерь
print('Optimal weights:', w1, w2)
print('Optimal value:', objective(w1, w2))

fig = plt.figure(figsize=(15, 15))

w1 = np.linspace(-5, 5, 1000)
w2 = np.linspace(-5, 5, 1000)

w1, w2 = np.meshgrid(w1, w2)
f = w1**2 + np.exp(w1**2 + w2**2) + 4*w1 + 3*w2

ax = fig.add_subplot(projection='3d')

ax.plot_surface(w1, w2, f, alpha=0.4, cmap='Blues')

ax.text(3, 3.5, 28, 'A', size=25)
ax.text(0, -0.4, 4, 'B', size=25)

ax.set_xlabel('w1', fontsize=15)
ax.set_ylabel('w2', fontsize=15)
ax.set_zlabel('f(w1, w2)', fontsize=15)

ax.plot(w1_list, w2_list, l_list, '.-', c='red')

plt.show()
