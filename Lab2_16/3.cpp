/*
Дано уравнение параболы  и точка на плоскости где параметры параболы 
и координаты точки определены случайным образом.  исследовать вопрос о том, 
принадлежит ли точка параболе. Найти координату фокуса параболы, найти растояние от 
директрисы параболы до его фокуса.
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Расстояние между двумя точками
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(){

 srand(static_cast<unsigned int>(time(nullptr)));

    double a = rand() % 5 + 1; // от 1 до 5
    double b = rand() % 9 - 3 ; // от 3 до 5s
    double c = rand() % 21 - 10; // от -10 до 10

    // Точка 
    double x = rand() % 21 - 10; 
    double y = rand() % 21 - 10; 

cout << "Парабола:" << a << "x^2 +" << b <<"x + " << c <<endl;
    if (y == a * x * x + b * x + c) {
        cout << "Точка принадлежит параболе." << std::endl;
    } else {
        cout << "Точка не принадлежит параболе." << std::endl;
    }
  //Фокус 

    double p = -b / (2 * a);
    double q = c - (b * b) / (4 * a);
    double d = 1 / (4 * a);
    
    cout << "Координаты точки: (" << x << ", " << y << ")" << std::endl;

    cout << "Координаты фокуса: (" << p << ", " << q << ")" << std::endl;
    cout << "Расстояние от директрисы до фокуса: " << d << std::endl;
}