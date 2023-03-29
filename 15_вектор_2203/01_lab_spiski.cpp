#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Stud {
    string name;
    string address;
    int group;
    double rate;
};

struct ListNode {
    Stud data;
    ListNode *next;
};

ListNode *createNode(const Stud &data) {
    auto node = new ListNode;
    node->data = data;
    node->next = nullptr;
    return node;
}

void addNode(ListNode *&head, const Stud &data) {
    auto node = createNode(data);
    if (head == nullptr) {  // если дырка от мешка пустая
        head = node;  // засунуть туда студента
    } else if (data.name < head->data.name) {
        node->next = head;  // вставляем перед первым студентом
        head = node;
    } else {  // если там что-то есть
        auto current = head;  // то, что там лежит сохраняем в переменную
        while (current->next != nullptr) {  // пока студенты в мешке не закончились
            current = current->next;  // "текущий студент" - это тот, что лежит после того, которого мы достали
        }
        current->next = node;  // следующий студент кладется на дно мешка
    }
}

void showList(ListNode *head) {
    while (head != nullptr) {
        cout << head->data.name << " " << head->data.address << " " << head->data.group << " " << head->data.rate << endl;
        head = head->next;
    }
}

int countList(ListNode *head) {
    int counter = 0;
    while (head != nullptr) {
        counter++;
        head = head->next;
    }
    return counter;
}

void deleteList(ListNode *&head) {
    while (head != nullptr) {
        auto next = head->next;
        delete head;
        head = next;
    }
}

double findMax(ListNode *head) {
    double max_rating = -1.0;
    while (head != nullptr) {
        if (head->data.rate > max_rating) {
            max_rating = head->data.rate;
        }
        head = head->next;
    }
    return max_rating;
}

double findMin(ListNode *head) {
    double min_rating = 100.9;
    while (head != nullptr) {
        if (head->data.rate < min_rating) {
            min_rating = head->data.rate;
        }
        head = head->next;
    }
    return min_rating;
}

void deleteDouble(ListNode *&head) {
    vector<string> seenNodes;  // здесь будут храниться узлы, которые мы отсмотрели
    auto curr = head;
    ListNode *prev = nullptr;
    while (curr != nullptr) {
        if (find(seenNodes.begin(), seenNodes.end(), curr->data.name) != seenNodes.end()) {
            // find(), если находит, вернет нам студента как структуру. Если не находит, возвращает nullptr, который по умолчанию является последним элементом вектора
            // текущий узел = дубликат, удаляем его
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {  // если узел не дубликат
            seenNodes.push_back(curr->data.name);  // push_back вставляет элемент в вектор
            prev = curr;
            curr = curr->next;
        }
    }
}

void deleteNode(ListNode *&head, const string &name) {
    ListNode *prev = nullptr;
    auto curr = head;
    while (curr != nullptr) {
        if (curr->data.name == name) {
            if (prev == nullptr) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

int menu() {
    int choice = 0;
    cout << "Make a choice:\n1 - add node\n2 - show list\n3 - delete double\n4 - delete list\n5 - quit\n6 - delete element";
    cin >> choice;
    return choice;
}

int mmmm() {
    ListNode *head = nullptr;
    string name, address;
    int option, group;
    double rate, max_rate, min_rate;

    do {
        option = menu();
        cin.ignore();
        if (option == 1) {
            cout << "Name: ";
            getline(cin, name);
            cout << "Address: ";
            getline(cin, address);
            cout << "Group (int): ";
            cin >> group;
            cout << "Rate (double): ";
            cin >> rate;
            addNode(head, {name, address, group, rate});
        } else if (option == 2) {
            showList(head);
            cout << "Length of list: " << countList(head) << endl;
            cout << "\n\n";
        } else if (option == 3) {
            deleteDouble(head);
            showList(head);
        } else if (option == 4) {
            deleteList(head);
            cout << "Deleted!\n\n";
        } else if (option == 5) {
            max_rate = findMax(head);
            cout << "Max rating: " << max_rate << endl;
            min_rate = findMin(head);
            cout << "Min rating: " << min_rate << endl;
        } else if (option == 6) {
            cout << "Enter name of student: ";
            getline(cin, name);
            deleteNode(head, name);
        } else {
            cout << "Incorrect choice!";
        }
    } while (option != 5);

    return 0;
}
