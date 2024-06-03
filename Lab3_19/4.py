'''
Численно найти сумму функционального ряда (k=1, infty)(-1)**k / (sin(k * x) + 19 + k**2) с точностью 10^-6
'''
from math import *

def calculate_term(k, x):
    return (-1)**k / (sin(k * x) + 19 + k**2) #Функциональный ряд

# Функция для вычисления суммы ряда с заданной точностью
def calculate_sum(x, tolerance):
    k = 1
    sum_result = 0.0
    term = calculate_term(k, x)

    while abs(term) >= tolerance:
        sum_result += term
        k += 1
        term = calculate_term(k, x)

    return sum_result

tolerance = 1e-6  # Устанавливаем требуемую точность
x = 5  # Задаем значение x

result = calculate_sum(x, tolerance)  # Вычисляем сумму функционального ряда

# Выводим результат с заданной точностью
print("Ряд (k=1, infty)(-1)**k / (sin(k * x) + 19 + k**2)")
print(f"Сумма функционального ряда с точностью 10^-6 при x = {x}:")
print(f"Sum = {result}")
