#include <iostream>
using namespace std;

void task1_l6() {
    int length;
    cout << "Insert length of array: ";
    cin >> length;

    double *arr = new double[length]; //  память под массив будет выделена динамически
    for (int i = 0; i < length; i++) {
        cout << "Insert element " << i + 1 << ": ";
        cin >> arr[i];
    }

    double min = 0.0, f_pos = 0.0, l_pos = 0.0, summ = 0.0;
    int i_min = 0, f_pos_i = 0, l_pos_i = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] < min) {
            min = arr[i];
            i_min = i;
        }
    }
    cout << "Minimum: " << min << " Index: " << i_min << endl;
    for (int i = 0; i < length; i++) {
        if (arr[i] > 0) {
            f_pos = arr[i];
            f_pos_i = i;
            break;
        }
    }
    for (int i = length - 1; i > -1; i--) {
        if (arr[i] > 0) {
            l_pos = arr[i];
            l_pos_i = i;
            break;
        }
    }
    cout << "First positive: " << f_pos << " " << f_pos_i << endl;
    cout << "Last positive: " << l_pos << " " << l_pos_i << endl;

    for (int i = f_pos_i + 1; i < l_pos_i; i++) {
        cout << arr[i] << ", ";
        summ += arr[i];
    }
    cout << "Summ: " << summ << endl;

    delete[] arr;  // удаляем массив из памяти
    arr = nullptr;  // присваиваем нулевой указатель массиву
}