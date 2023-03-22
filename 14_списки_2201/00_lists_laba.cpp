#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string address;
    int group;
    double rate;
};

struct Node {
    Student data;
    Node *next;
};

Node *head = nullptr;

void insertStudent(Student student);
void deleteElement();
void displayList();
int countList();
int findMax();
int findMin();
void deleteDouble();
void deleteList();
int menu();

int zapuskai() {
    insertStudent({"Ivan Ivanov", "K7, b2", 30, 6.7});
    insertStudent({"", "", 0, 0});
    insertStudent({"", "", 0, 0});
    return 0;
}

int menu() {
    int er;
    cout << "Введите:\n";
    cout << "1-для добавления студента в список" << endl;
    cout << "2-для удаления студента из списка" << endl;
    cout << "3-для выхода" << endl;
    cin >> er;
    return er;
}

void insertStudent(Student student) {
    Node *newNode = new Node;
    newNode->data = student;
    newNode->next = head;
    head = newNode;
}

void displayList() {
    Node *tmp = head;
    while (tmp != nullptr) {
        cout << "Full name: " << tmp->data.name << endl;
        cout << "Address: " << tmp->data.address << endl;
        cout << "Group: " << tmp->data.group << endl;
        cout << "Rate: " << tmp->data.rate << endl;
    }
}

