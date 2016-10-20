
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
