#Метод дихотомии
from math import *

def example_function(x):
    return exp(-x) - sqrt(x - 1) # Уравнение

# Функция метода

def dichotomy_method(f, a, b, epsilon):
    if f(a) * f(b) > 0:
        return None
    iter = 0
    while (b - a) / 2 > epsilon:
        c = (a + b) / 2
        iter +=1
        if f(c) == 0:
            return c
        elif f(a) * f(c) < 0:
            b = c
        else:
            a = c
    print(f"Количество итераций: {iter}") 
    return (a + b) / 2

a=1 #левый край
b=3 #правый край
epsilon=1e-6 #точность
root = dichotomy_method(example_function, a, b, epsilon)
print(f"Решение уравнения: x = {root}")
fun=example_function(root)
print(f"Значение функции: f({root})=",fun)