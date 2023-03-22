#include <iostream>

using namespace std;

struct Student {
    string name;
    string surname;
    string father_name;
    string address;
    int group;
    double rate;
};

struct Student Empty;

void create_array(Student *&obj, int amount) {
    for (int i = 0; i < amount; i++) {
        cout << "Имя, Фамилия, Отчество студента: ";
        cin >> obj[i].name >> obj[i].surname >> obj[i].father_name;
        cout << "Адрес";
        getline(cin, obj[i].address);
        cin.ignore(32767, '\n');
        cout << "Группа: ";
        cin >> obj[i].group;
        cin.ignore(32767, '\n');
        cout << "Рейтинг: ";
        cin >> obj[i].rate;
        cin.ignore(32767, '\n');
    }
}

void show_data(Student *obj, int amount) {
    cout << "№\t" << "ФИО\t\t\t\t" << "Адрес\t" << "Группа\t" << "Рейтинг\t" << endl;
    for (int i = 0; i < amount; i++) {
        cout << i << "\t" << obj[i].name << "\t" << obj[i].surname << "\t" << obj[i].father_name << "\t"
             << obj[i].address << "\t" << obj[i].group << "\t" << obj[i].rate << "\t" << endl;
    }
}

void bubble_sort(Student *arr, int amount) {
    for (int i = 0; i < amount - 1; i++) {
        // последний i элемент всегда остается на месте
        for (int j = 0; j < amount - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {  // если число больше следующего
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int search_stricture(Student *obj, int amount, double rate) {
    for (int i = 0; i < amount; i++) {
        if (obj[i].rate == rate) {
            return i;
        }
    }
    return -1;
}

void change_student(Student *&obj) {
    int c;                                              //номер записи, которую нужно изменить
    int per;
    cout << "Введите номер записи" << endl;
    cin >> c;
    c -= 1;
    do {
        cout << endl << "Введите:" << endl;
        cout << "1-для изменения имени" << endl;
        cout << "2-для изменения фамилии" << endl;
        cout << "3-для изменения отчества" << endl;
        cout << "4-для изменения адреса" << endl;
        cout << "5-для изменения группы" << endl;
        cout << "6-для изменения рейтинга" << endl;
        cout << "7-для прекращения" << endl;
        cin >> per;
        switch (per) {
            case 1:
                cout << "Введите имя студента: ";
                cin >> obj[c].name;
                break;
            case 2:
                cout << "Введите фамилию студента: ";
                cin >> obj[c].surname;
                break;
            case 3:
                cout << "Введите отчество студента: ";
                cin >> obj[c].father_name;
                break;
            case 4:
                cout << "Введите адрес студента: ";
                cin >> obj[c].address;
                break;
            case 5:
                cout << "Введите группу студента: ";
                cin >> obj[c].group;
                break;
            case 6:
                cout << "Введите рейтинг студента: ";
                cin >> obj[c].rate;
                break;
            case 7:
                return;
        }

    } while (true);

}

void delete_student(Student *&obj, int num) {
    int d;        //номер записи, которую нужно удалить
    cout << "Введите номер записи, которую необходимо удалить: " << endl;
    cout << "Если необходимо удалить все записи,нажмите '99': ";
    cin >> d;
    if (d != 99) {
        for (int i = (d - 1); i < num; i++) //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
            obj[i] = obj[i + 1]; //замещаем текущую запись следующей за ней
        num -= 1; //уменяьшаем счетчик полных записей на 1
    }
    if (d == 99) {
        for (int i = 0; i < num; i++)//цикл по все записям от первой до 30-ой
            obj[i] = Empty; //замещаем каждую структуру в массиве пустотой
    }
}

int menu() {
    int er;
    cout << "Введите:\n";
    cout << "1-для ввода массива" << endl;
    cout << "2-для сортировки" << endl;
    cout << "3-для поиска по рейтингу" << endl;
    cout << "4-для изменения" << endl;
    cout << "5-для удаления" << endl;
    cout << "6-для вывода" << endl;
    cout << "7-для выхода" << endl;
    cin >> er;
    return er;
}


int main() {

    setlocale(LC_ALL, "Russian");

    int amount;
    cout << "Сколько студентов? ";
    cin >> amount;
    auto *students = new Student[amount];

    while (true) {
        int ans = menu();
        if (ans == 1) {
            create_array(students, amount);
        } else if (ans == 2) {
            bubble_sort(students, amount);
        } else if (ans == 3) {
            double r;
            cout << "Введите рейтинг: "; cin >> r;
            int found = search_stricture(students, amount, r);
            cout << "Имя студента с рейтингом " << r << " - " << students[found].name << endl;
        } else if (ans == 4) {
            change_student(students);
        } else if (ans == 5) {
            delete_student(students, amount);
        } else if (ans == 6) {
            show_data(students, amount);
        } else {
            break;
        }

    }

    return 0;
}