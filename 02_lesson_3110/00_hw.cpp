#include <iostream>
using namespace std;

void task_2_hw() {
    int n, thousands, hundreds, tens, units;
    tryAgain:  // метка возврата
    cout << "Insert 4-digit number: ";
    cin >> n;
    if (n >= 1000 && n <= 9999) {
        thousands = n / 1000;  // 2385 / 1000 = 2
        hundreds = n % 1000 / 100;  // 2385 % 100 = 385, 385 / 100 = 3
        tens = n % 100 / 10;  // 2385 % 100 = 85, 85 / 10 = 8
        units = n % 10;  // 2385 % 10 = 5
        cout << thousands + hundreds + tens + units << endl;
    } else {  // если проверка дала false
        goto tryAgain;  // вернуться в метку tryAgain
    }
}

int task_3(int n) {
    // количество нечетных чисел от 1 до n (не включая n) всегда равно n / 2
    return n / 2;
}

void task_4() {
    int thousands, hundreds, tens, units;
    for (int i = 1000; i < 10000; i++) {
        thousands = i / 1000;  // 2385 / 1000 = 2
        hundreds = i % 1000 / 100;  // 2385 % 100 = 385, 385 / 100 = 3
        tens = i % 100 / 10;  // 2385 % 100 = 85, 85 / 10 = 8
        units = i % 10;  // 2385 % 10 = 5
        if (thousands + hundreds + tens + units == 15) {
            cout << i << ", ";
        }
    }
}

void task_6() {
    int arr[] = {2, 3, 0, 5, 1, 1, 1, 3, 45, 0, 6, 7};
    int f_zero, l_zero, sum;
    bool zero_found = false;
    for (int i = 0; i < 12; i++) {
        if (arr[i] == 0 && !zero_found) {
            zero_found = true;
            f_zero = i;
        }
        if (arr[i] == 0) {
            l_zero = i;
        }
    }
    cout << "First zero index is: " << f_zero << endl;
    cout << "Last zero indes is: " << l_zero << endl;
    sum = 0;
    for (int i = f_zero; i < l_zero; i++) {
        sum += arr[i];
    }
    cout << sum << endl;
}

void task_7_fix_me() {
    int arr[] = {3, 5, 10, 4, 0, 0, 5, 0, 7, 0, 3, 4, 5, 0, 12, 0};
    int len = sizeof(arr) / sizeof(arr[0]);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] == 0) {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < len; i++) {
        if (arr[i] != 0) {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int key : arr) {
        cout << key << ", ";
    }
}

void task_8() {
    int arr[5] = {8, 2, 3, 0, 9};
    for (int i = 4; i > -1; i--) {
        cout << arr[i] << ", ";
    }
}