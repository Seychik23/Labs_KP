# Комплексные числа, операции
import math
import cmath

# Функция для перевода комплексного числа в тригонометрическую форму
def complex_to_trig(z):
    r, theta = cmath.polar(z)
    return r, theta

# Функция для возведения комплексного числа в степень
def complex_pow(z, n):
    r, theta = complex_to_trig(z)
    return r**n * cmath.exp(1j * n * theta)

# Функция для извлечения корня из комплексного числа
def complex_root(z, n):
    r, theta = complex_to_trig(z)
    roots = []
    for k in range(n):
        root = r**(1/n) * cmath.exp(1j * (theta + 2 * math.pi * k) / n)
        roots.append(root)
    return roots

# Арифметические операции
z1 = complex(input("Введите комплексное число z1, формат a+bj: "))
z2 = complex(input("Введите комплексное число z2, формат a+bj: "))
print(f'z1+z2={z1+z2}, z1-z2={z1-z2}, z1*z2={z1*z2}, z1/z2={z1/z2}')

z3 = complex(input("Введите комплексное число z3, формат a+bj: "))
n = int(input("Введите степень, в которую возвести z3: "))
n1 = int(input("Введите степень корня: "))

r, theta = complex_to_trig(z3)
print("Комплексное число в тригонометрической форме:", f'{r:.5f}*(cos({theta:.5f}) + i*sin({theta:.5f})')
print("Возведение в степень:", complex_pow(z3, n))
print("Извлечение корня:", complex_root(z3, n1))
