#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    string name;
    string surname;
    string father_name;
    string address;
    string group;
    string rate;
};

void create_array(Student *&obj, int amount) {
    for (int i = 0; i < amount; i++) {
        cout << "Имя, Фамилия, Отчество, Адрес, Группа, Рейтинг студента ";
        cin >> obj[i].name >> obj[i].surname >> obj[i].father_name >> obj[i].address >> obj[i].group >> obj[i].rate;
    }
}

int task1() {
    int amount;
    cout << "Сколько студентов? ";
    cin >> amount;
    auto *students = new Student[amount];
    auto *buffer = new Student[amount];
    create_array(students, amount);

    ofstream F1("../my_file.txt", ios::binary);
    for (unsigned int i = 0; i < amount; i++) {
        F1.write((char*)&students[i].name, sizeof(students[i].name));
        F1.write((char*)&students[i].surname, sizeof(students[i].surname));
        F1.write((char*)&students[i].father_name, sizeof(students[i].father_name));
        F1.write((char*)&students[i].address, sizeof(students[i].address));
        F1.write((char*)&students[i].group, sizeof(students[i].group));
        F1.write((char*)&students[i].rate, sizeof(students[i].rate));
    }
    F1.close();

    return 0;
}
