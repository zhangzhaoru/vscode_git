/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-19 10:55:49
 * @LastTime: 2020-03-19 11:13:44
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\Merge.cpp
 * @Description: 合并两个排序链表
 */
/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-19 10:51:52
 * @LastTime: 2020-03-19 10:54:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\ReverseList.cpp
 * @Description: 翻转链表
 */
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode *Merge(ListNode *pHead1,ListNode *pHead2){
    ListNode *pHead = new ListNode(-1);
    ListNode *res = pHead;
    while(pHead1!= NULL && pHead2!= NULL){
        if(pHead1->val<pHead2->val){
            pHead->next = pHead1;
            pHead1 = pHead1->next;
        }else{
            pHead->next = pHead2;
            pHead2  = pHead2->next;
        }
        pHead = pHead->next;
    }
    if(pHead1==NULL){
        pHead->next =pHead2;
    }
    if(pHead2==NULL){
        pHead->next = pHead1;
    }
    return res->next;    
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
    ListNode a1(15);
    ListNode b1(25);
    ListNode c1(35);
    ListNode d1(45);
    ListNode e1(55);
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;
    ListNode *head1 = &a1;
    ListNode *res = Merge(head,head1);
    while(res){
        cout<<res->val<<" ";
        res = res->next;
    }
    cout<<endl;
    return 0;
}