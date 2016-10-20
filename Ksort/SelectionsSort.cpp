//
//  SelectionsSort.cpp
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#include "SelectionsSort.h"

void SelectionSort::sort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(array + i, array + minIndex);
        }
    }
}
