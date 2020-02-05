//使用栈实现队列
#include<iostream>
#include<stack>

using namespace std;

class MyQueue{
public:
    MyQueue(){}
    void push(int x){
        input.push(x);
    }
    int pop(){
        adjust();
        int x = output.top();
        output.pop();
        return x;
    }
    int peek(){
        adjust();
        return output.top();
    }
    bool empty(){
        return input.empty() && output.empty();
    }
    int size(){
        return input.size()+output.size();
    }
private:
    void adjust(){
        if(!output.empty()){
            return;
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    stack<int> input;
    stack<int> output; 
};

int main(){
    MyQueue Solution;
    Solution.push(1);
    Solution.push(2);
    Solution.push(3);
    Solution.push(4);
    Solution.push(5);
    int len = Solution.size();
    for(int i = 0;i<len;i++){
        cout<<Solution.pop()<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}