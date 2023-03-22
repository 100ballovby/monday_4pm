#include <iostream>
using namespace std;

int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

void create_matrix(int **&matrix, int n, int m) {
    /** Передаю матрицу как указатель на адрес ее
     * ячейки. Когда функция будет запущена, она
     * найдет матрицу по адресу, наполнит ее и
     * сохранит результат в той ячейке, которая указана
     * как параметр функции. **/
    matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = randint(0, 10);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void task1_5(int **&matrix, int n, int m) {
    int line = -1; // строка с нулевым элементом
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0 && line == -1) {
                line = i;
                break;
            }
        }
    }

    cout << "Номер строки : " << line << endl;
    cout << "Первый элемент найденной строки: " << matrix[line][0] << endl;
    int a = matrix[line][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] -= a;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int это_функция_main() {
    srand(time(NULL));
    int m, n;
    cout << "Insert rows: ";
    cin >> n;
    cout << "Insert cols: ";
    cin >> m;

    int **matrix;  // инициализируем указатель на матрицу
    create_matrix(matrix, n, m);
    task1_5(matrix, n, m);
}