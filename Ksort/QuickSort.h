//
//  QuickSort.h
//  cyest
//
//  Created by 杨才 on 16/10/14.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef QuickSort_h
#define QuickSort_h

#include "Sort.h"
#include <stdio.h>

class QuickSort : public Sort {
public:
    void sort(int array[], int n);

private:
    void _sort(int array[], int start, int end);
};

#endif /* QuickSort_h */
