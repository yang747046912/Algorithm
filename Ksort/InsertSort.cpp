//
//  InsertSort.cpp
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#include "InsertSort.h"

void InsertSort::sort(int array[], int n) {

    for (int i = 1; i < n; i++) {
        if (array[i] >= array[i - 1]) {
            continue;
        }
        for (int j = i - 1; j >= 0; j--) {
            if (array[j] > array[j + 1]) {
                swap(array + j, array + j + 1);
            }
        }
    }
}
