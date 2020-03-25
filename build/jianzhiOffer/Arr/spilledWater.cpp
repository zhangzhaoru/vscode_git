/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-24 23:14:20
 * @LastTime: 2020-03-24 23:14:34
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\spilledWater.cpp
 * @Description: 上一个容器满后自动溢出至下一个容器，leave表示遗留的水，put表示注入的水
 * 求最终溢出的水
 */

#include <iostream>
#include <vector>
using namespace std;
int leftWater(int N, int X, vector<int> leave, vector<int> put) {
    int res = 0;
    if (X < (leave[0] + put[0])) {
        put[1] = put[1]+(leave[0] + put[0]) - X;
    }
    cout<<put[1]<<endl;
    for (int i = 1; i <= N - 2; i++) {
        if (X < (leave[i] + put[i])) {
            put[i + 1] = put[i + 1] + (leave[i] + put[i]) - X; 
        }
    }
    if (X >= (leave[N - 1] + put[N - 1])) {
        res = 0;
    } else {
        res = leave[N - 1] + put[N - 1] - X;
    }
    return res;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> leave, put;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        leave.push_back(x);
        put.push_back(y);
    } 
    int res = leftWater(N, X, leave, put);
    cout << res << endl;
    system("pause");
    return 0;
}