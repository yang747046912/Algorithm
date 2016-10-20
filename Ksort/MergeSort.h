//
//  MergeSort.h
//  cyest
//
//  Created by 杨才 on 16/10/16.
//  Copyright © 2016年 杨才. All rights reserved.
//

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
