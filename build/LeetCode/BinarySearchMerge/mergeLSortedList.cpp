//合并K个排序链表
#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};
