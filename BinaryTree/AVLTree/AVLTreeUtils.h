//
//  AVLTreeUtils.h
//  cyest
//
//  Created by 杨才 on 16/10/19.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef AVLTreeUtils_h
#define AVLTreeUtils_h

#include <stdio.h>
#include "AVLTree.h"
#include <iostream>
#include <stack>
#include "queue"
using namespace std;
//#include "../BinaryTreeUtils.h"

void creatTreeAVL(AVLTree &tree, int array[], int n);

void insertNodeAVL(AVLTree &tree, int value);
void deleteNodeAVL(AVLTree &tree, int value);
void deleteNodeAVL(AVLTree &tree, AVLTree node);

bool RotateTree(AVLTree &root, int bf, int value);

void RotateLL(AVLTree &root);

void RotateLR(AVLTree &root);

void RotateRR(AVLTree &root);

void RotateRL(AVLTree &root);

#endif /* AVLTreeUtils_h */
