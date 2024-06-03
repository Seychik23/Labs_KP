#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstddef>

using namespace std;

// Генерация случайных целых чисел
int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Точка эллиптическому параболоиду
bool point_belongs_parab(int x, int y, int z, int* parab) {
    int A = parab[0];
    int B = parab[1];
    int C = parab[2];
    int D = parab[3];
    int E = parab[4];
    int F = parab[5];
    int G = parab[6];
    int H = parab[7];
    int I = parab[8];
    int J = parab[9];
    
    return (A*x*x + B*y*y + C*z*z + D*x*y + E*x*z + F*y*z + G*x + H*y + I*z + J) == 0;
}

// Пересечение плоскости с эллиптическим параболоидом
bool plane_inter_parab(int x, int y, int z, int* plane, int* parab) {
    int a = plane[0];
    int b = plane[1];
    int c = plane[2];
    int d = plane[3];
    int A = parab[0];
    int B = parab[1];
    int C = parab[2];
    int D = parab[3];
    int E = parab[4];
    int F = parab[5];
    int G = parab[6];
    int H = parab[7];
    int I = parab[8];
    int J = parab[9];
    
    return (A*a*x + B*b*y + C*c*z + D*(a*y + b*x) + E*(a*z + c*x) + F*(b*z + c*y) + G*x + H*y + I*z + J*d) == 0;
}

int main() {
    srand(time(NULL));
    
    //Выделить под генерацию коэф.
    int parab[10];
    int plane[4];
    
    for (int i = 0; i < 10; ++i) {
        parab[i] = getRandomInt(-10, 10);
    }
    
    for (int i = 0; i < 4; ++i) {
        plane[i] = getRandomInt(-5, 5);
    }

    // Генерация целочисленных координат для точки
    int x = getRandomInt(-5, 5);
    int y = getRandomInt(-5, 5);
    int z = getRandomInt(-5, 5);


  // Вывод уравнения эллиптического параболоида
    cout << "Эллиптический параболоид: ";
    for (int i = 0; i < 10; ++i) {
        cout << parab[i];
        if (i < 9) {
            cout << " ";
        } else {
            cout << " = 0" << std::endl;
        }
    }

    // Вывод координат точки
    cout << "Точка: (" << x << ", " << y << ", " << z << ")" << endl;

    // Вывод уравнения плоскости
    cout << "Плоскость: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << plane[i];
        if (i < 3) {
            cout << " ";
        } else {
            cout << " = 0" << std::endl;
        }
    }
    
    // Проверка принадлежности точки эллиптическому параболоиду
    if (point_belongs_parab(x, y, z, parab)) {
        cout << "Точка принадлежит эллиптическому параболоиду" << endl;
    } else {
        cout << "Точка не принадлежит эллиптическому параболоиду" << endl;
    }

    // Проверка пересечения плоскости с эллиптическим параболоидом
    if (plane_inter_parab(x, y, z, plane, parab)) {
        cout << "Плоскость пересекает эллиптический параболоид" << endl;
    } else {
        cout << "Плоскость не пересекает эллиптический параболоид" << endl;
    }

    return 0;
}
