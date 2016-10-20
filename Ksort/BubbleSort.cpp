
#include "BubbleSort.h"

void BubbleSort::sort(int array[], int n) {
    int low = 0;
    int height = n - 1;
    bool flag = true;//是否发生交换
    while (low < height && flag) {
        flag = false;
        for (int i = low; i < height; i++) {
            if (array[i] > array[i + 1]) {
                flag = true;
                swap(array + i, array + i + 1);
            }
        }
        height--;
        for (int i = height; i > low; i--) {
            if (array[i] < array[i - 1]) {
                flag = true;
                swap(array + i, array + i - 1);
            }
        }
    }
}


