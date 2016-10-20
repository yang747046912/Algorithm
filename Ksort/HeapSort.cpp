//
//  HeapSort.cpp
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#include "HeapSort.h"

void HeapSort::sort(int array[], int n) {
    buildHead(array, n);
    for (int i = n - 1; i > 0; i--) {
        swap(array, array + i);
        buildHead(array, i);
    }
}

void HeapSort::buildHead(int array[], int n) {
    int nonLeafNode = n / 2 - 1;
    for (int i = nonLeafNode; i >= 0; i--) {
        maxHead(array, n, i);
    }
}

void HeapSort::maxHead(int array[], int n, int leafNodeIndex) {
    int childLeftIndex = leafNodeIndex * 2 + 1;
    int childRightIndex = leafNodeIndex * 2 + 2;
    if (childRightIndex >= n) {//only have left child
        if (array[childLeftIndex] > array[leafNodeIndex]) {
            swap(array + childLeftIndex, array + leafNodeIndex);
        }
    } else {//have two children
        int maxIndex = array[childLeftIndex] > array[childRightIndex] ? childLeftIndex : childRightIndex;
        if (array[maxIndex] > array[leafNodeIndex]) {
            swap(array + maxIndex, array + leafNodeIndex);
            int maxLeftIndex = maxIndex * 2 + 1;
            int maxRightIndex = maxIndex * 2 + 2;
            if (maxLeftIndex < n || maxRightIndex < n) {
                buildHead(array, n);
            }
        }
    }

}