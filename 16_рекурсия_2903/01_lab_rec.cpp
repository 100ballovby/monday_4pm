#include <iostream>
#include <cmath>

using namespace std;

void findClosestFraction(int x, int n, int &best_m, int &best_n, double &best_diff) {
    if (n >= 100) {
        return;
    }

    int m = round(n * sqrt(x));
    if (m == 0) {
        findClosestFraction(x, n+1, best_m, best_n, best_diff);
        return;
    }

    double diff = abs(sqrt(x) - (double)m/n);
    if (diff < best_diff) {
        best_m = m;
        best_n = n;
        best_diff = diff;
    }

    findClosestFraction(x, n+1, best_m, best_n, best_diff);
}

int ya_glavniy()
{
    int x;
    cout << "Введите натуральное число: ";
    cin >> x;

    int best_m = 0;
    int best_n = 1;
    double best_diff = x;

    findClosestFraction(x, 1, best_m, best_n, best_diff);
    //best_m = (best_m % best_n) + best_n / best_m + 1;
    cout << "Ближайшая к корню из " << x << " дробь: " << best_m << "/" << best_n << endl;

    return 0;
}
