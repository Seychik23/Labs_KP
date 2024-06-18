// Метод прогонки
#include <iostream>
#include <vector>

using namespace std;

vector<double> Metod_Progonki(vector<vector<double>>& A, vector<double>& B) {
    // Известные константы
    double k1 = -A[0][1];
    double m1 = B[0];
    double k2 = -A[A.size() - 1][A[0].size() - 2];
    double m2 = B[B.size() - 1];
    
    double alfa = k1;
    double beta = m1;
    
    // Поиск alfa и beta
    int c = 2;
    int a = 0;
    int b = 1;
    vector<double> alf{alfa};
    vector<double> bet{beta};
    
    for (int i = 1; i < A.size() - 1; ++i) {
        if (c < A[i].size()) {
            beta = (B[i] - A[i][a] * beta) / (A[i][a] * alfa + A[i][b]);
            alfa = -A[i][c] / (A[i][a] * alfa + A[i][b]);
            a++;
            b++;
            c++;
            alf.push_back(alfa);
            bet.push_back(beta);
        } else {
            break;
        }
    }
    
    // Расчет y
    double y = (k2 * beta + m2) / (1 - k2 * alfa);
    vector<double> otv{y};
    
    // Цикл для обратного вычисления ответа
    for (int i = alf.size() - 2; i >= 0; --i) {
        y = alf[i] * y + bet[i];
        otv.push_back(y);
    }
    
    return otv;
}

int main() {
    vector<vector<double>> A = {{-14, 6, 0}, {2, 7, 0}, {-7, -18, -9}, {2, -13, 2}, {-7, -7, 0}};
    vector<double> B = {82, -51, -46, 111, 35};

    // Вызов функции и вывод на экран
    for (auto& row: A) {
        for (auto& num: row) {
            cout << num << " ";
        }
        cout << endl;
    }
    for (double num : B) {
        cout << num << " ";
    }
    cout << endl;

    vector<double> Result = Metod_Progonki(A, B);
    cout << "Результат: ";
    for (double num : Result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
