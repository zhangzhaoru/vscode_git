/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 09:57:13
 * @LastTime: 2020-03-26 10:03:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\countDiffChar.cpp
 * @Description: 统计不同字符个数
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int countDiffChar(string s) {
    vector<int> hashMap(128, 0);
    for (int i = 0; i < s.length(); i++) {
        hashMap[s[i]]++;
    }
    int count = 0;
    for (int i = 0; i < 128; i++) {
        if (hashMap[i] != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    string s = "aabcd";
    int res = countDiffChar(s);
    cout << res << endl;
    return 0;
}