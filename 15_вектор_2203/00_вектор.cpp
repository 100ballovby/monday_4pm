#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int v_theory() {
    vector<int> v {4, 5, 2, 7, 1, 2, 8, 9};
    auto begin = v.begin();
    auto end = v.end();  // на элемент, стоящий после последнего элемента вектора

    for (auto ptr = begin; ptr != end; ptr++) {
        cout << *ptr << " ";
    }
    cout << endl;

    int n = 7, i_n;
    for (auto ptr = begin; ptr != end; ptr++) {
        if (*ptr == n) {
            i_n = *ptr;
        }
    }
    cout << "Found: " << i_n << endl;
    auto i_key = find(begin, end, i_n);
    cout << i_key - v.begin() << endl;

    v.resize(10);  // расширить вектор до 10 элементов
    for (auto ptr = v.begin(); ptr != v.end(); ptr++) {
        cout << *ptr << " ";
    }

    return 0;
}
