#include <iostream>
using namespace std;

int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

int lab5_task2_7() {
    srand((int)time(NULL));
    int n, m;
    cout << "n = "; cin >> n;
    cout << "m = "; cin >> m;
    int **matrix = new int *[n];  // инициализирую matrix новый массив
    for (int i = 0; i < n; i++) {  // повторить n раз
        matrix[i] = new int[m];   // создать внутри matrix вложенный массив
    }
    for (int str = 0; str < n; str++) {
        for (int elem = 0; elem < m; elem++) {
            matrix[str][elem] = randint(-50, 50);
            cout << matrix[str][elem] << " | ";
        }
        cout << endl;
    }
    int *records = new int[m];  // в массив записываем характеристики каждого столбца матрицы
    for (int elem = 0; elem < m; elem++) {  // перебираем элементы (столбцы) матрицы
        records[elem] = 0;  // изначальная характеристика каждого столбца матрицы
        for (int str = 0; str < n; str++) {  // перебираю "строки" матрицы
            if (matrix[str][elem] < 0 && matrix[str][elem] % 2 != 0) {
                records[elem] -= matrix[str][elem];
            }
        }
    }
    cout << "records: " << endl;
    for (int i = 0; i < m; i++) {
        cout << records[i] << ", ";
    }

    for (int elem = 1; elem < m; elem++) {  // граница, которая не даст уйти за пределы массива с характеристиками
        for (int record = 0; record < m - elem; record++) {  // просматриваю характеристики до последней, не включая ее
            if (records[record] > records[record + 1]) {  // если характеристика больше следующей характеристики
                swap(records[record], records[record + 1]);  // поменять их местами

                for (int str = 0; str < n; str++) {  // смотрю столбцы матрицы
                    swap(matrix[str][record], matrix[str][record + 1]);
                    /** меняю элемент столбца, совпадающий по индексу
                    с характеристикой, местами со следующим элементом столбца **/
                }
            }
        }
    }
    cout << endl;
    for (int k = 0; k < m; k++) {
        cout << records[k] << ", ";
    }
    cout << endl << "Sorted matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " | ";
        }
        cout << endl;
    }

    int *summ = new int[m];
    for (int elem = 0; elem < m; elem++) {  // перебираем элементы (столбцы) матрицы
        summ[elem] = 0;  // изначальная сумма отрицательных элементов каждого столбца матрицы
        for (int str = 0; str < n; str++) {  // перебираю "строки" матрицы
            if (matrix[str][elem] < 0) {  // если элемент в строке отрицательный
                summ[elem] += matrix[str][elem];  // сложить отрицательные элементы в столбце
            }
        }
        if (summ[elem] != 0) {
            cout << "Stolb " << elem + 1 << " = " << summ[elem] << endl;
        }
    }
}
