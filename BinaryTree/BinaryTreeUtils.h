//
//  BinaryTreeUtils.h
//  cyest
//
//  Created by 杨才 on 16/10/16.
//  Copyright © 2016年 杨才. All rights reserved.
//

#ifndef BinaryTreeUtils_h
#define BinaryTreeUtils_h

#include "BinaryTree.h"
#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


void logTreeNode(BinaryTree tree);


BinaryTree buildTree(int array[], int n);

void logLevel(BinaryTree tree);

void _logPreOrder(BinaryTree tree);

void _logInOrder(BinaryTree tree);

void _logPostorder(BinaryTree tree);

void logPreOrder(BinaryTree tree);

void logInOrder(BinaryTree tree);

void logPostorder(BinaryTree tree);

//在复合二叉树查找的情况下
void creatTree(BinaryTree &tree, int array[], int n);

void _creatTree(BinaryTree &tree, int array[], int n);

void insertNode(BinaryTree &tree, int value);

void _insertNode(BinaryTree &tree, int value);

void deleteNode(BinaryTree &tree, int value);

BinaryTree searchNode(BinaryTree &tree, int value);


#endif /* BinaryTreeUtils_h */
