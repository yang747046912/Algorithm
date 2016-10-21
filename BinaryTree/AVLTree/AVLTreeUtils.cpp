
#include "AVLTreeUtils.h"

void creatTreeAVL(AVLTree &tree, int array[], int n) {
    for (int i = 0; i < n; i++) {
        insertNodeAVL(tree, array[i]);
    }
    logPreOrder(tree);
}

void insertNodeAVL(AVLTree &tree, int value) {
    stack<AVLTree> nodes;
    AVLTree tmp = tree;
    AVLTree tmpParent = NULL;
    while (tmp != NULL && tmp->value != value) {
        tmpParent = tmp;
        nodes.push(tmpParent);
        if (tmp->value > value) {
            tmp = tmp->leftNode;
        } else {
            tmp = tmp->rightNode;
        }
    }
    if (tmp != NULL) {
        cout << value << " 已经存在,无法插入" << endl;
        return;
    }
    tmp = new TreeNode();
    tmp->value = value;
    tmp->BF = 0;
    tmp->leftNode = NULL;
    tmp->rightNode = NULL;
    if (tmpParent == NULL) {
        tree = tmp;
    } else if (tmpParent->value > tmp->value) {
        tmpParent->leftNode = tmp;
    } else {
        tmpParent->rightNode = tmp;
    }
    while (!nodes.empty()) {
        tmpParent = nodes.top();
        nodes.pop();
        int bf = tmpParent->value > value ? 1 : -1;
        tmpParent->BF = tmpParent->BF + bf;
        bf = tmpParent->BF;
        if (bf == 0) {
            break;
        }
        if (bf == 2 || bf == -2) {
            RotateTree(tmpParent, bf, value);
            if (nodes.empty()) {
                tree = tmpParent;
            } else if (nodes.top()->value > value) {
                nodes.top()->leftNode = tmpParent;
            } else {
                nodes.top()->rightNode = tmpParent;
            }
            break;
        }
    }

}

//1.当旋转根的BF值为2时：
//
//如果旋转根的左孩子的BF值为1，则进行LL型旋转；
//
//如果旋转根的左孩子的BF值为-1，则进行LR型旋转。
//
//2.当旋转根的BF值为-2时：
//
//如果旋转根的右孩子的BF值为1，则进行RL型旋转；
//
//如果旋转根的右孩子的BF值为-1，则进行RR型旋转。
bool RotateTree(AVLTree &root, int bf, int value) {
    cout << "bf:" << bf << " ";
    if (bf == 2) {
        cout << "root ->leftNode -> BF:" << root->leftNode->BF << endl;
        if (root->leftNode->BF == 1) {
            cout << "插入/删除" << value << ",发生LL旋转" << endl;
            RotateLL(root);
        } else if (root->leftNode->BF == -1) {
            cout << "插入/删除" << value << ",发生LR旋转" << endl;
            RotateLR(root);
        } else {
            RotateLL(root);
            return false;
        }
    } else if (bf == -2) {
        cout << "root ->rightNode -> BF:" << root->rightNode->BF << endl;
        if (root->rightNode->BF == 1) {
            cout << "插入/删除" << value << ",发生RL旋转" << endl;
            RotateRL(root);
        } else if (root->rightNode->BF == -1) {
            cout << "插入/删除" << value << ",发生RR旋转" << endl;
            RotateRR(root);
        } else {
            RotateRR(root);
            return false;
        }
    }
    return true;
}

void RotateLL(AVLTree &root) {
    AVLTree rootNext = root->leftNode;
    root->leftNode = rootNext->rightNode;
    rootNext->rightNode = root;
    if (rootNext->BF == 1) {
        rootNext->BF = 0;
        root->BF = 0;
    } else {//rootNext -> BF== 0 的情况，删除时用
        rootNext->BF = -1;
        root->BF = 1;
    }
    root = rootNext;
}

void RotateLR(AVLTree &root) {
    AVLTree rootNext = root->leftNode;
    AVLTree newRoot = rootNext->rightNode;
    root->leftNode = newRoot->rightNode;
    rootNext->rightNode = newRoot->leftNode;
    newRoot->leftNode = rootNext;
    newRoot->rightNode = root;
    switch (newRoot->BF) //改变平衡因子
    {
        case 0:
            root->BF = 0;
            rootNext->BF = 0;
            break;
        case 1:
            root->BF = -1;
            rootNext->BF = 0;
            break;
        case -1:
            root->BF = 0;
            rootNext->BF = 1;
            break;
    }
    newRoot->BF = 0;
    root = newRoot;
}

void RotateRR(AVLTree &root) {
    AVLTree rootNext = root->rightNode;
    root->rightNode = rootNext->leftNode;
    rootNext->leftNode = root;

    if (rootNext->BF == -1) {
        root->BF = 0;
        rootNext->BF = 0;
    } else { //rootNext -> BF== 0 的情况，删除时用
        root->BF = -1;
        rootNext->BF = 1;
    }
    root = rootNext;
}

void RotateRL(AVLTree &root) {
    AVLTree rootNext = root->rightNode;
    AVLTree newRoot = rootNext->leftNode;
    root->rightNode = newRoot->leftNode;
    rootNext->leftNode = newRoot->rightNode;
    newRoot->leftNode = root;
    newRoot->rightNode = rootNext;
    switch (newRoot->BF) //改变平衡因子
    {
        case 0:
            root->BF = 0;
            rootNext->BF = 0;
            break;
        case 1:
            root->BF = 0;
            rootNext->BF = -1;
            break;
        case -1:
            root->BF = 1;
            rootNext->BF = 0;
            break;
    }
    newRoot->BF = 0;
    root = newRoot;
}

void deleteNodeAVL(AVLTree &tree, int value) {
    int deleteValue = value ;
    AVLTree tmp = tree;
    AVLTree tmpParent = NULL;
    stack<AVLTree> nodes;
    while (tmp != NULL && tmp->value != value) {
        tmpParent = tmp;
        nodes.push(tmp);
        if (tmp->value > value) {
            tmp = tmp->leftNode;
        } else {
            tmp = tmp->rightNode;
        }
    }
    if (tmp == NULL) {
        cout << "没有找到 " << value << " 无法删除 ..." << endl;
    } else {
        cout << "我找到啦 " << value << " 正在删除 ..." << endl;



        if (tmp->rightNode == NULL) {
            if (tmp->leftNode == NULL) {
                if (tmpParent == NULL) {
                    tree = NULL;
                    logPreOrder(tree);
                    logInOrder(tree);
                    return;
                } else {
                    if (tmpParent->value > tmp->value) {
                        tmpParent->leftNode = NULL;
                    } else {
                        tmpParent->rightNode = NULL;
                    }
                }
            } else {
                AVLTree tmpLeft = tmp->leftNode;
                tmp->value = tmpLeft->value;
                tmp->rightNode = tmpLeft->rightNode;
                tmp->leftNode = tmpLeft->leftNode;
                tmp->BF -= 1;
                delete tmpLeft;

                if (tmp->BF == -2) {
                    bool changeHeight = RotateTree(tmp, -2, value);
                    if (tmpParent == NULL) {
                        tree = tmp;
                    } else if (tmp->value > tmpParent->value) {
                        tmpParent->rightNode = tmp;
                    } else {
                        tmpParent->leftNode = tmp;
                    }
                    if (!changeHeight) {
                        logPreOrder(tree);
                        logInOrder(tree);
                        return;
                    }
                }
            }
        } else if (tmp->rightNode->leftNode == NULL) {
            AVLTree tmpRight = tmp->rightNode;
            tmp->value = tmpRight->value;
            tmp->rightNode = tmpRight->rightNode;
            tmp->BF += 1;
            delete tmpRight;
            if (tmp->BF == 2) {
                bool changeHeight = RotateTree(tmp, 2, value);
                if (tmpParent == NULL) {
                    tree = tmp;
                } else if (tmp->value > tmpParent->value) {
                    tmpParent->rightNode = tmp;
                } else {
                    tmpParent->leftNode = tmp;
                }
                if (!changeHeight) {
                    logPreOrder(tree);
                    logInOrder(tree);
                    return;
                }
            }
        } else {
            nodes.push(tmp);
            AVLTree minTmp = tmp->rightNode;
            nodes.push(minTmp);
            while (minTmp->leftNode != NULL) {
                minTmp = minTmp->leftNode;
                nodes.push(minTmp);
            }
            nodes.pop();
            nodes.top()->leftNode = minTmp->rightNode;
            tmp->value = minTmp->value;
            deleteValue = minTmp ->value ;
            delete minTmp;
        }
        cout << "删除成功 " << value << " ..." << endl;
        cout << "正在重新构造AVL树" << endl;
        while (!nodes.empty()) {
            int bf;
            AVLTree bfTmp = nodes.top();
            nodes.pop();
            if (bfTmp->value > deleteValue) {
                bf = -1;
            } else {
                bf = 1;
            }
            bfTmp->BF = bfTmp->BF + bf;
            bf = bfTmp->BF;
            if (bf != 0) {//如果bf==0，表明高度降低，继续后上回溯
                //如果bf为1或-1则说明高度未变，停止回溯，如果为2或-2，则进行旋转
                //当旋转后高度不变，则停止回溯
                if (bf == 1 || bf == -1) {
                    break;
                }

                bool changeHeight = RotateTree(bfTmp, bf, value);
                if (nodes.empty()) {
                    tree = bfTmp;
                } else if (nodes.top()->value > bfTmp->value) {
                    nodes.top()->leftNode = bfTmp;
                } else {
                    nodes.top()->rightNode = bfTmp;
                }
                if (!changeHeight) {
                    break;
                }
            }
        }
    }
    logPreOrder(tree);
    logInOrder(tree);
    cout << endl;
}

void deleteNodeAVL(AVLTree &tree, AVLTree node) {

}
