//
//  HeapSort.h
//  cyest
//
//  Created by 杨才 on 16/10/15.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

#include <stdio.h>
#include "Sort.h"

class HeapSort : public Sort {
public:
    void sort(int array[], int n);

private:
    void buildHead(int array[], int n);//构建大根堆
    void maxHead(int array[], int n, int leafNodeIndex);//调整堆
};

#endif /* HeapSort_h */
