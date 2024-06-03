'''
Даны два уравнения плоскости и координата точки в пространстве , 
параметры плоскостей и координата точки определены случайным образом. 
Найти угол между плоскостями, выяснить их параллельность, если параллельны , 
то найти рассояние между плоскостями, найти расстояние от точки до каждой плоскости, 
если плоскости пересекаются, то найти параметры прямой, по которой пересекаются плоскости.
'''
import math
import numpy as np
import scipy

# Cлучайные коэф двух плоскостей (a,b,c,d=0)ax + by + cz + d = 0
np.random.seed(42)
plane1 = np.random.rand(4)  
plane2 = np.random.rand(4)  

# Точка (x,y,z)
point = np.random.rand(3)  

# Угол между плоскостями
angle = np.degrees(np.arccos(np.dot(plane1[:3], plane2[:3]) / (np.linalg.norm(plane1[:3]) * np.linalg.norm(plane2[:3]))))


parallel = np.isclose(np.cross(plane1[:3], plane2[:3]), 0).all()

if parallel:
    # Р Между параллельными плоскостями
    distance = abs(plane2[3] - plane1[3]) / np.linalg.norm(plane1[:3])

# От точки до плоскости
dist_to_plane1 = abs(np.dot(plane1[:3], point) + plane1[3]) / np.linalg.norm(plane1[:3])
dist_to_plane2 = abs(np.dot(plane2[:3], point) + plane2[3]) / np.linalg.norm(plane2[:3])

direction = np.cross(plane1[:3], plane2[:3])
point_on_line = np.array([0.0, 0.0, 0.0])  

print(f"Угол между плоскостями: {angle} градусов")
print(f"Плоскости параллельны: {parallel}")

if parallel:
    print(f"Расстояние между плоскостями: {distance}")

print(f"Расстояние от точки до плоскости 1: {dist_to_plane1}")
print(f"Расстояние от точки до плоскости 2: {dist_to_plane2}")
print(f"Параметры прямой пересечения: Точка: {point_on_line}, Направление: {direction}")

