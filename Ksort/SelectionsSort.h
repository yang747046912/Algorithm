//
//  SelectionsSort.h
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef SelectionsSort_h
#define SelectionsSort_h

#include <stdio.h>
#include "Sort.h"

class SelectionSort : public Sort {
public:
    void sort(int array[], int n);
};

#endif /* SelectionsSort_h */
