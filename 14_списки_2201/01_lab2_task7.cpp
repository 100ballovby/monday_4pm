#include <iostream>
using namespace std;

struct Queue {
    char data;
    Queue *next;
};

int maximum, k=0;

void menu();
void Insert(Queue **Q, char element);
void Print(Queue **Q);


int main() {
    int choice;
    char etalon, value;

    cout << "Etalon element: "; cin >> etalon;
    cout << "Size of queue: "; cin >> maximum;

    auto *character = new Queue();

    menu();
    cin >> choice;
    while (choice != 3) {
        switch(choice) {
            case 1:
                cout << "Insert symbol: "; cin >> value;
                if (value == etalon) {
                    cout << "Etalon inserted!\n\n";
                    cout << "Size of queue = " << k << endl;
                    break;
                } else {
                    Insert(&character, value);
                    break;
                }
            case 2:
                Print(&character);
                break;
            default:
                cout << "Incorrect choice, try again\n";
                menu();
                break;
        }
        menu();
        cout << "Choice:"; cin >> choice;
    }

    return 0;
}

void menu() {
    cout << "1 - Insert\n2 - Print\n3 - quit\n\n";
}

void Insert(Queue **Q, char element) {
    if (*Q) {  // если очередь не пустая
        Queue *pC = new Queue;  // создали "временная очередь"
        Queue *pQ;
        pQ = (*Q);  // та очередь, которую мы передали через аргумент функци
        while (pQ->next) {  // пока в очереди есть элементы
            pQ = pQ->next;  // перейти в конец (к следующему до конца)
        }
        pC->data = element;  // во временную добавляю элемент
        pC->next = NULL;  // следующим элементом ставлю пустоту
        pQ->next = pC;  // добавляю новый элемент в основную очередь
        k++; // считаем, сколько элементов добавили
    } else {
        (*Q) = new Queue;
        (*Q)->data = element;
        (*Q)->next = NULL;
    }
}

void Print(Queue **Q) {
    if ((*Q) != NULL) {  // если очередь не пустая
        cout << "Queue\n";
        Queue *temp = *Q;
        while (temp->next) {
            temp = temp->next;
            cout << " | " << temp->data << " | ";
        }
    } else {
        cout << "Queue is empty!" << endl;
    }
}
