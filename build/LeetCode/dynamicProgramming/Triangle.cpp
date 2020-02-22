/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 17:36:17
 * @LastTime: 2020-02-21 18:19:07
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\Triangle.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &Triangle) {
    if (Triangle.size() == 0) {
        return 0;
    }
    vector<vector<int>> dp;
    for (int i = 0; i < Triangle.size(); i++) {
        vector<int> temp;
        for (int j = 0; j < Triangle[i].size(); j++) {
            temp.push_back(0);
        }
        dp.push_back(temp);
    }
    for (int i = 0; i < Triangle[Triangle.size() - 1].size(); i++) {
        dp[dp.size() - 1][i] = Triangle[Triangle.size() - 1][i];
    }
    for (int i = dp.size() - 2; i >= 0; i--) {
        for (int j = 0; j < Triangle[i].size(); j++) {
            dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + Triangle[i][j];
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> Triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int res = minimumTotal(Triangle);
    cout << "the minimum total is : " << res << endl;
    return 0;
}
