/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 11:11:11
 * @LastTime: 2020-03-17 11:19:29
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Queue_Stack\Stack2Queue.cpp
 * @Description: 使用栈实现队列
 */
#include<iostream>
#include<stack>
using namespace std;

class MyQueue
{
public:
    void push(int node) {
        stack1.push(node);
   
    }

    int pop() {
        if(stack2.empty())
        {
       while(stack1.empty()==false){
           stack2.push(stack1.top());
           stack1.pop();
       }
        }
        int result;
        if(stack2.empty()==false){
            result = stack2.top();
            stack2.pop();
        }
        else
            result = NULL;
        return result;
    }
    int size(){
        return stack1.size()+stack2.size();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    for(int i = 0;i<5; i++){
        int res = q.pop();
        if(res!=NULL)
            cout<<res<<" ";
    }
    cout<<endl;
    return 0;
}