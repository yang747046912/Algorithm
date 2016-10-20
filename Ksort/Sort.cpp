
#include "Sort.h"

void Sort::swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Sort::log(int ints[], int count) {
    for (int i = 0; i < count; i++) {
        cout << ints[i] << " ";
    }
    cout << endl;
}


