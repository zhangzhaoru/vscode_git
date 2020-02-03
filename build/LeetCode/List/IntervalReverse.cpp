//链表区间段逆序
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right) {
    int count = right - left + 1;
    ListNode *preHead = NULL;
    ListNode *result = head;
    while (head && left--) {
        preHead = head;
        head = head->next;
    }
    ListNode *listTail = head;
    ListNode *newHead = NULL;
    while (head && count--) {
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    listTail->next = head;
    if (preHead) {
        preHead->next = newHead;
    } else {
        result = newHead;
    }
    return result;
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
    ListNode *reverseHead = NULL;
    reverseHead = reverseBetween(head, 1, 3);
    while (reverseHead) {
        cout << reverseHead->val << " ";
        reverseHead = reverseHead->next;
    }
    cout << endl;
    system("pause");
    return 0;
}