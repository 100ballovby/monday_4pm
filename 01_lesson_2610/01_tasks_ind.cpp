#include <iostream>
using namespace std;

void task3_7ind() {
    /* Задан одномерный числовой массив A из n
     * элементов и число k. Найти номера всех
     * элементов массива, которые равны, больше и
     * меньше k. */

    const int n = 7;
    int k;
    int arr[n];
    cout << "Insert k: " << endl;
    cin >> k;
    for (int i = 0; i < n; i++) {
        // arr[i] = rand() % 1000 + 10 / 2; <- наполнение случайными числами
        cout << "Insert arr[" << i << "] = ";
        cin >> arr[i];
        //cout << arr[i] << ", ";
    }
    cout << endl;
    for (int j = 0; j < n; j++) {
        if ((arr[j] > k)) {
            cout << "Index: " << j << " > " << k << endl;
        } else if (arr[j] < k) {
            cout << "Index: " << j << " < " << k << endl;
        } else if (arr[j] == k) {
            cout << "Index: " << j << " == " << k << endl;
        }
    }
}

void task3_8ind() {
    /* Даны массивы A из n элементов и B
     из m элементов. Содержится ли
     наибольший элемент массива A в массиве B? */
    const int n = 4, m = 5;
    int A[n], B[m];
    int max;

    for (int i = 0; i < n; i++) {
        cout << "Insert A[" << i << "] = ";
        cin >> A[i];
    }
    for (int i = 0; i < m; i++) {
        cout << "Insert B[" << i << "] = ";
        cin >> B[i];
    }
    // находим наибольший
    max = A[0];
    for (int j = 0; j < n; j++) {
        if (A[j] > max) {
            max = A[j];
        }
    }
    cout << "Max of A is " << max << endl;
    // определяем, находится ли максимум во втором массивe
    for (int k = 0; k < m; k++) {
        if (B[k] == max) {
            cout << "Yes!" << endl;
            break; // принудительный выход из цикла
        }
    }

}

void task4() {
    /* В массиве из 25 элементов найти номер первого
     отрицательного элемента и первого положительного
     элемента. Значение элементов и их порядковый
     номер вывести на экран. Заменить найденный
     отрицательный элемент в массиве на их
     произведение (отрицательного и положительного),
     а отрицательный на сумму. */
    int array[25];
    int first_negative, first_positive;
    bool found_pos, found_neg;
    int i = 0;
    found_pos = false;
    found_neg = false;

    for (int k = 0; k < 25; k++) {
        array[k] = rand() % 100;  // <- наполнение случайными числами
        cout << array[k] << ", ";
    }
    cout << endl << endl;
    while (i < 7 && !found_neg || !found_pos) {
        if (array[i] < 0) {
            found_neg = true;
            first_negative = i;
        }
        else if (array[i] > 0) {
            found_pos = true;
            first_positive = i;
        }
        i++;
    }
    cout << "First neg index = " << first_negative << "\nValue = " << array[first_negative] << endl;
    cout << "First pos index = " << first_positive << "\nValue = " << array[first_positive] << endl;
    array[first_negative] = array[first_positive] * array[first_negative];
    array[first_positive] = array[first_positive] + array[first_negative];

    for (int num : array) {
        cout << num << ", ";
    }

}

int mm() {
    srand(unsigned(time(NULL)));  // числа не будут повторяться при генерации

    return 0;
}
