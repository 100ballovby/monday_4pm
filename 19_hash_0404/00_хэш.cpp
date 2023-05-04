#include <iostream>
#include <ctime>
using namespace std;

const int TABLE_SIZE = 10;  // размер таблицы (общий)
const int STACK_SIZE = 5;  // размер стеков

int has_main() {
    int table[TABLE_SIZE][STACK_SIZE];
    int hash[TABLE_SIZE];

    srand(time(NULL));

    // заполним хеш таблицу значениями
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < STACK_SIZE; j++) {
            table[i][j] = rand() % 100;
        }
        hash[i] = table[i][0];  // в качестве хеш значения берем первый элемент в стеке
    }

    int min_stack = 0;
    for (int i = 1; i < TABLE_SIZE; i++) {
        if (hash[i] < hash[min_stack]) {
            min_stack = i;
        }
    }

    cout << "Hash table: ";
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < STACK_SIZE; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Stacks: ";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << hash[i] << " ";
    }
    cout << "\n\n";
    cout << "Min stack: " << min_stack << endl;
}
