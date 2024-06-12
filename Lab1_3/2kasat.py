# Метод Ньютона (касательных)
import cmath

# Функция, корни которой нужно найти
def func(x):
    return cmath.exp(-x) - cmath.sqrt(x - 1)

# Производная
def derivative_func(x):
    return -cmath.exp(-x) - 1 / (2 * cmath.sqrt(x - 1))

# Метод Ньютона для нахождения корня уравнения
def newton_method(x0, eps):
    x_prev = x0
    x_curr = x_prev - func(x_prev) / derivative_func(x_prev)
    
    # Итеративный процесс до достижения заданной точности
    while abs(x_curr - x_prev) > eps:
        x_prev = x_curr
        x_curr = x_prev - func(x_prev) / derivative_func(x_prev)

    return x_curr

# Начальное предположение для корня и требуемая точность
initial_guess = 2.0
epsilon = 1e-6

root = newton_method(initial_guess, epsilon)
print(f"Численный корень уравнения: {root}")
