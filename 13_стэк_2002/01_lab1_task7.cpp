#include <iostream>
//#include <malloc.h>
//#include <locale.h>
using namespace std;

struct stackNode {
    char data;
    struct stackNode *nextPtr;
};

int maximum, k = 0;

typedef struct stackNode StackNode;  // "указатель" на стек
typedef StackNode *StackNodePtr;  // инициализация стека

void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
void printStack(StackNodePtr currentPtr);
bool isEmpty(StackNodePtr *topPtr);
void menu();

int task7_lab01_stack() {
    StackNodePtr stackPtr = NULL;  // отменяем создание стека
    int choice;
    char etalon, value;
    cout << "Etalon element: "; cin >> etalon;
    cout << "Size of stack: "; cin >> maximum;

    menu();
    cin >> choice;
    while (choice != 3) {
        switch(choice) {
            case 1:
                cout << "Insert symbol: "; cin >> value;
                if (value == etalon) {
                    cout << "Etalon inserted!\n\n";
                    printStack(stackPtr);
                    break;
                } else {
                    push(&stackPtr, value);
                    printStack(stackPtr);
                    break;
                }
            case 2:
                if (!isEmpty(&stackPtr)) {
                    cout << "Deleted " << pop(&stackPtr) << endl;
                }
                printStack(stackPtr);
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
    cout << "1 - Push\n2 - Pop\n3 - quit\n\n";
}

void push(StackNodePtr *topPtr, int info) {  // вставляем новый символ в стек
    StackNodePtr newPtr;  // указатель на новый стек
    newPtr = new StackNode;
    if (k < maximum) {  // проверяем, чтобы в стеке еще было место
        if (newPtr != NULL) {
            newPtr->data = info;  /* Чтобы вставить в поле структуры значение, мы пишем название.поле = значение, но так как мы работаем с указателем на стек, мы используем аналог оператора "." - "->" */
            newPtr->nextPtr = *topPtr;  // следующий элемент стека находится сверху
            *topPtr = newPtr;
            k++;
        }
    } else {
        cout << info << " access denied\n";
    }
}

int pop(StackNodePtr *topPtr) {  // достаем элементы стека
    StackNodePtr tempPtr; // указатель на временный узел
    int popValue; // указатель на значение
    tempPtr = *topPtr;
    popValue = (*topPtr)->data;
    *topPtr = (*topPtr)->nextPtr;
    free(tempPtr);  // освобождаю динамически выделенную память
    return popValue;
}

void printStack(StackNodePtr currentPtr) {   // выводим все содержимое
    if (currentPtr != NULL) {
        cout << "Stack\n";
        while (currentPtr != NULL) {  // пока не дошли до конца стека
            cout << " | " << currentPtr->data << " | ";
            currentPtr = currentPtr->nextPtr;
        }
        cout << " |\n\n";
    }
}

bool isEmpty(StackNodePtr *topPtr) {
    return topPtr == NULL;
}
