/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-21 18:53:18
 * @LastTime: 2020-03-22 09:46:44
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\RandomLists.cpp
 * @Description:
 */
#include <iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *Clone(RandomListNode *pHead) {
    if (!pHead) return NULL;
    nodeClone(pHead);
    connectRandom(pHead);
    return reconnect(pHead);
}

//[1]复制结点，插入到原结点后方
void nodeClone(RandomListNode *head) {
    RandomListNode *pNode = head;
    while (pNode != NULL) {
        RandomListNode *pClone = new RandomListNode(pNode->label);
        pClone->next = pNode->next;
        pNode->next = pClone;
        pNode = pClone->next;
    }
}

//[2]还原新结点的random指针
void connectRandom(RandomListNode *head) {
    RandomListNode *pNode = head;

    while (pNode != NULL) {
        RandomListNode *pClone = pNode->next;
        if (pNode->random) {
            pClone->random = pNode->random->next;
        }
        pNode = pClone->next;
    }
}

//[3]拆分
RandomListNode *reconnect(RandomListNode *head) {
    RandomListNode *pNode = head;
    RandomListNode *result = head->next;
    while (pNode != NULL) {
        RandomListNode *pClone = pNode->next;
        pNode->next = pClone->next;
        pNode = pNode->next;
        if (pNode != NULL) pClone->next = pNode->next;
    }
    return result;
}

int main() {
    RandomListNode a(1);
    RandomListNode b(2);
    RandomListNode c(3);
    RandomListNode d(4);
    RandomListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;
    RandomListNode *head = Clone(&a);
    while (head) {
        cout << "label = " << head->label << " ";
        if (head->random) {
            cout << "rand = " << head->random->label;
        } else {
            cout << "rand = NULL";
        }
        cout << endl;
        head = head->next;
    }
    return 0;
}