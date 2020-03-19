/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-19 10:51:52
 * @LastTime: 2020-03-19 10:54:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\ReverseList.cpp
 * @Description: ·­×ªÁ´±í
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

//
ListNode* reverseList(ListNode *head){
    ListNode tempHead(0);
    while(head){
        ListNode *next = head->next;
        head->next = tempHead.next;
        tempHead.next = head;
        head = next;
    }
    return tempHead.next;
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
    return 0;
}