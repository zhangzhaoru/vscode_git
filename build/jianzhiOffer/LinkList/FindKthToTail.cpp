/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 22:46:02
 * @LastTime: 2020-03-17 23:04:44
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\FindKthToTail.cpp
 * @Description:
 */
#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
    stack<ListNode *> temp;
    while (pListHead) {
        temp.push(pListHead);
        pListHead = pListHead->next;
    }
    ListNode *res;
    if (temp.size() < k) return res;
    int count = 1;
    while (count <= k) {
        res = temp.top();
        temp.pop();
        count++;
    }
    return res;
}

int main() {
    ListNode a(10);
    ListNode b(20);
    ListNode c(30);
    ListNode d(40);
    ListNode e(50);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *head = &a;
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    head = &a;
    ListNode *res = FindKthToTail(head, 1);
    cout << res->val << endl;
    cout << endl;
    return 0;
}