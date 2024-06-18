# Метод прогонки
import numpy as np

def Metod_Progonki(A, B):
    # Известные константы
    k1 = -A[0][1]
    m1 = B[0]
    k2 = -A[-1][-2]
    m2 = B[-1]
    
    alfa = k1
    beta = m1
    
    # Поиск alfa и beta
    c = 2
    a = 0
    b = 1
    alf = [alfa]
    bet = [beta]
    
    for i in range(1, A.shape[0] - 1):
        if c < A.shape[1]:
            beta = (B[i] - A[i][a] * beta) / (A[i][a] * alfa + A[i][b])
            alfa = -A[i][c] / (A[i][a] * alfa + A[i][b])
            a += 1
            b += 1
            c += 1
            alf.append(alfa)
            bet.append(beta)
        else:
            break
    
    # Расчет y
    y = (k2 * beta + m2) / (1 - k2 * alfa)
    otv = [y]
    
    # Цикл для обратного вычисления ответа
    for i in range(len(alf) - 1, -1, -1):
        y = alf[i] * y + bet[i]
        otv.append(y)
    
    # Переворачиваем значения в списке
    otvet = []
    for i in reversed(otv):
        otvet.append(i)
    
    return otvet

# Задаем матрицу системы 5x3
A = np.array([[-14, 6, 0], [2, 7, 0], [-7, -18, -9], [2, -13, 2], [-7, -7, 0]])
B = np.array([82, -51, -46, 111, 35])

# Вызов функции и вывод на экран
print(A)
print(B)
Result = Metod_Progonki(A, B)
print(f'Результат: {Result}')

