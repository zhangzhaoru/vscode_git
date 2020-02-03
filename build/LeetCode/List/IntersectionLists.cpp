//两个链表的交点
//合并两个排序链表
//链表区间段逆序
#include<set>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode * getIntersectionNode1(ListNode *headA,ListNode *headB){
    std::set<ListNode *> nodeset;
    while(headA){
        nodeset.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if((nodeset.find(headB))!=nodeset.end()){
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

int getListLength(ListNode * head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

ListNode *forwardLongList(int longLength,int shortLength,ListNode *head){
    int delta = longLength-shortLength;
    while(head && delta){
        head = head->next;
        delta--;
    }
    return head;
}

ListNode * getIntersectionNode2(ListNode *headA,ListNode *headB){
    int ListLengthA = getListLength(headA);
    int ListLengthB = getListLength(headB);
    if(ListLengthA>ListLengthB){
        headA = forwardLongList(ListLengthA,ListLengthB,headA);
    }else{
        headB = forwardLongList(ListLengthB,ListLengthA,headB);
    }
    while(headA&&headB){
        if(headA==headB){
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}

int main(){
    ListNode a(10);
    ListNode b(30);
    ListNode c(20);
    ListNode d(40);
    ListNode e(50);
    ListNode a1(11);
    ListNode b1(12);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a1.next = &b1;
    b1.next = &c;
    ListNode *headA = &a;
    ListNode *headB = &a1;
    ListNode *reverseHead = NULL;
    while(headA){
        cout<<headA->val<<" ";
        headA = headA->next;
    }
    cout<<endl;
    while(headB){
        cout<<headB->val<<" ";
        headB = headB->next;
    }
    cout<<endl;
    headA = &a;
    headB = &a1;
    reverseHead = getIntersectionNode1(headA,headB);
    if(reverseHead){
        cout<<reverseHead->val;
    }
    cout<<endl;
    headA = &a;
    headB = &a1;
    reverseHead = getIntersectionNode2(headA,headB);
    if(reverseHead){
        cout<<reverseHead->val;
    }
    cout<<endl;

    system("pause");
    return 0;
}