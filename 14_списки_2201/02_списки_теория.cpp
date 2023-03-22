#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void lists_basics() {
    // чтобы создать список, надо указать list <тип_данных> <имя_идентификатора>
    list <string> listik;
    // чтобы инициализировать список, просто запишем его элементы в {}
    list <int> numbers = {5, 2, 3, 8, 5, 2, 3};
    /**
     * pop_front - удалить элемент из начала списка
     * pop_back - удалить элемент из конца списка
     * push_front - добавить в начало
     * push_back - добавить в конец
     * front - обратиться к первому элементу
     * back - обратиться к последнему элементу
     * insert - вставить элемент в определенное место списка
     * unique - удалить все повторяшки
     * merge - добавление списка
     * copy - вывести все элементы списка
     *
     * У списков есть два волшебных слова - begin() и end()
     * **/

    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
}


int я_мэйн() {
    list <int> mylist;
    list <int> list_for_merge = {7, 8, 9, 10};

    // автоматическое наполнение списка
    for (int i = 0; i < 7; i++) {
        mylist.push_back(i);
    }
    // вывод списка
    cout << "Новый список: " << endl;
    copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    // добавление элемента на последнее место
    cout << "Вставил в конец списка 6: " << endl;
    mylist.insert(mylist.end(), 6);  // в конец списка вставить число 6
    copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
    cout << "\n\n";

    // unique
    mylist.unique();
    list <int> :: iterator iter;  // эта штука будет бегать по списку и дергать элементы

    // for (int iter = 0; iter < sizeof(mylist); iter++)
    cout << "Удалил повторяшки: " << endl;
    for (iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << *iter << " ";
    }

    // объединение списков
    mylist.merge(list_for_merge);  // добавляю в список mylist новый список list_for_merge
    cout << "\n\nОбъединил два списка: " << endl;
    for (iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << *iter << " ";
    }

    // чтобы удалить все элементы со значением X
    cout << "\n\nУдалим десятку: \n";
    mylist.remove(10);
    for (iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << *iter << " ";
    }

    // удалим последовательно все элементы списка:
    cout << "\n\nУдалим весь список: \n";
    mylist.erase(mylist.begin(), mylist.end());  // снести элементы с самого начала до самого конца

    for (iter = mylist.begin(); iter != mylist.end(); iter++) {
        cout << *iter << " ";
    }
    return 0;
}
