//鏈錶劃分
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *Partition(ListNode *head, int x) {
    ListNode moreHead(0);
    ListNode lessHead(0);
    ListNode *ptr1 = &lessHead;
    ListNode *ptr2 = &moreHead;
    int flag = 0;
    while (head) {
        if (head->val < x) {
            flag = 1;
            ptr1->next = head;
            ptr1 = ptr1->next;
        } else {
            ptr2->next = head;
            ptr2 = ptr2->next;
        }
        head = head->next;
    }
    if (flag) {
        ptr1->next = moreHead.next;
        return lessHead.next;
    } else {
        return moreHead.next;
    }
}

ListNode *Partition1(ListNode *head, int x) {
    ListNode Node(0);
    Node.next = head;
    ListNode *ptr = head;
    ListNode *temp,*tail;
    head->next = NULL;
    tail = head;
    while(ptr!=NULL){
        if(ptr->val<x){
            temp = Node.next;
            ptr->next = head->next;
            head->next = ptr;
            if(ptr->next==NULL)
                tail = ptr;
            ptr = temp;
        }else{
            tail->next = ptr;
            tail = ptr;
            ptr = ptr->next;
        }
    }
     tail->next = NULL;
     return Node.next;
}

int main() {
    ListNode a(80);
    ListNode b(30);
    ListNode c(40);
    ListNode d(20);
    ListNode e(50);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *head = &a;
    ListNode *result;
    result = Partition1(head, 30);
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    system("pause");
    return 0;
}