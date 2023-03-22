#include <iostream>
using namespace std;

int get_from_user() {
    int n;
    cout << "Insert number: ";
    cin >> n;

    return n;
}

int caller_1() {
    int a, b;
    a = get_from_user();
    b = get_from_user();

    cout << a + b << endl;
    return 0;
}