'''
Даны две прямые на плоскости, а также точка, параметры прямых и координата точки определены случайным образом. 
Найти расстояния от точки до каждой прямой , найти точку пересечения прямых,
найти расстояние от заданной точки до пересечения прямых, найти угол между прямыми. 
Здесь используются библиотеки numpy и scipy.
'''
import numpy
from scipy.spatial import distance
import math

# Случайные параметры a,b,c
a1 = numpy.random.randint(1, 10)
b1 = numpy.random.randint(1, 10)
c1 = numpy.random.randint(1, 10)

a2 = numpy.random.randint(1, 10)
b2 = numpy.random.randint(1, 10)
c2 = numpy.random.randint(1, 10)

# Случайная точка 
x_point = numpy.random.randint(1, 10)
y_point = numpy.random.randint(1, 10)

# Пересечение
det = a1*b2 - a2*b1
intersection_x = (b1*c2 - b2*c1) / det
intersection_y = (a2*c1 - a1*c2) / det
inter_point = numpy.array([intersection_x, intersection_y])

# Расстояния от точки до прямых
def distance_to_line(x, y, a, b, c):
    return numpy.abs(a*x + b*y + c) / numpy.sqrt(a**2 + b**2)

distance1 = distance_to_line(x_point, y_point, a1, b1, c1)
distance2 = distance_to_line(x_point, y_point, a2, b2, c2)

# Расстояние от заданной точки до точки пересечения
distance_point_inter = distance.euclidean(inter_point, [x_point, y_point])

# Угол между прямыми
angle_rad = math.atan2(b2, a2) - math.atan2(b1, a1)
angle_deg = math.degrees(angle_rad)

print(f"Расстояние от точки ({x_point}, {y_point}) до прямой 1: {distance1}")
print(f"Расстояние от точки ({x_point}, {y_point}) до прямой 2: {distance2}")
print(f"Точка пересечения прямых: {inter_point}")
print(f"Расстояние от точки ({x_point}, {y_point}) до точки пересечения: {distance_point_inter}")
print(f"Угол между прямыми: {angle_deg} градусов")
