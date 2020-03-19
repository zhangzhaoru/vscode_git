/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-18 19:10:32
 * @LastTime: 2020-03-18 19:32:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\CreatList.cpp
 * @Description: ͷ�巨��β�巨
 */
//ͷ�巨ʵ����������
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

//ͷ�巨����
void CreatListF(ListNode *&head,vector<int> data){
    ListNode *temp;
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    for(int i = 0;i<data.size();i++){
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->val = data[i];
        temp->next = head->next;
        head->next = temp;
    }
}

//β�巨ʵ��˳�����
void CreatListR(ListNode *&head,vector<int> data){
    ListNode * temp;
    ListNode * tail;
    head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    tail = head;
    for(int i = 0;i<data.size();i++){
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->val = data[i];
        tail->next = temp;
        tail = tail->next;
    }
    tail->next = NULL;
}

int main(){
    vector<int> data = {1,2,3,4,5};
    ListNode *head;
    CreatListR(head,data);
    head = head->next;
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}