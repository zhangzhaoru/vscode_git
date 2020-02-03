//使用队列实现栈
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
   public:
    MyStack() {}
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while (!data.empty()) {
            temp.push(data.front());
            data.pop();
        }
        while (!temp.empty()) {
            data.push(temp.front());
            temp.pop();
        }
    }
    int pop() {
        int x = data.front();
        data.pop();
        return x;
    }
    int top() { return data.front(); }
    bool empty() { return data.empty(); }
    int size() { return data.size(); }

   private:
    queue<int> data;
};

int main() {
    MyStack Solution;
    Solution.push(10);
    Solution.push(20);
    Solution.push(30);
    Solution.push(40);
    Solution.push(50);
    int n = Solution.size();
    for (int i = 0; i < n; i++) {
        cout << Solution.top()<<" ";
        Solution.pop();
    }
    cout << endl;
    system("pause");
    return 0;
}