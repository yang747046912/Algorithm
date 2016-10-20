//
//  InsertSort.h
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef InsertSort_h
#define InsertSort_h

#include "Sort.h"
#include <stdio.h>

class InsertSort : public Sort {
public:
    void sort(int array[], int n);
};

#endif /* InsertSort_h */
