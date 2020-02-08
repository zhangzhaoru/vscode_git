//生成括号
//左括号与右括号的数量不超过n
//右括号不可以先于左括号放置
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void generate(string item, int left, int right,int n, vector<string> &result);
void generate(string item, int left, int right,int n, vector<string> &result) {
    if(left==n && right==n){
        result.push_back(item);
        return;
    }
    if(left<=n){
        generate(item+"(",left+1,right,n,result);
    }
    if(right<left){
        generate(item+")",left,right+1,n,result);
    }
}

int main() {
    vector<string> result;
    generate("", 0, 0, 2,result);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        cout << endl;
    }
    system("pause");
    return 0;
}
