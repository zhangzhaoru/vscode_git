//移除k个数字后获得可能的最小的新数字
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string removeKidgits(string num, int k) {
    stack<int> s;
    string res = "";
    for (int i = 0; i < num.size(); i++) {
        int number = num[i] - '0';
        while (!s.empty() && s.top() > number && k > 0) {
            s.pop();
            k--;
        }
        if (number != 0 || s.size() != 0) {
            s.push(number);
        }
    }
    while (!s.empty() && k > 0) {
        s.pop();
        k--;
    }
    stack<int> reverse;
    while (!s.empty()) {
        reverse.push(s.top());
        s.pop();
    }
    while (!reverse.empty()) {
        res.append(1, reverse.top() + '0');
        reverse.pop();
    }
    if (res == "") {
        return "0";
    }
    return res;
}

int main() {
    string num = "1432219";
    int k = 3;
    string res = removeKidgits(num,k);
    cout<<"the min subnumber is : "<<res<<endl;
    system("pause");
    return 0;              
}