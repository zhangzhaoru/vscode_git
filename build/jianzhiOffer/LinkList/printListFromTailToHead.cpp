/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 10:04:15
 * @LastTime: 2020-03-17 10:16:19
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\LinkList\printListFromTailToHead.cpp
 * \vscode_git\build\jianzhiOffer\LinkList\printListFromTailToHead.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> res;
    if (!head) return res;
    stack<ListNode*> temp;
    while (head) {
        temp.push(head);
        head = head->next;
    }
    while (!temp.empty()) {
        res.push_back(temp.top()->val);
        temp.pop();
    }
    return res;
}



//带头节点的链表：此种链表保存数据是从head->next开始的，
//head中并未保存有数据，访问时自然head->next开始，优点就是方便操作。
//以-1作为链表的结束
void CreateList_H(ListNode *&head){
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    ListNode *pre = head;
    int data;
    cin>>data;
    while(data!=-1){
        ListNode *last = (struct ListNode*)malloc(sizeof(struct ListNode));
        last->val = data;
        last->next = NULL;
        pre->next = last;
        pre = last;
        cin>>data;
    }
}

//不带头节点的链表：此种链表的head即保存第一个数据，访问时从head开始。
//不利于删除或者添加指定位置数据的操作。
void CreateList(ListNode *&head){
    int data;
    cin>>data;
    while(data!=-1){
        ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
        temp->val = data;
        temp->next = NULL;
        ListNode *pre;
        if(head==NULL){
            head = temp;
            pre = head; 
        }else{
            pre->next = temp;
            pre = temp;
        }
        cin>>data;
    }    
}

void printList(ListNode *head){
    while(head){
        cout<<head->val;
        head = head->next;
    }
    cout<<endl;
}

int main(){
    ListNode *head1;
    ListNode *head2;
    cout<<"Please create the list 1!"<<endl;
    CreateList_H(head1);
    printList(head1->next);

    vector<int> reserve = printListFromTailToHead(head1->next);
    for(int i = 0;i<reserve.size(); i++){
        cout <<reserve[i]<< " ";
    }
    cout<< endl;
    return 0;
}


