#include <iostream>
using namespace std;


void n_sized_array() {
    const int n = 3;
    int matrix[n][n] = {
            {5, 6, 7},
            {12, 4, 9},
            {10, 1, 2}
    };
    for (int string = 0; string < n; string++) {  // перебираю строки матрицы
        for (int elem = 0; elem < n; elem++) {  // перебираю элементы строк матрицы
            cout << matrix[string][elem] << " | ";
        }
        cout << endl;
    }

}

void task_matrix() {
    /* Задана матрица nxn, нужно посчитать сумму элементов
     * на главной диагонали матрицы. */
    const int n = 3;
    int matrix[n][n] = {
            {2, 5, 7},
            {3, 2, 1},
            {4, 1, 5},
    };
    int summ = 0;
    int mult = 1;
    for (int i = 0; i < n; i++) {
        summ += matrix[i][i];
        mult *= matrix[i][n - 1 - i];
    }
    cout << summ << endl;
    cout << mult << endl;
}
