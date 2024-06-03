'''
Дано уравнение эллиптического параболоида, 
плоскости, прямой и координаты точки в пространстве,
параметры которых определены случайным образом. 
Выяснить вопрос о том, пересекает ли плоскость или прямая заданный эллиптический параболоид, 
принадлежит ли точка эллиптическому параболоиду.
'''
import math
from random import *

# Случайные параметры 

parab = [randint(-10,10) for _ in range(10)]

plane = [randint(-5,5) for _ in range(4)]

point = [randint(-5,5) for _ in range(3)]

x, y, z = point
a, b, c, d = plane
A, B, C, D, E, F, G, H, I, J = parab

print(f"Эллиптический параболоид: {A}x^2+{B}y^2+{C}z^2+{D}xy+{E}xz+{F}yz+{G}x+{H}y+{I}z+{J}=0")
print(f"Точка:({x},{y},{z})")
print(f"Плоскость:{a}x+{b}y+{c}z+{d}")


# ax + by + cz + d = 0
def plane_inter_parab(point, plane, parab):
    x, y, z = point
    a, b, c, d = plane
    A, B, C, D, E, F, G, H, I, J = parab
    result = A*a*x + B*b*y + C*c*z + D*(a*y + b*x) + E*(a*z + c*x) + F*(b*z + c*y) + G*x + H*y + I*z + J*d
    return result == 0

# Уравнение эллиптического параболоида: Ax^2 + By^2 + Cz^2 + Dxy + Exz + Fyz + Gx + Hy + Iz + J = 0
def point_belongs_parab(point, parab):
    x, y, z = point
    A, B, C, D, E, F, G, H, I, J = parab
    result = A*x**2 + B*y**2 + C*z**2 + D*x*y + E*x*z + F*y*z + G*x + H*y + I*z + J
    return result == 0

inter_parab = plane_inter_parab (point, plane, parab)

if inter_parab:
    print('Плоскость пересекает параболоид')
else:
    print('Плоскость не пересекает параболоид')


belongs_parab = point_belongs_parab (point, parab)

if belongs_parab:
    print('Точка принадлежит параболоиду')
else:
    print('Точка не принадлежит параболоиду')
