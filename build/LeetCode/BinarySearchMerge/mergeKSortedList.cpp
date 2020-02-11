//合并K个已排序的链表
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode *a, ListNode *b) { return a->val < b->val; }

ListNode *mergeLists(ListNode * &head1,ListNode * &head2) {
    vector<ListNode *> nodeVec;
    while (head1) {
        nodeVec.push_back(head1);
        head1 = head1->next;
    }
    while (head2) {
        nodeVec.push_back(head2);
        head2 = head2->next;
    }
    if (nodeVec.empty()) {
        return NULL;
    }
    sort(nodeVec.begin(), nodeVec.end(), cmp);
    for (int i = 0; i < nodeVec.size() - 1; i++) {
        nodeVec[i]->next = nodeVec[i + 1];
    }
    nodeVec[nodeVec.size() - 1]->next = NULL;
    return nodeVec[0];
}

ListNode *mergeKLists(vector<ListNode *> &lists){
    if(lists.size()==0)
        return NULL;
    if(lists.size()==1){
        return lists[0];
    }
    if(lists.size()==2)
        return mergeLists(lists[0],lists[1]);
    int mid = lists.size()/2;
    vector<ListNode *> lists1;
    vector<ListNode *> lists2;
    for(int i = 0;i<mid;i++){
        lists1.push_back(lists[i]);
    }
    for(int i = mid;i<lists.size();i++){
        lists2.push_back(lists[i]);
    }
    ListNode *l1 = mergeKLists(lists1);
    ListNode *l2 = mergeKLists(lists2);
    return mergeLists(l1,l2);
}


int main() {
    ListNode a(1);
    ListNode b(3);
    ListNode c(5);
    ListNode d(7);
    ListNode e(9);
    ListNode a1(2);
    ListNode b1(4);
    ListNode c1(6);
    ListNode d1(8);
    ListNode e1(10);
    ListNode a2(11);
    ListNode b2(12);
    ListNode c2(13);
    ListNode d2(14);
    ListNode e2(15);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    a1.next = &b1;
    b1.next = &c1;
    c1.next = &d1;
    d1.next = &e1;
    a2.next = &b2;
    b2.next = &c2;
    c2.next = &d2;
    d2.next = &e2;
    ListNode *head1 = &a;
    ListNode *head2 = &a1;
    ListNode *head3 = &a2;
    vector<ListNode *> ListVec;
    ListVec.push_back(head1);
    ListVec.push_back(head2);
    ListVec.push_back(head3);
    ListNode *res = mergeKLists(ListVec);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}