'''
Численно найти сумму числового ряда (k=1, infty) 19.0 / (pow(2, k) - 1) + pow(-1, k - 1) / (2.0 * pow(3, k - 1)) 
с точностью 10^-6
'''
from math import *
def calculate_term(k):
    return 19 / (2**k - 1) + (-1)**(k-1) / (2 * 3**(k-1)) # Числовой ряд
 
 # Функция для вычисления суммы ряда с заданной точностью
def calculate_sum(tolerance):
    sum_result = 0.0
    term = 0.0
    k = 1

    while True:
        term = calculate_term(k) # вычисляем очередной член ряда
        sum_result += term #прибавляем к сумме
        if abs(term) < tolerance: #проверка точности
            break
        k += 1 # к следующему

    return sum_result

tolerance = 1e-6  # Задаем точность
result = calculate_sum(tolerance)

print("Ряд (k=1, infty) 19.0 / (pow(2, k) - 1) + pow(-1, k - 1) / (2.0 * pow(3, k - 1))")
print("Сумма функционального ряда с точностью 10^-6:")
print(f"Sum = {result:.12f}")
