
#ifndef MergeSort_h
#define MergeSort_h

#include <stdio.h>
#include "Sort.h"

class MergeSort : public Sort {
public:
    void sort(int array[], int n);

    void merge(int array[], int n, int start, int length);
};

#endif /* MergeSort_h */
