#include <iostream>
using namespace std;

int randint(int min, int max) {
    int r = rand() % (max - min) + min;
    return r;
}

/** нужно написать функцию, которая создаст
 динамический одномерный массив. И функцию, которая
 наполнит его случайными числами **/

int *fill_array(int *arr, int size, int l_border=0, int r_border=2) {  // два параметра заданы по умолочанию. Это значит, что их можно не передавать
    arr = new int [size];  // инициализировал динамический массив длиной size
    for (int i = 0; i < size; i++) {
        arr[i] = randint(l_border, r_border);
        cout << arr[i] << ", ";
    }
    cout << endl;
    return arr;  // передал массив из функции по адресу из параметра
}


int с4() {  // бывший main
    srand(time(0));
    int length;
    cout << "Array length: " << endl;
    cin >> length;
    int arr[length];
    int arr1[length];
    int arr2[length];

    fill_array(arr, length, -100, 100);
    fill_array(arr1, length, -10, 10);
    fill_array(arr2, length);
    return 0;
}