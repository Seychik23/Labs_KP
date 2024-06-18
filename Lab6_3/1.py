# Метод покоординатного спуска для поиска оптимума функции
import numpy as np
import matplotlib.pyplot as plt

# Задаем функцию f(x) = e^(x1^2 + x2^2) + ln(4 + x2^2 + 2*x3^2)
def objective(x1, x2, x3):
    try:
        return np.exp(x1**2 + x2**2) + np.log(4 + x2**2 + 2*x3**2)
    except OverflowError:
        return float('inf')

# Инициализация начальных значений
x1, x2, x3 = 0.1, 0.1, 0.1

# Итерации и шаг оптимизации
iterations = 1000
step_size = 0.0001

# Списки для хранения значений координат и функции потерь
x1_list, x2_list, x3_list, loss_list = [], [], [], []

for i in range(iterations):
    x1_list.append(x1)
    x2_list.append(x2)
    x3_list.append(x3)
    loss_list.append(objective(x1, x2, x3))

    # Вычисляем произв
    grad_x1 = 2 * x1 * np.exp(x1**2 + x2**2)
    grad_x2 = 2 * x2 * np.exp(x1**2 + x2**2) + 2 * x2 / (4 + x2**2 + 2 * x3**2)
    grad_x3 = 4 * x3 / (4 + x2**2 + 2 * x3**2)
    
    # Обновление x1, x2, x3
    x1 = x1 - step_size * grad_x1
    x2 = x2 - step_size * grad_x2
    x3 = x3 - step_size * grad_x3

    # Ограничение значений, чтобы избежать переполнения
    x1 = np.clip(x1, -100, 100)
    x2 = np.clip(x2, -100, 100)
    x3 = np.clip(x3, -100, 100)

# Вывод оптимальных значений и максимальное значение функции
optimal_x1, optimal_x2, optimal_x3 = x1_list[-1], x2_list[-1], x3_list[-1]
print('Optimal values: x1 =', optimal_x1, 'x2 =', optimal_x2, 'x3 =', optimal_x3)
print('Optimal f:', objective(optimal_x1, optimal_x2, optimal_x3))

# Визуализация графиком
fig, ax = plt.subplots()
ax.plot(x1_list, label='x1')
ax.plot(x2_list, label='x2')
ax.plot(x3_list, label='x3')
ax.set_xlabel('Iterations')
ax.set_ylabel('Values')
ax.set_title('Метод покоординатного спуска')
ax.legend()
plt.show()
