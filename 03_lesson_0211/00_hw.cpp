#include <iostream>
using namespace std;

void task_2_hw() {
    int matrix[7][3] = {
            {3, 4, 2},
            {5, 7, 9},
            {2, 4, 6},
            {90, 22, 15},
            {34, 95, 12},
            {-1, 5, 19},
            {-5, 16, 23}
    };
    for (int str = 0; str < 7; str += 2) {
        for (int el = 0; el < 3; el++) {
            cout << matrix[str][el] << ", ";
        }
    }
}