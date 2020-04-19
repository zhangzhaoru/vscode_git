/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-13 12:40:14
 * @LastTime: 2020-04-18 18:22:46
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\levenshteinDistance.cpp
 * @Description: Levenshteinæ‡¿Î
 */
#include <bits/stdc++.h>
using namespace std;

int calStringDistance(string origin, string target) {
    if (origin.length() == 0 && target.length() == 0) {
        return 0;
    }
    if (origin.length() == 0) {
        return target.length();
    }
    if (target.length() == 0) {
        return origin.length();
    }
    int dp[origin.length() + 1][target.length() + 1] = {0};
    for (int i = 0; i <= origin.length(); i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= target.length(); j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= origin.length(); i++) {
        for (int j = 1; j < target.length(); j++) {
            if (origin[i - 1] == target[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
        }
    }
    return dp[origin.length() - 1][target.length() - 1];
}

int main() {
    string origin = "abcdefg";
    string target = "abcdef";
    int res = calStringDistance(origin,target);
    cout<<res<<endl;
    return 0;
}