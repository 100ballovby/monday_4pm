#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long fact(int n) {
    int factorial = 1;
    for (int i = n; i >= 1; i--) {
        factorial *= i;
    }
    return factorial;
}

long long factorial(int n) {
    if (n == 0 || n == 1) { // базовый случай (случай выхода из функции)
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}