#include <iostream>
using namespace std;

int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

void dynamic_array() {
    int len;
    cout << "Insert length of array: ";
    cin >> len;
    int *d_array = new int[len];
    // *d_array - это указатель на создание нового динамического массива

    srand(time(NULL));  // обновляем "случайность"
    for (int i = 0; i < len; i++) {  // повторить 10 раз
        d_array[i] = randint(0, 100);  // сгенерировать случайное число от -100 до 100
        cout << d_array[i] << ", ";
    }
}

void lab5_t1() {
    int matrix[3][5] = {
            {7, 3, 1, 10, 15,},
            {6, 2, 0, -10, 7},
            {50, 20, 10, 100, -2},
    };
    int i_max, i_min, max, min;
    for (int stroka = 0; stroka < 3; stroka++) {
        i_max = 0;
        i_min = 0;
        max = matrix[stroka][0];
        min = matrix[stroka][0];
        for (int elem = 0; elem < 5; elem++) {
            if (matrix[stroka][elem] > max) {
                i_max = elem;
                max = matrix[stroka][elem];
            }
            if (matrix[stroka][elem] < min) {
                i_min = elem;
                min = matrix[stroka][elem];
            }
        }
        cout << "Str: " << stroka << "Index of max " << i_max << endl;
        cout << "Str: " << stroka << "Index of min " << i_min << endl;
        matrix[stroka][i_max] = min;
        matrix[stroka][i_min] = max;
    }
    for (int i = 0; i < 3; i++) {  // перебираю строчки матрицы
        for (int j = 0; j < 5; j++) {  // перебираю элементы строки матрицы
            cout << matrix[i][j] << ", ";  // вывожу элементы одной строки
        }
        cout << endl; // новая строка матрицы будет выводить с новой строчки
    }

    int summ = 0;
    for (int i = 0; i < 3; i++) {
        summ += matrix[i][i];
    }
    cout << summ << endl;
}