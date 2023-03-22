#include <iostream>
using namespace std;

int factorial(int n) {  // объявляю функцию factorial с параметром n
    int factorial = 1;
    for (int i = 1; i <= n; i++) {  // циклом перебираю числа от 1 до n
        factorial *= i;  // перемножаю каждое число
    }
    return factorial;  // возворащаю результат
}

void factorial_procedure() {
    // вариант решения без функции
    int factorial = 1;
    int n;
    cout << "Insert n: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    cout << factorial << endl;
}

int m() {
    int fact;
    fact = factorial(6);  // функция factorial вернет результат в переменную fact
    cout << "6! = " << fact << endl;

    // найти факториалы чисел от 2 до 10
    for (int i = 2; i <= 10; i++) {
        cout << i << "! = " << factorial(i) << endl;
    }
    return 0;
}