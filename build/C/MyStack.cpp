/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-15 10:10:32
 * @LastTime: 2020-03-15 10:25:41
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\QueueAndStackRewrite.cpp
 * @Description: 实现队列与栈
 */
#include <iostream>
using namespace std;
class node {
   public:
    int val;
    node* next;
    node(int x = 0) {
        val = x;
        next = NULL;
    }
};

class stack {
   public:
    void pop();
    node* push(int val);
    void traverse();
    void clear();
    bool deleteNode(node* n);
    stack() {
        size = 0;
        top = NULL;
    }
    node* GetTop() { return top; }
    int GetSize() { return size; }
    bool isEmpty() { return size == 0; }

   private:
    node* top;
    int size;
    node* GetPre(node* n);
};

void stack::pop() {
    if (top == NULL) return;
    node* temp = top;
    top = top->next;
    temp = NULL;
    size--;
}// 删除链表头部节点，头部后移

node* stack::push(int val) {
    size++;
    if (top == NULL) {
        top = new node(val);
        return top;
    }
    node* temp = new node(val);
    temp->next = top;
    top = temp;
    return top;
}// 始终设置链表头部为栈顶

void stack::traverse() {
    if (top == NULL) {
        cout << "stack is empty!" << endl;
        return;
    }
    node* temp = top;
    cout << "the size of this stack is: " << size << endl
         << "stack is as follows: ";
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void stack::clear() {
    node* temp;
    size = 0;
    while (top) {
        temp = top;
        top = top->next;
        temp = NULL;
    }
}

node* stack::GetPre(node* n) {
    if (n == NULL) {
        cout << "this node has is NULL!" << endl;
        return NULL;
    }
    if (n == top) {
        cout << "this node has no pre node!" << endl;
        return NULL;
    }
    node* temp = top;
    while (temp->next) {
        if (temp->next == n) return temp;
    }
    cout << "this node does not exist in the stack!" << endl;
    return NULL;
}

bool stack::deleteNode(node* n) {
    node* temp = top;
    bool flag = false;
    while (temp) {
        if (temp == n) {
            size--;
            flag = true;
            if (temp == top) {
                top = top->next;
                break;
            } else {
                node* pre = GetPre(temp);
                pre->next = temp->next;
                break;
            }
        }
        temp = temp->next;
    }
    if (!flag) cout << "this node does not exist!" << endl;
    return flag;
}

int main() {
    stack s;
    cout << "检测压栈功能" << endl;
    cout << "压入1，2，3" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.traverse();
    cout << "检测出栈功能" << endl;
    s.pop();
    s.traverse();
    cout << "清除这个栈" << endl;
    s.clear();
    s.traverse();
    cout << "压入1，2，3，4，5" << endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.traverse();
    cout << "删除第二个结点" << endl;
    s.deleteNode(s.GetTop()->next);
    s.traverse();
    return 0;
}