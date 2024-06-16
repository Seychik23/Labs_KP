// 
// Метод Гаусса для системы 4x4 с правой частью

#include<iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N    4 // Задаем размерноть системы 
#define N1    N+1
using namespace std;
/* Ввод матрицы системы */
float matrix[N][N1]={{7,-5, 6 ,7, 120},
                     {8,-1, -9 ,1, 31},
                     {-3, 8, 8, 8, 6 },
                     {2, -3, 6, -4, 25}};
/* Погрешность вычисления */
float epsilon=0.001;
 
void ShowMatrix(void)
{
cout << "SLAU Gauss:" << endl;
  int i,j;
    for (i=0 ;i<N; i++)
      {
        for (j=0; j<N; j++)
          printf("%+3.3f*x%d",matrix[i][j],i+1);
          printf("=%3.3f\n",matrix[i][N]);
      }
}
 
int main()
{
  float tmp, xx[N1];
  short int i, j, k;
 
  ShowMatrix();
 

/*Метод Гаусса
 прямой ход*/

  for (i=0; i<N; i++)
   {
     tmp=matrix[i][i];
       for (j=N;j>=i;j--)
           matrix[i][j]/=tmp;
         for (j=i+1;j<N;j++)
        {
           tmp=matrix[j][i];
             for (k=N;k>=i;k--)
           matrix[j][k]-=tmp*matrix[i][k];
        }
    }

/*обратный ход*/

  xx[N-1] = matrix[N-1][N];
   for (i=N-2; i>=0; i--)
     {
         xx[i] = matrix[i][N];
         for (j=i+1;j<N;j++) xx[i]-=matrix[i][j]*xx[j];
     }

/*вывод решения*/

printf("\nMetod Gaussa:\n");
  for (i=0; i<N; i++)
    printf("x[%d]=%6.5f\n", i+1, xx[i]);
 
 return 0;
}