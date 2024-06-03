/*
Даны две прямые на плоскости, а также точка, параметры прямых и координата точки определены случайным образом. 
Найти расстояния от точки до каждой прямой , найти точку пересечения прямых,
найти расстояние от заданной точки до пересечения прямых, найти угол между прямыми. 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
    
    //Расстояния от точки до прямых
double pointLineDist(int x, int y, int a, int b, int c) {
    return abs(a*x + b*y + c) / sqrt(a*a + b*b);
}
    //Пересечение
pair<double, double> findIntersection(int a1, int b1, int c1, int a2, int b2, int c2) {
    double det = a1*b2 - a2*b1;
    double x = (b1*c2 - b2*c1) / det;
    double y = (a2*c1 - a1*c2) / det;
    return make_pair(x, y);
}
    //Угол между прямыми
double angleBetweenLine(int a1, int b1, int a2, int b2) {
    return atan2(b2, a2) - atan2(b1, a1);
}

int main() {
    //Генерация случайных значений 
    int a1 = rand() % 10 + 1;
    int b1 = rand() % 10 + 1;
    int c1 = rand() % 10 + 1;

    int a2 = rand() % 10 + 1;
    int b2 = rand() % 10 + 1;
    int c2 = rand() % 10 + 1;

    int x = rand() % 10 + 1;
    int y = rand() % 10 + 1;

    //Вызов функций 
    double dist1 = pointLineDist(x, y, a1, b1, -c1);
    double dist2 = pointLineDist(x, y, a2, b2, -c2);

    auto intersection = findIntersection(a1, b1, -c1, a2, b2, -c2);

    double dist_from_point = hypot(intersection.first - x, intersection.second - y);

    double angle_deg = angleBetweenLine(a1, b1, a2, b2) * 180 / M_PI;

    cout << "Расстояние от точки (" << x << ", " << y << ") до прямой 1: " << dist1 << endl;
    cout << "Расстояние от точки (" << x << ", " << y << ") до прямой 2: " << dist2 << endl;
    cout << "Точка пересечения прямых: (" << intersection.first << ", " << intersection.second << ")" << endl;
    cout << "Расстояние от точки (" << x << ", " << y << ") до точки пересечения: " << dist_from_point << endl;
    cout << "Угол между прямыми: " << angle_deg << " градусов" << endl;

    return 0;
}
