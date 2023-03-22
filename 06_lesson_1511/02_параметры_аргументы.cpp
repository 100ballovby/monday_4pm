#include <iostream>
using namespace std;

double division(double a, int b) {
    double res;  // локальная переменная (к ней нельзя получить доступ вне функции)
    if (a == 0 || b == 0) {
        return 0.0;
    } else{
        res = a / b;
    }
    return res;
}

int summ(int a, int b) {
    int res = a + b;
    return res;
}

int caller_2() {
    cout << division(12, 3) << endl;  // 12 и 3 встанут на места a и b соответственно
    cout << division(14, 0) << endl;
    cout << division(3, 12) << endl;  // аргументы позиционные - первое число передается в a, второе в b
    return 0;
}
