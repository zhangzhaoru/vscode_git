/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 20:19:46
 * @LastTime: 2020-03-28 21:05:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\searchBrotherWord.cpp
 * @Description: ����diac�е�index��brotherWord
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isBrother(string str1, string str2) {
    if (str1.size() != str2.size()) {
        return false;
    }
    if (str1 == str2) {
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    if (str1 == str2) {
        return true;
    } else {
        return false;
    }
}

string searchBrotherWord(vector<string> strs, string target, int index) {
    sort(strs.begin(), strs.end());
    // ���ֵ�������
    int count = 0;
    string res;
    for (int i = 0; i < strs.size(); i++) {
        if (isBrother(target, strs[i])) {
            count++;
            if (count == index) {
                res = strs[i];
            }
        }
    }
    if (!strs.empty()) {
        cout << count << endl;
        // brother�ܸ���
    }
    if (count >= index) {
        return res;
        //��index��brother
    }
    return "-1";
}

int main() {
    vector<string> dict = {"bca", "cab", "abc"};
    string target = "abc";
    int index = 1;
    string res = searchBrotherWord(dict, target, index);
    cout << res << endl;
    return 0;
}