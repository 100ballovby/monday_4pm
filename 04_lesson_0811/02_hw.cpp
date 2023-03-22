#include <iostream>
using namespace std;

double *give_memory(double *ptr_arr, int size) { // указатель на функцию
    ptr_arr = new double[size];  // инициализировал динамический массив длиной size
    return ptr_arr;  // передал массив из функции
}

void fill_array(double *ptr_arr, int size) {
    double elem;
    for (int i = 0; i < size; i++) {
        cout << "Введите n: ";
        cin >> elem;
        ptr_arr[i] = elem;
    }
}

void show_array(double *ptr_arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << ptr_arr[i] << ", ";
    }
    cout << endl;
}

void zapuskator() {
    int length;
    cout << "Insert array length: ";
    cin >> length;
    double arr[length];
    give_memory(arr, length);
    fill_array(arr, length);
    show_array(arr, length);
}
