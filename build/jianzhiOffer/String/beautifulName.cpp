/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-05 21:40:16
 * @LastTime: 2020-04-06 09:41:35
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\beautifulName.cpp
 * @Description: 每个字符拥有“漂亮度”，计算名字最大可能漂亮程度
 * 设置字符计数器，排序后从多至少依次赋权相加
 */
#include <bits\stdc++.h>
using namespace std;

int mostWeight(string str) {
    vector<int> charCount(26, 0);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            charCount[str[i] - 'a']++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            charCount[str[i] - 'A']++;
        }
    }
    sort(charCount.begin(), charCount.end());
    int w = 26;
    int res = 0;
    for (int i = 25; i >= 0; i--) {
        res += charCount[i] * w;
        w--;
    }
    return res;
}

int main() {
    string str = "zhangsan";
    int res = mostWeight(str);
    cout<<res<< endl;
    return 0;
}