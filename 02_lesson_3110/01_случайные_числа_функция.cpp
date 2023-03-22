#include <iostream>
using namespace std;


int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

void zapusk_randint() {
    srand(time(NULL));  // обновляем "случайность"
    for (int i = 0; i < 10; i++) {  // повторить 10 раз 
        cout << randint(-100, 100) << ", ";  // сгенерировать случайное число от -100 до 100 
    }
}