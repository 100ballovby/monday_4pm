#include <iostream>
#include <string>
using namespace std;


int stroka_() {
    string s = "a-2b+l6.c-d12..34fghi5-+";
    string number = "";
    bool hasDecimal = false;

    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            number += s[i];
        } else if (s[i] == '+' || s[i] == '-') {
            if (number.empty() && i + 1 < s.length()) {
                number += s[i];
            }
        } else if (s[i] == '.') {
            if (!hasDecimal) {
                number += s[i];
                hasDecimal = true;
            }
        }
    }

    if (number.empty()) {
        cout << "Not found!" << endl;
    } else {
        double res = stod(number);
        cout << "Found number! " << res << endl;
    }
}
