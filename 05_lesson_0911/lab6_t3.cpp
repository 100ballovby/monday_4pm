#include <iostream>

using namespace std;

int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

int l6_t3_2() {
    srand(time(NULL));
    int n;
    cout << "Count of teams: ";
    cin >> n;
    const int m = 5;  // в каждой команде 5 игроков
    int **teams = new int *[n];  // матрица для команд
    int *top = new int[n];  // массив для результатов
    for (int str = 0; str < n; str++) {
        teams[str] = new int[m];
        for (int elem = 0; elem < m; elem++) {
            teams[str][elem] = randint(0, 28);
            cout << teams[str][elem] << " | ";
        }
        cout << endl;
    }
    // считаем сумму очков команды
    int sum;
    for (int str = 0; str < n; str++) {
        sum = 0;
        for (int elem = 0; elem < m; elem++) {
            sum += teams[str][elem];
        }
        cout << "Score of team " << str + 1 << " is " << sum << "\n";
        top[str] = sum;
    }
    cout << endl;
    // сортируем очки по возрастанию
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (top[i] < top[j]) {
                swap(top[i], top[j]);
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "st place team has " << top[i] << " scores" << endl;
    }

}
