//判断合法的出栈序列
#include <iostream>
#include <queue>
#include <stack>
#include<vector>
using namespace std;

bool checkIsValidOrder(queue<int> &order) {
    stack<int> s;
    int len = order.size();
    for (int i = 1; i <= len; i++) {
        s.push(i);
        if (!s.empty() && s.top() == order.front()) {
            s.pop();
            order.pop();
        }
    }
    if (!s.empty()) {
        return false;
    }
    return true;
}

int main() {
    vector<int> data = {1,2,3,4,5};
    int len = data.size();
    queue<int> order;

    for (int i = 0; i < len; i++) {
        cout<<data[i];
        order.push(data[i]);
    }
    cout << endl;
    bool res = checkIsValidOrder(order);
    if (res) {
        cout << "The stack order is valid! " << endl;
    } else {
        cout << "The stack order is not valid! " << endl;
    }
    system("pause");
    return 0;
}
