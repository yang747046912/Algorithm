#pragma once

enum {
	BLACK,
	RED
};


struct BRtreeNode
{
	int value;
	int color =RED;
	BRtreeNode *leftNode;
	BRtreeNode *rigthNode;
};
typedef BRtreeNode *BRtree;
