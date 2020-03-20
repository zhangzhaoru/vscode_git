/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-20 13:23:20
 * @LastTime: 2020-03-20 13:33:34
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Queue_Stack\StackMin.cpp
 * @Description: 实现带有min函数的栈
 */
#include <iostream>
#include <stack>
using namespace std;

class MyStack {
   public:
    void push(int value) {
        myStack.push(value);
        if (minStack.empty()) {
            minStack.push(value);
        }
        if (value < minStack.top()) {
            minStack.push(value);
        }
    }
    void pop() {
        if (minStack.top() == minStack.top()) {
            minStack.pop();
        }
        myStack.pop();
    }
    int top() { return myStack.top(); }
    int min() { return minStack.top(); }

   private:
    std::stack<int> myStack, minStack;
};

int main() {
    MyStack s;
    s.push(5);
    cout<<s.min()<<endl;
    s.push(4);
    cout<<s.min()<<endl;
    s.push(3);
    cout<<s.min()<<endl;
    cout<<endl;
}