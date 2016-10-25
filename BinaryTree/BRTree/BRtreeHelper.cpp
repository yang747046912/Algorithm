#include "BRtreeHelper.h"void logInOrderAVL(BRtree tree) {    int count = 0;    stack<BRtree> s;    BRtree p = tree;    while (p != NULL || !s.empty()) {        while (p != NULL) {            s.push(p);            if (p->color == RED) {                cout << p->value << "(red) ";            } else {                cout << p->value << " ";            }            count++;            p = p->leftNode;        }        if (!s.empty()) {            p = s.top();            s.pop();            p = p->rigthNode;        }    }    cout << endl << "共输出" << count << "个数据" << endl;}void createBRTree(BRtree &root, int *array, int n) {    for (int i = 0; i < n; i++) {        insertBRTree(root, *(array + i));    }}void insertBRTree(BRtree &root, int value) {    stack<BRtree> nodes;    BRtree tmp = root;    while (tmp != NULL && tmp->value != value) {        nodes.push(tmp);        if (tmp->value > value) {            tmp = tmp->leftNode;        } else {            tmp = tmp->rigthNode;        }    }    if (tmp != NULL) {        cout << value << "已经存在，无法插入" << endl;        return;    }    tmp = new BRtreeNode;    tmp->value = value;    tmp->leftNode = NULL;    tmp->rigthNode = NULL;    if (nodes.empty()) {        root = tmp;        root->color = BLACK;        return;    }    BRtree tmpParent = NULL;    tmpParent = nodes.top();    if (tmp->value > tmpParent->value) {        tmpParent->rigthNode = tmp;    } else {        tmpParent->leftNode = tmp;    }    while (!nodes.empty()) {        tmpParent = nodes.top();        if (tmpParent->color == BLACK) {            return;        }        nodes.pop();        if (nodes.empty()) {            if (tmpParent->color == RED) {                tmpParent->color = BLACK;            }            return;        }        BRtree tmpGrand = nodes.top();        BRtree tmpUncle = NULL;        if (tmpParent->value > tmpGrand->value) {            tmpUncle = tmpGrand->leftNode;        } else {            tmpUncle = tmpGrand->rigthNode;        }        if (tmpUncle != NULL && tmpUncle->color == RED) {            tmpParent->color = BLACK;            tmpUncle->color = BLACK;            tmpGrand->color = RED;            tmp = tmpGrand;            nodes.pop();            if (nodes.empty()) {                tmpGrand->color = BLACK;                return;            }        } else {            if (tmpGrand->leftNode == tmpParent) {                if (tmpParent->leftNode == tmp) {                    roateLL(tmpGrand);                } else {                    roateLR(tmpGrand);                }            } else {                if (tmpParent->rigthNode == tmp) {                    roateRR(tmpGrand);                } else {                    roateRL(tmpGrand);                }            }            tmpGrand->color = BLACK;            tmpGrand->leftNode->color = RED;            tmpGrand->rigthNode->color = RED;            nodes.pop();            if (nodes.empty()) {                root = tmpGrand;            } else {                if (nodes.top()->value > tmpGrand->value) {                    nodes.top()->leftNode = tmpGrand;                } else {                    nodes.top()->rigthNode = tmpGrand;                }            }            return;        }    }}void roateLL(BRtree &root) {    BRtree left = root->leftNode;    root->leftNode = left->rigthNode;    left->rigthNode = root;    root = left;}void roateLR(BRtree &root) {    BRtree left = root->leftNode;    BRtree right = left->rigthNode;    root->leftNode = right->rigthNode;    left->rigthNode = right->leftNode;    right->leftNode = left;    right->rigthNode = root;    root = right;}void roateRR(BRtree &root) {    BRtree right = root->rigthNode;    root->rigthNode = right->leftNode;    right->leftNode = root;    root = right;}void roateRL(BRtree &root) {    BRtree right = root->rigthNode;    BRtree left = right->leftNode;    root->rigthNode = left->leftNode;    right->leftNode = left->rigthNode;    left->leftNode = root;    left->rigthNode = right;    root = left;}void logBRTree(BRtree root) {    if (root != NULL) {        if (root->color == RED) {            cout << root->value << "(red)" << " ";        } else {            cout << root->value << " ";        }        countBrnode++;        logBRTree(root->leftNode);        logBRTree(root->rigthNode);    }}void deleteBRTree(BRtree &root, int value) {    cout << "删除" << value << ":" << endl;    BRtree tmp = root;    stack<BRtree> nodes;    while (tmp != NULL && tmp->value != value) {        nodes.push(tmp);        if (tmp->value > value) {            tmp = tmp->leftNode;        } else {            tmp = tmp->rigthNode;        }    }    if (tmp == NULL) {        cout << value << "不存在，无法删除" << endl;        return;    }    cout << value << "找到，正在删除" << endl;    BRtree minTmp = tmp;//右支树最小值    if (minTmp->leftNode != NULL && minTmp->rigthNode != NULL) {        nodes.push(minTmp);        minTmp = minTmp->rigthNode;        nodes.push(minTmp);        while (minTmp->leftNode != NULL) {            minTmp = minTmp->leftNode;            nodes.push(minTmp);        }        tmp->value = minTmp->value;        nodes.pop();    }    tmp = minTmp;    BRtree newTmp = tmp->rigthNode;    if (newTmp == NULL) {        newTmp = tmp->leftNode;    }    if (nodes.empty()) {//根节点被删除        root = newTmp;        if (root != NULL) {            root->color = BLACK;        }        return;    } else {        BRtree tmpParent = nodes.top();        if (tmpParent->value > tmp->value) {            tmpParent->leftNode = newTmp;        } else {            tmpParent->rigthNode = newTmp;        }        if (tmp->color == BLACK && newTmp != NULL && newTmp->color == RED) {//一黑一红            newTmp->color = BLACK;            return;        }    }    if (tmp->color == RED) {        return;    }    // nodes.pop();    nodes.push(newTmp);    while (!nodes.empty()) {        BRtree current = nodes.top();        nodes.pop();        if (nodes.empty()) {            current->color = BLACK;            return;        }        BRtree currentParent = nodes.top();        nodes.pop();//这个地方有待探讨        BRtree currentGrand = NULL;        if (!nodes.empty()) {            currentGrand = nodes.top();        }        nodes.push(currentParent);        BRtree currentUncle = NULL;        if (currentParent->value > tmp->value) {            currentUncle = currentParent->rigthNode;        } else {            currentUncle = currentParent->leftNode;        }        if (currentUncle != NULL && currentUncle->color == RED) {//红兄            currentUncle->color = BLACK;            currentParent->color = RED;            if (currentParent->value > currentUncle->value) {                roateLL(currentParent);            } else {                roateRR(currentParent);            }            if (currentGrand == NULL) {                root = currentParent;                currentParent->color = BLACK;                return;            } else {                if (currentGrand->value > currentParent->value) {                    currentGrand->leftNode = currentParent;                } else {                    currentGrand->rigthNode = currentParent;                }            }        } else {//黑兄            if (isBlackOrNull(currentUncle->leftNode) && isBlackOrNull(currentUncle->rigthNode)) {//二黑侄儿                if (currentParent->color == RED) {//红父                    currentParent->color = BLACK;                    if (currentUncle != NULL) {                        currentUncle->color = RED;                    }                    if (current != NULL) {                        current->color = BLACK;                    }                    return;                } else {//黑父                    if (current != NULL && current->color == RED) {                        currentParent->color = RED;                    } else {                        currentParent->color = BLACK;                    }                    if (current != NULL) {                        current->color = BLACK;                    }                    currentUncle->color = RED;                }            } else {//红侄儿                int parentColor = currentParent->color;                currentParent->color = BLACK;                if (currentParent->value > currentUncle->value) {//L                    if (currentUncle->rigthNode != NULL && currentUncle->rigthNode->color == RED) {                        currentUncle->rigthNode->color = BLACK;                        roateLR(currentParent);                    } else {                        currentUncle->leftNode->color = BLACK;                        roateLL(currentParent);                    }                } else {//R                    if (currentUncle->leftNode != NULL && currentUncle->leftNode->color == RED) {                        currentUncle->leftNode->color = BLACK;                        roateRL(currentParent);                    } else {                        currentUncle->rigthNode->color = BLACK;                        roateRR(currentParent);                    }                }                currentParent->color = parentColor;                if (currentGrand == NULL) {                    root = currentParent;                    currentParent->color = BLACK;                    return;                } else {                    if (currentGrand->value > currentParent->value) {                        currentGrand->leftNode = currentParent;                    } else {                        currentGrand->rigthNode = currentParent;                    }                }                return;            }        }    }}bool isBlackOrNull(BRtree root) {    if (root != NULL) {        return root->color == BLACK;    }    return true;}