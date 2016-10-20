//
//  Sort.h
//  cyest
//
//  Created by 杨才 on 16/10/14.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef Sort_h
#define Sort_h

#include <stdio.h>
#include <iostream>

using namespace std;

class Sort {
public:
    virtual void sort(int array[], int n) = 0;

    void log(int ints[], int count);



protected:
    //两个数交换不产生临时空间
    void swap(int *a, int *b);
};

#endif /* Sort_h */
