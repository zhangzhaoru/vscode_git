/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 11:09:24
 * @LastTime: 2020-02-21 11:15:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\ClimbingStairs.cpp
 * @Description:爬楼梯
 */
#include <iostream>
#include <vector>
using namespace std;

int climbStaiars(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(2);
    int i = 2;
    while(i<n){
        dp.push_back(dp[i-1]+dp[i-2]);
        i++;
    }
    return dp[n-1];
}

int main(){
    int res =climbStaiars(3);
    cout<<res<<endl;
    return 0;
}

