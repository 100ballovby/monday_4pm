#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Student {
    string name = "";
    string surname = "";
    string father_name = "";
    string address = "";
    string group = "";
    double rate = 0.0;
};

int i, j; // объявлена глобальная переменная, чтобы каждый раз не объявлять ее в функции
Student *student = 0; // массив структур с данными
int SIZE = 0; // размер массива

void add_student() { // добавляет в постоянный массив структур элемент и пользователь вводит данные
    SIZE++; // наш размер увеличивается на 1, т.к. мы добавляем элемент в массив
    if (SIZE == 1) { // если это первый элемент, нам ничего копировать не нужно, и мы просто выделяем память под новую структуру
        student = new Student[SIZE];
    } else { // если это не первый элемент, нужно скопировать уже имеющиеся данные и выделить память под новую структуру
        // реализация C++ vector без vector
        Student *temp_student = new Student[SIZE]; // создаем временный массив структур нового размера (как у вектора)
        for (i = 0; i < SIZE - 1; ++i) {
            temp_student[i] = student[i]; // копируем в него данные из постоянного массива структур старого размера
        }
        delete[] student; // удаляем постоянный массив структур старого размера
        student = temp_student; // получаем постоянный массив структур нового размера
    }
    cout << "Name: ";
    getline(cin, student[SIZE - 1].name); // вводим в новую структуру постоянного массива структур новые данные
    cout << "Surname: ";
    getline(cin, student[SIZE - 1].surname); // вводим в новую структуру постоянного массива структур новые данные
    cout << "Father name: ";
    getline(cin, student[SIZE - 1].father_name); // вводим в новую структуру постоянного массива структур новые данные
    cout << "Address: ";
    getline(cin, student[SIZE - 1].address); // вводим в новую структуру постоянного массива структур новые данные
    cout << "Group: ";
    getline(cin, student[SIZE - 1].group); // вводим в новую структуру постоянного массива структур новые данные
    cout << "Rate: ";
    cin >> student[SIZE - 1].rate;
    cin.get();/* после введения данных через "cin" остается символ перевода строки "\n", который "съедает" последующий
		"getline()" и мы не можем ввести свою строку. cin.get() сам "съест" символ перевода строки "\n" и ввод строки удастся */

}

void show_database() // выводит на экран базу данных, тут все легко
{
    cout << "===================================================================" << endl;
    cout << "\tName\t\tSurname\t\tFather name\t\t\tAddress\t\tGroup\tRate" << endl;
    for (i = 0; i < SIZE; ++i) // цикл
        cout << i + 1 << "\t" << student[i].name << "\t\t" << student[i].surname  << "\t\t" << student[i].father_name
             << "\t\t" << student[i].address << "\t\t" << student[i].group << "\t\t\t" << student[i].rate
             << endl; // вывод данных
    cout << "===================================================================" << endl;
}

void save_data() { // сохраняет данные в файл базы данных
    ofstream data("../database.txt"); // открываем файл базы данных для записи данных в него
    for (i = 0; i < SIZE; ++i) // цикл записи данных в файл базы данных
    {
        if (i != SIZE - 1) // если это не последняя струтура в постоянном массиве структур, то...
        {
            data << student[i].name << endl;
            data << student[i].surname << endl;
            data << student[i].father_name << endl;
            data << student[i].address << endl;
            data << student[i].group << endl;
            data << student[i].rate << endl; // здесь будет перенос строки
        } else // а если это последняя структура в постоянном массиве структур, то...
        {
            data << student[i].name << endl;
            data << student[i].surname << endl;
            data << student[i].father_name << endl;
            data << student[i].address << endl;
            data << student[i].group << endl;
            data << student[i].rate; /* здесь не будет переноса строки, т.к. в будущем нам надо будет загружать данные
				из файла базы данных в программу, и при считывании он будет считывать пустую строку, а нам этого не надо*/
        }
    }
    data.close(); // закрываем файл базы данных
    cout << "Your data has been saved" << endl;
}

void load_data() {
    i = 1; // здесь i - это счетчик строк. посчитаем строки и вычислим количество структур массива, под который нужно выделить память
    string str; // строка, которую мы будем считывать и считать с помощью i
    ifstream data("../database.txt"); // открываем файл базы данных для записи данных из него
    for (data >> str; !data.eof(); data >> str) { // цикл, считывающий строки, пока файл не закончится
        i++; // счетчик строк увеличивается на 1 с каждой считанной строкой
    }
    SIZE = i / 6; // каждые 6 строк - это одна структура: потому что в структуре 6 элементов
    student = new Student[SIZE]; // выделяем память под нужное количество структур
    data.seekg(0); // возвращаемся в начало файла
    for (i = 0; i < SIZE; i++) {  // цикл, передающий данные из файла в наш постоянный массив структур
        getline(data, student[i].name);
        getline(data, student[i].surname);
        getline(data, student[i].father_name);
        getline(data, student[i].address);
        getline(data, student[i].group);
        data >> student[i].rate; // считываем рейтинг
        data.get(); // аналогично cin.get()
    }
    data.close(); // закрываем файл базы данных
    cout << "Your data has been loaded" << endl;
}



int task2() {
    int act = 2; // 5 действий доступно в программе
    do {
        if (act == 1)
            add_student(); // добавить самолет в базу данных
        else if (act == 2)
            show_database(); // вывести на экран базу данных (не из файла, а из массива)
        else if (act == 3)
            save_data(); // сохранить данные в промежуточном массиве
        else if (act == 4)
            load_data(); // загрузить все в файл
        else if (act != 5) // если введенное число не имеет смысла в рамках нашего выбора действий, то...
        {
            cout << "This action isn`t available, please, try again" << endl; // ошибка :(
        }
        cout << "==================================" << endl;
        cout << "\tSTUDENTS" << endl;
        cout
                << "1 - add student\n2 - show database\n3 - save data\n4 - load data\n7 - exit"
                << endl;
        cout << "==================================" << endl;
        cin >> act; // выбор действия
        cin.get();
    } while (act != 5); // пока мы не введем 5, что значит "Выход", цикл будет продолжаться
    return 0;
}