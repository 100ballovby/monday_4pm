#include <iostream>
using namespace std;


void print_array(int *array, int length) {
    /** Функция должна будет перебрать
     * массив и вывести все значения из него **/
    for (int i = 0; i < length; i++) {
        cout << array[i] << ", ";
    }
    cout << endl;
}

int с3() {
    int arr1[3] = {4, 2, 1};
    int arr2[5] = {5, 2, 7, 8, 10};

    print_array(arr1, 3);
    print_array(arr2, 5);
    return 0;
}