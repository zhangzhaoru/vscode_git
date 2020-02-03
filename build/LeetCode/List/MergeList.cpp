//合并两个排序链表
//链表区间段逆序
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode * mergeTwoList(ListNode* l1,ListNode *l2){
    ListNode tempHead(0);
    ListNode *pre = &tempHead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if(l1){
        pre->next = l1;
    }
    if(l2){
        pre->next = l2;
    }
    return tempHead.next;
}

int main(){
    ListNode a(10);
    ListNode b(30);
    ListNode c(20);
    ListNode d(40);
    ListNode e(50);
    a.next = &b;
    c.next = &d;
    d.next = &e;
    ListNode *l1 = &a;
    ListNode *l2 = &c;
    ListNode *reverseHead = NULL;
    reverseHead = mergeTwoList(l1,l2);
    while(reverseHead){
        cout<<reverseHead->val<<" ";
        reverseHead = reverseHead->next;
    }
    cout<<endl;
    system("pause");
    return 0;
}