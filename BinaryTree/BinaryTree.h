//
//  BinaryTree.h
//  cyest
//
//  Created by 杨才 on 16/10/16.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>

struct TreeNode {
    int value;
    int BF;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

typedef TreeNode *BinaryTree;

#endif /* BinaryTree_h */
