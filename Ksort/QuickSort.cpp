
#include "QuickSort.h"

void QuickSort::_sort(int array[], int start, int end) {
    if (end - start <= 0) {
        return;
    } else if (end - start == 1 && array[start] > array[end]) {
        swap(array + start, array + end);
    } else {
        int i = start;
        int j = end;
        int tmp = array[i];
        while (i != j) {
            while (array[j] >= tmp && i < j) {
                j--;
            }
            while (array[i] <= tmp && i < j) {
                i++;
            }
            if (i < j) {
                swap(array + j, array + i);
            }
        }
        if (i != start) {
            swap(array + start, array + i);
        }
        if (i == start) {
            _sort(array, start, start);
            _sort(array, i + 1, end);
        } else if (i == end) {
            _sort(array, start, end - 1);
            _sort(array, end, end);
        } else {
            _sort(array, start, i - 1);
            _sort(array, i + 1, end);
        }
    }
}

void QuickSort::sort(int array[], int n) {
    _sort(array, 0, n - 1);
}