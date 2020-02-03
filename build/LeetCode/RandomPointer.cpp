//复杂链表深度拷贝
#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct RandonListNode{
    int label;
    RandonListNode *next,*random;
    RandonListNode(int x):label(x),next(NULL),random(NULL){}
};

RandonListNode *copyRandomList(RandonListNode *head){
    map<RandonListNode *,int> nodeMap;
    vector<RandonListNode *> nodeVec;
    RandonListNode *ptr = head;
    int i = 0;
    while(ptr){
        nodeVec.push_back(new RandonListNode(ptr->label));
        nodeMap[ptr] = i;
        i++;
        ptr = ptr->next;
    }
    ptr = head;
    i = 0;
    nodeVec.push_back(NULL);
    while(ptr){
        nodeVec[i]->next = nodeVec[i+1];
        if(ptr->random){
            int id = nodeMap[ptr->random];
            nodeVec[i]->random = nodeVec[id];
        }
        ptr = ptr->next;
        i++;
    }
    return nodeVec[0];
}

int main(){
    RandonListNode a(1);
    RandonListNode b(2);
    RandonListNode c(3);
    RandonListNode d(4);
    RandonListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a.random = &c;
    b.random = &d;
    c.random = &c;
    e.random = &d;
    RandonListNode *head = copyRandomList(&a);
    while(head){
        cout<<"label = "<<head->label<<" ";
        if(head->random){
            cout<<"rand = "<<head->random->label;
        }else{
            cout<<"rand = NULL";
        }
        cout<<endl;
        head = head->next;
    }
    system("pause");
    return 0;
}