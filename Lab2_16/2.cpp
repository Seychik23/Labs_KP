/*
Даны два уравнения плоскости и координата точки в пространстве , 
параметры плоскостей и координата точки определены случайным образом. 
Найти угол между плоскостями, выяснить их параллельность, если параллельны , 
то найти рассояние между плоскостями, найти расстояние от точки до каждой плоскости, 
если плоскости пересекаются, то найти параметры прямой, по которой пересекаются плоскос
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Вектор. произведения
vector<double> cross(vector<double> v1, vector<double> v2) {
    vector<double> result(3);
    result[0] = v1[1]*v2[2] - v1[2]*v2[1];
    result[1] = v1[2]*v2[0] - v1[0]*v2[2];
    result[2] = v1[0]*v2[1] - v1[1]*v2[0];
    return result;
}

// Функция скалярное произв.
double dot(vector<double> v1, vector<double> v2) {
    double result = 0;
    for(int i = 0; i < v1.size(); i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Ф-ция норм. вектора
double norm(vector<double> v) {
    double result = 0;
    for(int i = 0; i < v.size(); i++) {
        result += v[i] * v[i];
    }
    return sqrt(result);
}

int main() {

    vector<double> plane1 = {0.1, 0.2, 0.3, 0.4}; 
    vector<double> plane2 = {0.5, 0.6, 0.7, 0.8};  // (a, b, c, d) коэф. плоскости 2
    vector<double> point = {1.0, 2.0, 3.0};  // (x, y, z) координаты точки

    // Угол между плоскостями
    double angle = acos(dot(plane1, plane2) / (norm(plane1) * norm(plane2))) * 180 / M_PI;

    // Параллельность плоскостей
    bool parallel = cross(plane1, plane2)[0] == 0 && cross(plane1, plane2)[1] == 0 && cross(plane1, plane2)[2] == 0;

    double dist;
    if (parallel) {
        // Расстояние между параллельными плоскостями
        dist = abs(plane2[3] - plane1[3]) / norm(cross(plane1, plane2));
    }

    // Расстояния от точки до плоскостей
    double dist1 = abs(dot(plane1, point) + plane1[3]) / norm(plane1);
    double dist2 = abs(dot(plane2, point) + plane2[3]) / norm(plane2);

    // Найти параметры прямой пересечения
    vector<double> direction = cross(plane1, plane2);
    vector<double> point_on_line = {0.0, 0.0, 0.0};  

    cout << "Угол между плоскостями: " << angle << " градусов" << endl;
    cout << "Плоскости параллельны (если 0, то нет): " << parallel << endl;

    if(parallel) {
        cout << "Расстояние между плоскостями: " << dist << endl;
    }

    cout << "Расстояние от точки до плоскости 1: " << dist1 << endl;
    cout << "Расстояние от точки до плоскости 2: " << dist2 << endl;
    cout << "Параметры прямой пересечения: Точка: (" << point_on_line[0] << ", " << point_on_line[1] << ", " << point_on_line[2] << "), Направление: (" << direction[0] << ", " << direction[1] << ", " << direction[2] << ")" << endl;

    return 0;
}
