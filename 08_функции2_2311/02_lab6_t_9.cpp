// задачи на 9 баллов.
#include <iostream>
using namespace std;


bool check_palindromes(string word) {
    int n = word.length();
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    if (n > 2) {  // если в слове более трех букв
        for (int i = 0; i < n; i++, n--) {
            if (word[i] != word[n - 1]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }

}


int count_palindromes(string str) {
    // так как все слова разделены пробелами, то для проверки
    // последнего слова добавляю в конце еще один пробел
    str += " ";  // конкатенация - сложение строк

    // делаю переменную, в которой буду хранить слова
    string word = "";
    int count = 0;  // переменная считает палиндромы
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        // слова разделены пробелами, поэтому я проверяю, что символ,
        // который я просматриваю, пробелом не является
        if (ch != ' ')
            word += ch;
        else {  // если встретился пробел (я дошел до конца слова)
            if (check_palindromes(word)) {  // вызываю функцию проверки слова на палиндром
                count++;  // считаю его
            }
            word = "";  // очищаю переменную для следующего слова
        }
    }

    return count;
}

void eto_main() {
    cout << count_palindromes("kazak sdelal zakaz i zakazal komok") << endl;
}