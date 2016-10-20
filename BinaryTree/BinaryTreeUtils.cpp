
#include "BinaryTreeUtils.h"

void logTreeNode(BinaryTree tree) {
    if (tree == NULL) {
        return;
    }
    cout << "treeNode value " << tree->value << endl;
}


BinaryTree buildTree(int array[], int n) {
    queue<BinaryTree> nodes;
    BinaryTree tree = new TreeNode();
    tree->value = array[0];
    tree->leftNode = NULL;
    tree->rightNode = NULL;
    nodes.push(tree);
    for (int i = 1; i < n; i++) {
        BinaryTree tmp = nodes.front();
        if (tmp->leftNode != NULL && tmp->rightNode != NULL) {
            nodes.pop();
            tmp = nodes.front();
        }
        BinaryTree tree1 = new TreeNode();
        tree1->value = array[i];
        tree1->leftNode = NULL;
        tree1->rightNode = NULL;
        nodes.push(tree1);
        if (tmp->leftNode == NULL) {
            tmp->leftNode = tree1;
        } else {
            tmp->rightNode = tree1;
        }
    }
    return tree;
}

//层次遍历
void logLevel(BinaryTree tree) {
    if (tree == NULL) {
        return;
    }
    queue<BinaryTree> nodes;
    nodes.push(tree);
    while (!nodes.empty()) {
        BinaryTree tmp = nodes.front();
        cout << tmp->value << " ";
        if (tmp->leftNode != NULL) {
            nodes.push(tmp->leftNode);
        }
        if (tmp->rightNode != NULL) {
            nodes.push(tmp->rightNode);
        }
        nodes.pop();
    }
    cout << endl;
}

//前序遍历(递归)
void _logPreOrder(BinaryTree tree) {
    if (tree == NULL) {
        return;
    }
    cout << tree->value << " " ;
    _logPreOrder(tree->leftNode);
    _logPreOrder(tree->rightNode);

}

//中序遍历(递归)
void _logInOrder(BinaryTree tree) {
    if (tree == NULL) {
        return;
    }
    _logInOrder(tree->leftNode);
    cout << tree->value << " " ;
    _logInOrder(tree->rightNode);
}

//后序遍历(递归)
void _logPostorder(BinaryTree tree) {
    if (tree == NULL) {
        return;
    }
    _logPostorder(tree->leftNode);
    _logPostorder(tree->rightNode);
    cout << tree->value << " " ;
}


//前序遍历
void logPreOrder(BinaryTree tree) {
    stack<BinaryTree> nodes;
    BinaryTree tmp = tree;
    while (tmp != NULL || !nodes.empty()) {
        while (tmp != NULL) {
            cout << tmp->value << " ";
            nodes.push(tmp);
            tmp = tmp->leftNode;
        }
        if (!nodes.empty()) {
            tmp = nodes.top();
            nodes.pop();
            tmp = tmp->rightNode;
        }
    }
    cout << endl;
}

//中序遍历
void logInOrder(BinaryTree tree) {
    stack<BinaryTree> s;
    BinaryTree p = tree;
    while (p != NULL || !s.empty()) {
        while (p != NULL) {
            s.push(p);
            p = p->leftNode;
        }
        if (!s.empty()) {
            p = s.top();
            cout << p->value << " ";
            s.pop();
            p = p->rightNode;
        }
    }
    cout << endl;
}

//后序遍历
void logPostorder(BinaryTree root) {
    stack<BinaryTree> stk;
    while (!stk.empty() || root != NULL) {
        while (root != NULL) {
            stk.push(root);
            root = root->leftNode;
        }
        while (!stk.empty() && stk.top()->rightNode == root) {
            root = stk.top();
            stk.pop();
            cout << root->value << " ";
        }
        if (!stk.empty()) {
            root = stk.top()->rightNode;
        } else {
            root = NULL;
        }
    }
    cout << endl;
}

void _creatTree(BinaryTree &tree, int array[], int n) {
    for (int i = 0; i < n; i++) {
        _insertNode(tree, array[i]);
    }
}

void _insertNode(BinaryTree &tree, int value) {
    if (tree == NULL) {
        tree = new TreeNode();
        tree->value = value;
        tree->leftNode = NULL;
        tree->rightNode = NULL;
        return;
    }
    if (tree->value == value) {
        return;
    }
    if (tree->value > value) {
        _insertNode(tree->leftNode, value);
        return;
    }
    _insertNode(tree->rightNode, value);
}


void creatTree(BinaryTree &tree, int array[], int n) {
    for (int i = 0; i < n; i++) {
        insertNode(tree, array[i]);
    }
}

void insertNode(BinaryTree &tree, int value) {
    BinaryTree tmp = tree;
    BinaryTree tmpIndex = NULL;//新节点插入的位置
    while (tmp != NULL && tmp->value != value) {
        tmpIndex = tmp;
        if (tmp->value > value) {
            tmp = tmp->leftNode;
        } else {
            tmp = tmp->rightNode;
        }
    }

    if (tmp == NULL) {
        tmp = new TreeNode();
        tmp->value = value;
        tmp->leftNode = NULL;
        tmp->rightNode = NULL;
        if (tmpIndex == NULL) {
            tmpIndex = tmp;
            tree = tmpIndex;
        } else if (tmp->value > tmpIndex->value) {
            tmpIndex->rightNode = tmp;
        } else {
            tmpIndex->leftNode = tmp;
        }
    }
}


BinaryTree searchNode(BinaryTree &tree, int value) {

    BinaryTree tmp = tree;
    while (tmp != NULL) {
        if (tmp->value == value) {
            break;
        } else if (tmp->value > value) {
            tmp = tmp->leftNode;
        } else {
            tmp = tmp->rightNode;
        }
    }
    if (tmp == NULL) {
        cout << "没有找到 " << value << endl;
        return NULL;
    } else {
        cout << "我找到啦 " << value << endl;
        return tmp;
    }
}


void deleteNode(BinaryTree &tree, int value) {
    BinaryTree tmp = tree;
    BinaryTree tmpParent = NULL;
    while (tmp != NULL) {
        if (tmp->value == value) {
            break;
        } else if (tmp->value > value) {
            tmpParent = tmp;
            tmp = tmp->leftNode;
        } else {
            tmpParent = tmp;
            tmp = tmp->rightNode;
        }
    }
    if (tmp == NULL) {
        cout << "没有找到 " << value << "无法删除" << endl;

    } else {
        cout << "我找到啦 " << value << endl;
        cout << "正在删除 " << value << " ..." << endl;


        if (tmp->rightNode == NULL) {

            if (tmpParent == NULL) {
                tree = tmp->leftNode;
            } else if (tmpParent->value > tmp->value) {
                tmpParent->leftNode = tmp->leftNode;
            } else {
                tmpParent->rightNode = tmp->leftNode;
            }
            delete tmp;
        } else {
            if (tmp->rightNode->leftNode == NULL) {
                if (tmpParent == NULL) {
                    tree = tmp->rightNode;
                } else if (tmpParent->value > tmp->value) {
                    tmpParent->leftNode = tmp->rightNode;
                } else {
                    tmpParent->rightNode = tmp->rightNode;
                }
                tmp -> rightNode -> leftNode = tmp -> leftNode ;
                delete tmp;
            } else {

                BinaryTree min = tmp->rightNode->leftNode;
                BinaryTree minParent = tmp->rightNode;

                while (min->leftNode != NULL) {
                    minParent = min;
                    min = min->leftNode;
                }

                minParent->leftNode = min->rightNode;

                if (tmpParent == NULL) {
                    tree = min;
                } else if (tmpParent->value > tmp->value) {
                    tmpParent->leftNode = min;
                } else {
                    tmpParent->rightNode = min;
                }
                min->leftNode = tmp->leftNode;
                min->rightNode = tmp->rightNode;
                delete tmp;
            }
        }
        cout << "删除成功 " << value << " ..." << endl;
    }
    logLevel(tree);
}
