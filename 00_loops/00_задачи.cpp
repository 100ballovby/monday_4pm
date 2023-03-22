#include <iostream>
using namespace std;

void arrays_basics() {
    int marks[5];  // объявление целочисленного фиксированного массива
    double scores[] = {1.23, 5.6, 10.2, 3.49, 3.15};  // инициализцая фиксированного массива дробей
    // при инициализации фиксированного массива длину можно не указывать
    cout << sizeof(marks) << endl;  // размер массива в битах
    cout << sizeof(marks) / sizeof(marks[0]) << endl; // размер массива в элементах
    // ^ только для статических массивов
}

void arrays_loops() {
    int const len = 5;  // переменная-длина массива
    int marks[len];  // объявление целочисленного фиксированного массива
    double scores[] = {1.23, 5.6, 10.2, 3.49, 3.15};

    int length = sizeof(marks) / sizeof(marks[0]);

    for (int i = 0; i < length; ++i) {  // перебор массива по индексам
        cout << "scores["<< i << "] = "<<  scores[i] << endl;
    }
    cout << endl;
    for (double element : scores) {  // перебор массива по элементам
        cout << element << endl;
    }
}

void task_1() {
    int n, t, k;
    cout << "Insert n: ";
    cin >> n;
    double numbers[n], max, min, summ, mult;
    for (int i = 0; i < n; ++i) {
        double element;
        cout << "Insert " << i << ": ";
        cin >> element;
        numbers[i] = element;
    }

    max = numbers[0];
    min = numbers[0];
    for (int i = 0; i < n; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
            t = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            k = i;
        }
    }


    max = numbers[0];
    for (int i = 1; i < n; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
            k = i;
        }

    }

    min = numbers[0];
    for (int i = 1; i < n; i++)
    {
        if (min > numbers[i])
        {
            min = numbers[i];
            t = i;
        }
    }
    numbers[t] = max;
    numbers[k] = min;
    cout << "max = " << max << " " << k << endl;
    cout << "min = " << min << " " << t << endl;

    summ = 0;
    mult = 1;
    for (double elem : numbers) {
        cout << elem << ", ";
        summ += elem;
        mult *= elem;
    }
    cout << endl;
    cout << "summ = " << summ << endl;
    cout << "mult = " << mult << endl;
}

void task_7_ind() {
    /* 7.	В одномерном массиве, состоящем из вещественных элементов, вычислить:
    - количество элементов массива, больших С;
    - произведение элементов массива, расположенных после максимального по модулю элемента
    */
    int n, count, abs_index;
    cout << "Insert n: ";
    cin >> n;
    double numbers[n], c, abs_max, mult;
    for (int i = 0; i < n; ++i) {
        double element;
        cout << "Insert " << i << ": ";
        cin >> element;
        numbers[i] = element;
    }
    cout << "Insert C: ";
    cin >> c;
    count = 0;
    for (double elem : numbers) {
        if (elem > c) {
            count += 1;
        }
    }
    cout << "Count of elements greater than " << c << " is " << count << endl;

    // произведение элементов стоящих после максимального по модулю
    abs_max = numbers[0];
    for (int i = 1; i < n; i++)
    {
        if (numbers[i] < 0) {
            numbers[i] = numbers[i] * -1;
        }
        if (numbers[i] > abs_max) {
            abs_max = numbers[i];
            abs_index = i;
        }
    }
    cout << "Absolute max: " << abs_max << "\nIndex of max = " << abs_index << endl;
    mult = 1;
    cout << "New array: " << endl;
    for (int j = abs_index; j < n; j++) {
        cout << numbers[j] << ", ";
        mult *= numbers[j];
    }
    cout << endl;
    cout << "Multiplication of elements that greater than absolute max is " << mult << endl;
}
