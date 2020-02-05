//设计一个包含min函数的栈
#include<iostream>
#include<stack>
using namespace std;

class MinStack{
public:
    MinStack(){}
    void push(int x){
            _data.push(x);
            if(_min.empty()){
                _min.push(x);
            }else{
                if(x>_min.top())
                    x = _min.top();
                _min.push(x);
            }
        }
        void pop(){
            _data.pop();
            _min.pop();
        }
        int top(){
            return _data.top();
        }
        int getMin(){
            return _min.top();
        }
    private:
        stack<int> _data;
        stack<int> _min;
};


int main(){
    MinStack Solution;
    Solution.push(5);
    Solution.push(4);
    Solution.push(3);
    Solution.push(2);
    cout<<"the current min number is : "<<Solution.getMin()<<endl;
    Solution.push(1);
    cout<<"the current min number is : "<<Solution.getMin()<<endl;
    Solution.pop();
    cout<<"the current min number is : "<<Solution.getMin()<<endl;

    system("pause");
    return 0;
}

