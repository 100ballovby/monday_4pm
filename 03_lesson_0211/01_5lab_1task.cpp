#include <iostream>
#include <cmath>
using namespace std;

double randint(double min, double max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return (double)rand() / max * (max - min) + min;
}

void lab5_t1() {
    int n, m;
    cout << "Insert n: ";
    cin >> n;
    cout << "Insert m: ";
    cin >> m;
    /* Указатель - это объект, значение которого -
     * это ссылка на другие объекты. Они применяются для косвенного
     * доступа к объектам, на которые ссылаются */
    auto **matrix = new double *[n];  // тип данных матрицы будет определен по типу данных подмассивов
    /* первая звездочка перед matrix указывает на
     * главный массив (оборачивающий / шкаф), а вторая на
     * подмассивы (полочки в шкафу), которые будут
     * сгенерированы в этой матрице */
    cout << "Matrix start: " << endl;
    for (int str = 0; str < n; str++) {
        matrix[str] = new double[n];  // создаем новую строчку матрицы
        for (int el = 0; el < m; el++) {
            // каждую строчку наполняем элементами
            matrix[str][el] = randint(1.2, 99.5);
            cout.precision(5);  // ограничивает количество знаков после десятичной точки
            cout << matrix[str][el] << ", ";
        }
        cout << endl;
    }
    cout << "Matrix edited: " << endl;
    int i_max, i_min, max, min;
    for (int stroka = 0; stroka < n; stroka++) {
        i_max = 0;
        i_min = 0;
        max = matrix[stroka][0];
        min = matrix[stroka][0];
        for (int elem = 0; elem < m; elem++) {
            if (matrix[stroka][elem] > max) {
                i_max = elem;
                max = matrix[stroka][elem];
            }
            if (matrix[stroka][elem] < min) {
                i_min = elem;
                min = matrix[stroka][elem];
            }
        }
        cout << "Str: " << stroka << ", Index of max " << i_max << endl;
        cout << "Str: " << stroka << ", Index of min " << i_min << endl;
        matrix[stroka][i_max] = min;
        matrix[stroka][i_min] = max;
    }
    for (int i = 0; i < n; i++) {  // перебираю строчки матрицы
        for (int j = 0; j < m; j++) {  // перебираю элементы строки матрицы
            cout << matrix[i][j] << ", ";  // вывожу элементы одной строки
        }
        cout << endl; // новая строка матрицы будет выводить с новой строчки
    }

    double summ = 0;
    for (int i = 0; i < n; i++) {
        summ += matrix[i][i];
    }
    cout << summ << endl;

    // очистка памяти
    for (int str = 0; str < n; str++) {  // прохожусь по строчкам
        delete [] matrix[str];  // удаляю каждую строчку матрицы
    }
    delete [] matrix;  // удаляю матрицу
}