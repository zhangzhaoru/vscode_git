/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-06 23:42:28
 * @LastTime: 2020-04-07 00:04:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\deleteNode.cpp
 * @Description: 删除指定节点
 */

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteNode(ListNode *head, int target) {
    ListNode *pre = head;
    ListNode *res = NULL;
    ListNode *node = head;
    if (!head) {
        return res;
    }
    if (head->val == target) {
        res = node->next;
        return res;
    }
    node = node->next;
    while (node) {
        if (node->val == target) {
            pre->next = node->next;
            return head;
        }
        node = node->next;
        pre = pre->next;
    }
    return NULL;
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
    cout<<"===============deletenode=================="<<endl;
    ListNode *res = deleteNode(head, 60);
    if (!res) {
        cout << "Can't find the target node! " << endl;
    } else {
        while (res) {
            cout << res->val << " ";
            res = res->next;
        }
    }
    return 0;
}