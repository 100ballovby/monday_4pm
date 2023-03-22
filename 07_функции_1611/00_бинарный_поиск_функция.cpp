#include <iostream>

using namespace std;

int binary_search(int *arr, int length, int key) {
    /** Бинарный поиск элемента в массиве.
     * Постоянно делим массив на две части,
     * пока в середине массива не окажется число,
     * которое мы пытаемся найти. **/
    int low, high, mid;
    low = 0;
    high = length - 1;  // если в массиве 5 элементов, последний элемент имеет индекс 4, поэтому от длины массива отнимем 1
    mid = low + (high - low) / 2;
    while (arr[mid] != key || low != high) {
        // пока границы массива не схлопнулись ИЛИ пока мы не нашли число в массиве
        if (key > arr[mid]) {  // если число больше "среднего"
            low = mid + 1;  // сдвинуть левую границу вправо
        } else if (key < arr[mid]) {  // если число меньше "среднего"
            high = mid - 1;  // сдвинуть правую границу влево
        } else {
            return mid;
        }
        mid = low + (high - low) / 2;  // пересчитываем с каждым повторением mid
    }
}


int bivshiy_main() {
    const int len = 12;
    int arr[len] = {-4, 1, 2, 5, 7, 9, 12, 13, 52, 62, 78, 81};
    int key;
    cout << "Key: "; cin >> key;
    cout << binary_search(arr, len, key) << endl;
    return 0;
}