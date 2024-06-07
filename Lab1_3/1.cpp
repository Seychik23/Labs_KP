 //Комплексные числа
#include <iostream>
#include <complex>
#include <math.h>
#include <iomanip>
   
using namespace std;

int main() {
int n, k;
double real, imag, z_real, z_imag, n_rt, dn_rt;
complex< double > z1( 1.0, 1.0 );
complex< double > z2( 3.0, -1.0 );
complex< double > z3( -1.0, 1.0 );

cout <<"z1=" << z1 << endl; // Комплексное число выводится в виде вектора
cout << "z1^sopr=" << conj( z1 ) << endl; // Комплексно-сопряженное
cout <<"z2=" << z2 << endl; // Комплексное число выводится в виде вектора
cout << "z2^sopr=" << conj( z2 ) << endl; // Комплексно-сопряженное
cout << "Re z1=" << z1.real() << endl; // Действительная часть комплексного числа
cout << "Im z1=" << z1.imag() << endl; // Мнимая часть комплексного числа
cout << "Re z2=" << z2.real() << endl; // Действительная часть комплексного числа
cout << "Im z2=" << z2.imag() << endl; // Мнимая часть комплексного числа
cout << "z1 + z2=" << z1 + z2 << endl; // Сложение комплексных чисел
cout << "z1 - z2=" << z1 - z2 << endl; // Разность комплексных чисел
cout << "z1 * z2=" << z1 * z2 << endl; // Умножение комплексных чисел
cout << "z1 / z2=" << z1 / z2 << endl; // Деление комплексных чисел


cout << "z3^3=" << pow( z3, 4 ) << endl; // Возведение в степень комплексного числа

double rho = abs( z3 ); // Модуль комплексного числа
double phi = arg( z3 ); // Аргумент комплексного числа
// Тригонометрическая форма комплексного числа
cout << "z3=" << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;
// Показательная форма комплексного числа
cout <<"z3=" << rho << "*exp(i*" << phi << ")" << endl;
// Получаем исходное комплексное число по модулю и аргументу
cout << "z3=" << polar( rho, phi ) << endl;


// Извлечение корня n степени из комплексного числа
cout << "Input complex number (example: -1 1) " ;
cin >> real >> imag; // Ввод действительной и мнимой части через пробел
complex zp(real, imag);
cout << fixed << setprecision(16) << zp << endl;
cout << "Input number n_root " ;
cin >> n_rt;
cout << "\n";
rho = abs( zp );
phi = arg( zp );
cout << "rho=" << rho << ", phi=" << phi << endl;
dn_rt = 1.0/n_rt;
for(k=0; k<n_rt;k++){
    z_real = pow( rho, float (1/n_rt)) * cos((phi + 2 * M_PI * k) / n_rt);
    z_imag = pow( rho, float (1/n_rt)) * sin((phi + 2 * M_PI * k) / n_rt);
    complex z_n(z_real, z_imag);
    cout << "k=" << k << ", z_k=" << z_n << "\n";}


return 0;
} 