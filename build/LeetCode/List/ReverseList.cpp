//实现链表逆序
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* reverseList(ListNode *head){
    ListNode * newHead = NULL;
    while(head){
        ListNode *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

int main(){
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
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    head = &a;
    ListNode *reverseHead = NULL;
    reverseHead = reverseList(head);
    while(reverseHead){
        cout<<reverseHead->val<<" ";
        reverseHead = reverseHead->next;
    }
    cout<<endl;
    system("pause");
    return 0;
}