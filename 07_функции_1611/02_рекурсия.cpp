#include <iostream>

using namespace std;

int randint(int min, int max) {
    int r = rand() % (max - min) + min;
    return r;
}

int print(int n) { // рекурсивная функция вызывает себя до наступления какого-то события (но без цикла)
    if (n < 0) {  // базовый случай (условие выхода из рекурсии)
        return -1;
    } else if (n < 1) {  // базовый случай (условие выхода)
        return 1;
    } else {  // рекурсивный случай (условие повторения)
        cout << "push " << n << endl;
        return print(n - 1);
    }
}

// напишем функцию, которая вычисляет сумму всех чисел между 1 и n
int sumOf(int value) {
    if (value < 0) {  // сумму между 1 и отрицательным числом посчитать нельзя
        return 0;  // останавливаю функцию (базовый случай) и возвращаю 0
    } else if (value == 1) {  // сумма цифр ОТ 1 ДО 1 = 1
        return 1;  // поэтому возвращаю 1
    } else {
        return sumOf(value - 1) + value;
    }
}

void fib_nums() {  // числа фибоначчи без рекурсии
    int n, summ, i = 0, i1 = 0, i2 = 1;
    cout << "N = ";
    cin >> n;  // количество чисел в ряду Фибоначчи

    while (i < n) {
        // Ряд Фибоначчи - последовательность, в котороой каждый следующий элемент равен сумме двух предыдущих
        cout << i1 << ", ";  // начинаю с 0
        summ = i1 + i2;  // считаю сумму двух предыдущих элементов
        i++;  // i увеличиваю, чтобы вывести необходимое количество чисел
        i1 = i2;  // результат - получившееся число
        i2 = summ;  // присваиваем сумму двух предыдущих
    }
}

int fibonacci(int number) {  // числа фибоначчи с рекурсией
    if (number == 0) {
        return 0;
    } else if (number == 1) {
        return 1;
    } else {
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}

int factorial(int n) {
    int factorial = 1;
    for (int i = n; i > 1; i--) {
        factorial *= i;
    }
    return factorial;
}

int recurs_factorial(int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 1;
    } else {
        return n * recurs_factorial(n - 1);  // factorial *= i;
    }

}


int ne_main() {
    for (int i = 0; i <= 10; i++) {
        cout << i << "! = " << recurs_factorial(i) << endl;
    }
    return 0;
}