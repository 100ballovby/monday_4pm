#include <iostream>
using namespace std;

int randint(int min, int max) {
    // функция генерирует случайные целые числа в диапазоне от
    // min до max
    return rand() % (max - min) + min;
}

// task 1 ex 7
void create_matrix(int **&matrix, int n, int m) {
    /** Передаю матрицу как указатель на адрес ее
     * ячейки. Когда функция будет запущена, она
     * найдет матрицу по адресу, наполнит ее и
     * сохранит результат в той ячейке, которая указана
     * как параметр функции. **/
    matrix = new int *[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) {
            matrix[i][j] = randint(0, 10);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void task1_5(int **&matrix, int n, int m) {
    int line = -1; // строка с нулевым элементом
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0 && line == -1) {
                line = i;
                break;
            }
        }
    }

    cout << "Номер строки : " << line << endl;
    cout << "Первый элемент найденной строки: " << matrix[line][0] << endl;
    int a = matrix[line][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] -= a;
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
// task 1 ex 7 END

// task 2 ex 7
int task2_7(char symbol, string text) {
    int count = 0;
    for (int i = 0; i < text.length(); i++) {
        // .length() - возвращает длину (количество символов) в строке text
        if (text[i] == symbol) {
            count++;
        }
    }
    return count;
}
// task 2 ex 7 END

// task 3 ex 3
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
// task 3 ex 3 END

// task 3 ex 8
string longest_word(string str) {
    // так как все слова разделены пробелами, то для проверки
    // последнего слова добавляю в конце еще один пробел
    str += " ";  // конкатенация - сложение строк

    string word ("");  // здесь храним каждре отдельное слово из текста
    string longest_word ("");  // здесь сохраним самое длинное слово
    int max_length = 0;  // считаем длину самого длинного слова

    for (int i = 0; i < str.length(); i++) {  // перебираю каждый символ текста
        char ch = str[i];  // сохраняю этот символ в переменной

        // слова разделены пробелами или знаками препинания,
        // поэтому я проверяю, что символ, который я просматриваю,
        // не является этими знаками (слово заканчивается на пробеле или знаке препинания
        if (ch != ' ' && ch != ',' && ch != '!' && ch != '?' && ch != '.')
            word += ch;  // добавляю символ в переменную word (выдираю слово)
        else {  // если встретился пробел или знак препинания (я дошел до конца слова)
            if (word.length() > max_length) {  // если слово длиннее максимального
                max_length = word.length();  // записываю длину строки
                longest_word = word;  // записываю это слово как самое длинное
            }
            word = "";  // очищаю переменную для следующего слова
        }
    }

    return longest_word;
}
// task 3 ex 8 END

// task 3 ex 9
int count_words(string str) {
    // так как все слова разделены пробелами, то для проверки
    // последнего слова добавляю в конце еще один пробел
    str += " ";  // конкатенация - сложение строк

    string word ("");  // здесь храним каждре отдельное слово из текста
    int count = 0;  // считаем слова
    char first_letter, last_letter;

    for (int i = 0; i < str.length(); i++) {  // перебираю каждый символ текста
        char ch = str[i];  // сохраняю этот символ в переменной

        // слова разделены пробелами или знаками препинания,
        // поэтому я проверяю, что символ, который я просматриваю,
        // не является этими знаками (слово заканчивается на пробеле или знаке препинания
        if (ch != ' ' && ch != ',' && ch != '!' && ch != '?' && ch != '.')
            word += ch;  // добавляю символ в переменную word (выдираю слово)
        else if (word.length() > 1) {  // если встретился пробел или знак препинания (я дошел до конца слова)
            first_letter = word[0];  // сохраняю первую букву
            last_letter = word[word.length() - 1];  // сохраняю последнюю
            if (first_letter == last_letter) {
                count++;
            }
            word = "";  // очищаю переменную для следующего слова
        }
    }

    return count;
}
// task 3 ex 9 END



int функция_main() {
    srand(time(NULL));
    int task = -1;

    while (task != 0) {
        cout << "Insert task number (1, 2 or 3) or insert another number to exit: ";
        cin >> task;

        if (task == 1) {
            int m, n;
            cout << "Insert rows: ";
            cin >> n;
            cout << "Insert cols: ";
            cin >> m;

            int **matrix;  // инициализируем указатель на матрицу
            create_matrix(matrix, n, m);
            task1_5(matrix, n, m);
        }
        else if (task == 2) {
            char symbol;
            string text;
            cout << "Symbol for search: ";
            cin >> symbol;
            cin.ignore(32767, '\n');

            cout << "Insert text: ";
            getline(cin, text);  // методом cin записывает с клавиатуры символы в text

            cout << task2_7(symbol, text) << endl;
        }
        else if (task == 3) {
            // вызов функции задания 1
            cout << "Самое длинное слово в тексте \n'Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.': " << endl;
            cout << longest_word("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt.") << endl;

            cout << endl << endl;
            cout << "Посчитать палиндромы в тексте: \n'kazak sdelal zakaz i zakazal komok':" << endl;
            cout << count_palindromes("kazak sdelal zakaz i zakazal komok") << endl;

            cout << endl << endl;
            cout << "Посчитать слова с одинаковыми первыми и последними буквами: \n'kazak sdelal zakaz i zakazal komok':" << endl;
            cout << count_words("kazak sdelal zakaz i zakazal komok") << endl;
        }
        else {
            task = 0;
        }
    }
    cout << "Thanks for watching!";

    return 0;
}