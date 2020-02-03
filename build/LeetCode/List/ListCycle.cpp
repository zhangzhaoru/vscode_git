//若链表存在环，返回起点，否则按返回NULL
//快慢指針方法
#include <iostream>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    set<ListNode *> nodeSet;
    while (head) {
        if (nodeSet.empty()) {
            nodeSet.insert(head);
        } else {
            if ((nodeSet.find(head)) != nodeSet.end()) {
                return head;
            }
            nodeSet.insert(head);
        }
        head = head->next;
    }
    return NULL;
}

ListNode *detectCycle1(ListNode *head) {
    ListNode *fast;
    ListNode *slow;
    fast = slow = head;
    while(fast->next && slow){
        fast = fast->next->next;
        slow = slow->next;
        if(fast==slow){
            break;
        }
    }
    if(!fast->next||!slow){
        return NULL;
    }
    ListNode *ptr1 = head;
    ListNode *ptr2 = slow;
    while(ptr1!=ptr2){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr1;
}

int main() {
    ListNode a(10);
    ListNode b(30);
    ListNode c(20);
    ListNode d(40);
    ListNode e(50);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &b;
    ListNode *head = &a;
    ListNode *result;
    result = detectCycle1(head);
    if (result) {
        cout << result->val;
    }
    cout << endl;
    system("pause");
    return 0;
}