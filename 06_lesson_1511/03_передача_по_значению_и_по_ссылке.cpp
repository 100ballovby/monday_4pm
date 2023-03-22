#include <iostream>
using namespace std;


int pow(int n, int p) {  // здесь аргументы будут передаваться по значению
    /** Функция-аналог pow() из
     * библиотеки cmath. Получает
     * два параметра и возвращает
     * результат возведения числа n
     * в степень p **/
    int res = 1;
    for (int i = 0; i < p; i++) {
        res *= n;
    }
    return res;
}

void func(int value) {  // здесь передача по значению
    value = 7;
    // аргумент никогда не будет изменен при таком способе передачи
}

void func1(int &value) { // здесь передача по ссылке
    value = 7;
    // при вызове функции, она обратится к значению по ссылке
    // и заменит его
}

int c0() {
    int value = 6;
    cout << "value = " << value << endl;
    func(value);  // здесь аргумент НЕ будет изменен
    cout << "value = " << value << endl;
    return 0;
}

int c1() {
    int value = 6;
    cout << "value = " << value << endl;
    func1(value);  // здесь аргумент будет изменен
    cout << "value = " << value << endl;
    return 0;
}