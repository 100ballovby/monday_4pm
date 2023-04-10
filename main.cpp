#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node {
    int key;
    string info;
    Node *left;
    Node *right;
};

Node *createNode(int key, string info) {
    Node *newNode = new Node;
    newNode->key = key;
    newNode->info = info;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insertNode(Node *&root, int key, string info) {
    if (root == NULL) {
        root = createNode(key, info);
        return;
    }
    if (key < root->key) {
        insertNode(root->left, key, info);
    } else {
        insertNode(root->right, key, info);
    }
}

Node *search(Node *root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

Node *remove(Node *root, int key) {
    if (root == NULL) {  // если корня нет, возвращаем корень
        return root;
    }
    if (key < root->key) {  // если ключ удаляемого меньше ключа корня
        root->left = remove(root->left, key);  // вызываем функцию на левого потомка корня
    } else if (key > root->key) {  // если ключ больше ключа корня
        root->right = remove(root->right, key);  // вызываем функцию на правого потомка корня
    } else {  // иначе (если они равны)
        if (root->left == NULL) {  // если слева ничего нет
            Node *temp = root->right;  // сохраняем правого потомка во временную переменную
            delete root;  // удаляем "родителя"
            return temp;  // возвращаем удаленный элемент
        } else if (root->right == NULL) {  // если справа ничего нет
            Node *temp = root->left;  // сохраняем левого потомка в переменную
            delete root;  // удаляем родителя
            return temp;  // возвращаем удаленный элемент
        }
        Node *temp = root->right;  // сохраняем ссылку на правого потомка
        while (temp->left != NULL) {  // пока элементы слева не закончились
            temp = temp->left;  // присваиваем в переменную левого потомка
        }
        root->key = temp->key;  // в ключ ставим ключ временного потомка
        root->info = temp->info;  // в инфо ставим информацию временного потомка
        root->right = remove(root->right, temp->key);  // снова вызываем функцию удаления
    }
    return root;
}

void print(Node *root) {
    if (root != NULL) {
        print(root->left);
        cout << "Key: " << root->key << endl;
        print(root->right);
    }
}

void freeMemory(Node *root) {
    if (root != NULL) {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
    }
}

int countEvenKeys(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int count = countEvenKeys(root->left) + countEvenKeys(root->right);
    if (root->key % 2 == 0) {
        count++;
    }
    return count;
}


int main() {
    Node *root = NULL;
    int key;
    string info;

    // создадим дерево
    ifstream input("../input.txt");
    if (input.is_open()) {
        while (!input.eof()) {
            input >> info >> key;
            insertNode(root, key, info);
        }
        input.close();
    } else {
        cout << "Error!" << endl;
        return 1;
    }

    int choice;
    do {
        cout << "Select an option:" << endl;
        cout << "1 - Add a new record" << endl;
        cout << "2 - Search for a record" << endl;
        cout << "3 - delete a record" << endl;
        cout << "4 - print all" << endl;
        cout << "5 - Count nodes with even keys" << endl;
        cout << "6 - exit" << endl;
        cin >> choice;

        if (choice == 1) {
                // добавим запись
                cout << "Enter key and info: ";
                cin >> key >> info;
                insertNode(root, key, info);
        } else if (choice == 2) {
            cout << "Enter key to search: ";
            cin >> key;
            Node *result = search(root, key);
            if (result != NULL) {
                cout << "Key: " << result->key << ", Info: " << result->info << endl;
            } else {
                cout << "Record not found" << endl;
            }
        } else if (choice == 3) {
            cout << "Enter key to remove: " << endl;
            cin >> key;
            root = remove(root, key);
        } else if (choice == 4) {
            print(root);
        } else if (choice == 5) {
            int count = countEvenKeys(root);
            cout << "Number of nodes with even keys: " << count << endl;
        }
    } while (choice != 6);
    freeMemory(root);
    return 0;
}
