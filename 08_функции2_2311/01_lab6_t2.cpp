#include <iostream>
using namespace std;

int task2_7() {
    char symbol;
    string text;
    cout << "Insert text: ";
    getline(cin, text);  // методом cin записывает с клавиатуры символы в text
    cout << "Symbol for search: ";
    cin >> symbol;
    int count = 0;
    for (int i = 0; i < text.length(); i++) {
        // .length() - возвращает длину (количество символов) в строке text
        if (text[i] == symbol) {
            count++;
        }
    }
    return count;
}