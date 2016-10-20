//
//  MergeSort.cpp
//  cyest
//
//  Created by 杨才 on 16/10/16.
//  Copyright © 2016年 杨才. All rights reserved.
//

#include "MergeSort.h"

void MergeSort::sort(int arrays[], int n) {
    int group = (n + 1) / 2;
    int length = 2;
    while (group != 0) {
        for (int i = 0; i < n; i += length) {
            merge(arrays, n, i, length);
        }
        if (group != 1) {
            group = (group + 1) / 2;
        } else {
            group = group / 2;
        }
        length *= 2;
    }
}

void MergeSort::merge(int arrays[], int n, int start, int lengthSkip) {
    int length = lengthSkip;
    if (start + length > n) {
        length = n - start;
    }
    if (length <= lengthSkip / 2) {
        return;
    }
    if (length / 2 == 1 && length % 2 == 0) {
        if (arrays[start] > arrays[start + 1]) {
            swap(arrays + start, arrays + start + 1);
        }
    } else if (arrays[start + lengthSkip / 2 - 1] < arrays[start + lengthSkip / 2]) {
        return;
    } else {
        int leftLength = lengthSkip / 2;
        int rightLength = length - leftLength;
        int *array = new int[length];
        int arrayIndex = 0;
        int leftIndex = 0;
        int rightIndex = 0;
        int rightMax = arrays[start + length - 1];
        int leftMin = arrays[start];
        if (rightMax > leftMin) {
            while (leftIndex < leftLength && rightIndex < rightLength) {
                if (arrays[start + leftIndex] > arrays[start + leftLength + rightIndex]) {
                    array[arrayIndex++] = arrays[start + leftLength + rightIndex];
                    rightIndex++;
                } else {
                    array[arrayIndex++] = arrays[start + leftIndex];
                    leftIndex++;
                }
            }
        }
        while (rightIndex < rightLength) {
            array[arrayIndex++] = arrays[start + rightIndex + leftLength];
            rightIndex++;
        }
        while (leftIndex < leftLength) {
            array[arrayIndex++] = arrays[start + leftIndex];
            leftIndex++;
        }
        for (int i = 0; i < length; i++) {
            arrays[start + i] = array[i];
        }
        delete[] array;
    }
}

