#include <iostream>
using namespace std;

struct Person {  // объявление структуры Person
    short age;
    string name;
    double height;
    double weight;
};

struct Car {
    // обязательные параметры
    string brand;
    string model;
    string engine;
    // в структуре элементам можно задавать значения по умолчанию
    string color = "red";
};

void structure_and_elements() {
    Person Demid; // создал человека на основе данных структуры
    Demid.age = 13;  // обращаюсь к члену структуры и присваиваю ему значение
    Demid.name = "Demid";
    Demid.height = 164.5;
    Demid.weight = 75.5;

    Person Valerka;
    Valerka.name = "Valera";
    Valerka.age = 40;
    Valerka.height = 178;
    Valerka.weight = 85.6;

    int ages = Valerka.age + Demid.age;
    cout << "Валерке и Демиду " << ages << " лет." << endl;
}

int запускать_это() {
    // инициализирую структуру
    Person Vitalka = {36, "Vitaliy", 169, 96};  // 36 - age, "Vitaliy" - name, 169 - height, 96 - weight

    // создаю на основе структуры машину (цвет останется красным)
    Car mercedes_s = {"Mercedes-Benz", "S-class", "petrol"};
    cout << mercedes_s.model << endl;
    cout << mercedes_s.engine << endl;
    cout << mercedes_s.color << endl;
    return 0;
}