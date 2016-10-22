#include <iostream>#include "Ksort/BubbleSort.h"#include "Ksort/QuickSort.h"#include "Ksort/InsertSort.h"//#include "Ksort/ShellSort.h"#include "Ksort/SelectionsSort.h"#include "Ksort/HeapSort.h"#include "Ksort/MergeSort.h"#include "BinaryTree/BinaryTree.h"#include "BinaryTree/BinaryTreeUtils.h"#include "BinaryTree/AVLTree/AVLTreeUtils.h"int main(int argc, const char *argv[]) {    int ints[10] = {99, 456, 85, 216, 579, 464, 156, 416, 15, 86};    // int  ints1[10]= {479, 99 ,86, 77, 156, 216, 416, 456, 464, 478 };    BubbleSort sort;    sort.log(ints, 10);    cout << "冒泡排序:" << endl;    sort.sort(ints, 10);    sort.log(ints, 10);    QuickSort qSort;    cout << "快速排序:" << endl;    qSort.sort(ints, 10);    qSort.log(ints, 10);    InsertSort iSort;    cout << "插入排序:" << endl;    iSort.sort(ints, 10);    iSort.log(ints, 10);    //    int ints4[10]= {99,456,85,216,579,464,156,416,15,86};    //    ShellSort sSort;    //    cout<<"希尔排序:"<<endl;    //    sSort.sort(ints4, 10);    //    sSort.log(ints4, 10);    SelectionSort sSort;    cout << "选择排序:" << endl;    sSort.sort(ints, 10);    sSort.log(ints, 10);    HeapSort hSort;    cout << "堆  排序:" << endl;    hSort.sort(ints, 10);    hSort.log(ints, 10);    //99 456 85 216 464 579 156 416 15 86 11    MergeSort mSort;    cout << "归并排序:" << endl;    mSort.sort(ints, 10);    mSort.log(ints, 10);    cout << "二叉树:" << endl;    BinaryTree tree = buildTree(ints, 10);    cout << "层次遍历:" << endl;    logLevel(tree);    cout << "前序遍历(递归):" << endl;    _logPreOrder(tree);    cout << endl;    cout << "前序遍历:" << endl;    logPreOrder(tree);    cout << "中序遍历(递归):" << endl;    _logInOrder(tree);    cout << endl;    cout << "中序遍历:" << endl;    logInOrder(tree);    cout << "后序遍历(递归):" << endl;    _logPostorder(tree);    cout << endl;    cout << "后序遍历:" << endl;    logPostorder(tree);    delete tree;    cout << "二叉树的查找:" << endl;    cout << "数据源:" << endl;    mSort.log(ints, 10);    cout << "生成二叉查找树(递归):" << endl;    BinaryTree tree1 = NULL;    _creatTree(tree1, ints, 10);    logLevel(tree1);    delete tree1;    cout << "生成二叉查找树:" << endl;    BinaryTree tree2 = NULL;    creatTree(tree2, ints, 10);    logLevel(tree2);    cout << "二叉查找树查找:" << endl;    logTreeNode(searchNode(tree2, 9999));    logTreeNode(searchNode(tree2, 99));    logTreeNode(searchNode(tree2, 85));    logTreeNode(searchNode(tree2, 464));    logTreeNode(searchNode(tree2, 156));    logTreeNode(searchNode(tree2, 5555));    logLevel(tree2);    insertNode(tree2, -100);    logLevel(tree2);    insertNode(tree2, -99);    logLevel(tree2);    insertNode(tree2, -2);    logLevel(tree2);    insertNode(tree2, 12);    logLevel(tree2);    insertNode(tree2, -1);    logLevel(tree2);    insertNode(tree2, -101);    logLevel(tree2);    insertNode(tree2, -102);    logLevel(tree2);    insertNode(tree2, -103);    logLevel(tree2);    cout << "二叉查找树删除:" << endl;    deleteNode(tree2, 99);    deleteNode(tree2, 15);    deleteNode(tree2, 86);    deleteNode(tree2, 579);    deleteNode(tree2, 464);    deleteNode(tree2, 456);    deleteNode(tree2, 85);    deleteNode(tree2, 156);    deleteNode(tree2, 216);    deleteNode(tree2, 416);    deleteNode(tree2, 15);    deleteNode(tree2, 85);    deleteNode(tree2, 86);    deleteNode(tree2, 99);    deleteNode(tree2, 156);    deleteNode(tree2, 216);    deleteNode(tree2, 456);    deleteNode(tree2, 464);    deleteNode(tree2, 759);    deleteNode(tree2, 579);    logLevel(tree2);    delete tree2;    cout << "AVL 树:" << endl;    AVLTree treeAVL=NULL;    cout << "AVL 树的创建:" << endl;    creatTreeAVL(treeAVL, ints, 10);    insertNodeAVL(treeAVL, -100);    insertNodeAVL(treeAVL, -99);    insertNodeAVL(treeAVL, -2);    insertNodeAVL(treeAVL, 12);    insertNodeAVL(treeAVL, -1);    insertNodeAVL(treeAVL, -101);    insertNodeAVL(treeAVL, -102);    insertNodeAVL(treeAVL, -103);    logLevel(treeAVL);    deleteNodeAVL(treeAVL, 15);    deleteNodeAVL(treeAVL, 85);    deleteNodeAVL(treeAVL, 86);    deleteNodeAVL(treeAVL, 99);    deleteNodeAVL(treeAVL, 156);    deleteNodeAVL(treeAVL, 216);    deleteNodeAVL(treeAVL, 456);    deleteNodeAVL(treeAVL, 464);    deleteNodeAVL(treeAVL, 759);    deleteNodeAVL(treeAVL, 579);    int aa[10] = {-103, -102, -101, -100, -99, -2, -1, 12, 416, 456};    for (int i = 0; i < 10; ++i) {        deleteNodeAVL(treeAVL, aa[i]);    }    delete treeAVL;    cout << "11111" << endl;    return 0;}