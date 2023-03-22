#include <iostream>
#include <string>
using namespace std;

string cows(int n) {
    string word = "коро";
    string ending;
    if (n >= 11 && n <= 14) {
        ending = "в";
    } else {
        n %= 10;
        if (n == 0 || (n >= 5 && n <= 9)) {
            ending = "в";
        } else if (n == 1) {
            ending = "вa";
        } else if (n >= 2 && n <= 4) {
            ending = "вы";
        }
    }
    word += ending;
    return word;
}

void switch_case() {
    int n, m;
    cout << "Insert n:"; cin >> n;
    cout << "Insert m:"; cin >> m;
    char symbol;
    cout << "Insert action (+, -, *, /)"; cin >> symbol;
    switch (symbol) {
        case '+':
            cout << n + m;
            break;
        case '-':
            cout << n - m;
            break;
        case '*':
            cout << n * m;
            break;
        case '/':
            cout << n / m;
            break;
        default:
            cout << "error";
            break;
    }
}

void string_basis() {
    string word = "Hello, Andrew!";
    cout << "Длина строки: " << word.length() << endl;
    for (int i = 0; i < word.length(); i++) {  // length() - возвращает количество символов в строоке
        cout << "word[" << i << "] = " << word[i] << endl;
    }
    for (char letter : word) {  // лучше для перебора использовать foreach
        cout << letter << endl;
    }
}

void string_indexes() {
    string n ("45");  // прямая инициализация строки
    // cout << n + 4; <- строки можно складывать ТОЛЬКО со строками (конкатенация)
    cout << n[0] << '2' << n[1] << endl;
    n[1] = '3';  // замена второго элемента строки
    cout << n << endl;
}

void string_cin() {
    string name, age;
    cout << "Enter your full name:";
    getline(cin, name);  // функция игнорирует пробелы и записывает через cin весь текст в переменную
    cout << "Enter your age: ";
    getline(cin, age);

    cout << "Your name is " << name << ", your age is " << age;
}

void strin_ignore() {
    string name, choice;
    cout << "Enter 1 or 2:";
    cin >> choice;
    cin.ignore(32767, '\n');  // просим cin игнорировать символ новой строки
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Your name is " << name << " you choose " << choice << endl;
}