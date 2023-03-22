#include <iostream>
#include <fstream>  // подключаем библиотеку работы с файлами
#include <cmath>

using namespace std;

void files_basics() {
    ofstream f("../my_file.txt");  // объект класса ofstream для работы с файлами сразу указываю имя файла
    f << "Я записал строчку!!!!\nЭто вторая строка";  // запись строчки в файл
    f.close();  // закрывать файл после работы. ОБЯЗАТЕЛЬНО
}

void files_getline() {
    char buffer[50];  // буфер для хранения значений, считываемых из файла
    ifstream file("../my_file.txt");  // открываем файл
    file >> buffer;  // считываем в буфер текст файла
    cout << buffer << endl;  // выводим первое слово

    file.getline(buffer, 50);  // сохраняю текст из файла в буфер
    file.close();
    cout << buffer << endl;  // выводим текст из файла
}

void rezhim_files() {
    char buffer[50];  // буфер для хранения значений, считываемых из файла
    ifstream file("../my_file", ios_base::in);  // открываем файл в режиме чтения
    /* Режимы открытия файлов
     * ios_base::in - режим чтения
     * ios_base::out - режим записи
     * ios_base::ate - при открытии перенести указатель в конец файла
     * ios_base::app - режим добавления в файл
     * ios_base::trunc - удаление всего из файла
     * ios_base::binary - открыть файл в двоичном режиме

     Режимы можно комбинировать
     ios_base::out | ios_base::trunc - открыть файл для записи, предварительно его очистив
     */
    if (!file.is_open()) {  // если файл не открыт
        cout << "File is broken!" << endl;
    } else {
        file.getline(buffer, 50);  // сохраняю текст из файла в буфер
        file.close();
        cout << buffer << endl;  // выводим текст из файла
    }
}

void file_exersize() {
    /*Записать в файл максимальные значения типов данных */
    ofstream f("datatypes.txt", ios_base::out | ios_base::trunc);
    if (!f.is_open()) {
        cout << "Error!" << endl;
    } else {
        f << "Тип\t" << "Байты\t    " << "Максимальное значение\t" << endl;
        f << "int\t" << sizeof(int) << "    " << pow(2, sizeof(int) * 8.0 - 1) << endl;
        f << "char\t" << sizeof(char) << "    " << pow(2, sizeof(char) * 8.0 - 1) << endl;
        f << "long int\t" << sizeof(long int) << "    " << pow(2, sizeof(long int) * 8.0 - 1) << endl;
        f << "double\t" << sizeof(double) << "    " << pow(2, sizeof(double) * 8.0 - 1) << endl;
    }
}

void lab_9_task1() {
    /** Создать текстовый файл F1 не менее, чем из 10 строк и
     * записать в него информацию. Скопировать из файла F1 в файл
     * F2 строки, начиная с К до К+5. **/
    srand(time(NULL));

    int size, k;
    cout << "Введите количество строк: ";
    cin >> size;
    cout << "Введите k: ";
    cin >> k;
    int *arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (100 - 1) + 1;
    }
    // создаем объект для файла, который наполним строчками
    ofstream F1("../task1.txt", ios_base::out | ios_base::trunc);
    for (int i = 0; i < size; i++) {
        F1 << arr[i] << endl;
    }
    // создаем буфер, в котором будем хранить скопированные значения из файла F1
    ifstream F1_1("../task1.txt");
    int *arr2 = new int[size];  // сам буфер (массив на 10 элементов)
    for (int i = 0; !F1_1.eof(); i++) {  // пока файл не закончился
        F1_1 >> arr2[i];  // забирать из файла строки и записывать в массив
    }

    // если значение k + 5 - больше, чем длина массива
    if ((k + 5) > size) {
        k = size - 6;  // отнимаем от длины массива 6 (индексы с 0) и записываем это значение в k
    }

    // создаем файл F2 (в который будем копировать)
    ofstream F2("../task1_f2.txt", ios_base::out | ios_base::trunc);
    for (int i = k; i < k + 5; i++) {
        F2 << arr2[i] << endl;  // загоняем в него элементы массива F2
    }
}