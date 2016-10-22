#pragma once

#include "BRtree.h"
#include <iostream>
#include <stack>

using namespace std;

void createBRTree(BRtree &root, int *array, int n);

void insertBRTree(BRtree &root, int value);

void roateLL(BRtree &root);

void roateLR(BRtree &root);

void roateRR(BRtree &root);

void roateRL(BRtree &root);