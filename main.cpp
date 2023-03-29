#include <iostream>
#include <cmath>

using namespace std;

int printLeadingDigit(int n) {
    if (n < 10) {
        return n;
    } else {
        return printLeadingDigit(n / 10);
    }
}

int countDigits(int n) {
    if (n < 10) {
        return 1;
    } else {
        return 1 + countDigits(n / 10);
    }
}

int main() {
    int n;
    cout << "введите натуральное число: ";
    cin >> n;
    cout << "Старшая цифра введенного числа " << printLeadingDigit(n) << endl;

    cout << "Количество цифор в десятичной записи: " << countDigits(n) << endl;
    return 0;
}
