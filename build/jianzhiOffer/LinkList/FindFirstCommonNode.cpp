#include<iostream>
#include<stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL) {}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2);

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2){
    if(!pHead1||!pHead2){
        return NULL;
    }
    stack<ListNode*> stack1;
    stack<ListNode*> stack2;
    while(pHead1){
        stack1.push(pHead1);
        pHead1 = pHead1->next;
    }
    while(pHead2){
        stack2.push(pHead2);
        pHead2 = pHead2->next;
    }
    ListNode *node1 ;
    ListNode *node2 ;
    ListNode *common = NULL;
    while(stack1.size() && stack2.size()){
        node1 = stack1.top();
        node2 = stack2.top();
        if(node1->val==node2->val){
            common = node1;
            stack1.pop();
            stack2.pop();
        }else{
            break;
        }
    }
    return common;
}


//带头节点的链表：此种链表保存数据是从head->next开始的，
//head中并未保存有数据，访问时自然head->next开始，优点就是方便操作。
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
    cout<<"Please create the list 2!"<<endl;
    CreateList_H(head2);

    printList(head1->next);
    printList(head2->next);
    ListNode *Common;
    Common = FindFirstCommonNode(head1,head2);
    cout<<"The first common node is: "
    <<Common->val<<endl;
    system("pause");
    return 0;
}