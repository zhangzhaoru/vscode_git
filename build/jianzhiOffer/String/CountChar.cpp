/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 19:32:57
 * @LastTime: 2020-03-25 19:50:58
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\CountChar.cpp
 * @Description: 计算字符串中指定字符个数
 */
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

void myTolower(string &s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = tolower(s[i]);
            // s[i]+=32;//+32转换为小写
            // s[i]=s[i]-'A'+'a';
        }
    }
}
//大写转化为小写

void myToupper(string &s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = toupper(s[i]);
            // s[i]-=32;//+32转换为小写
            // s[i]=s[i]-'a'+'A';
        }
    }
}
//小写转化为大写

void countChar(string str, char target) {
    map<int, int> hashMap;
    for (int i = 0; i < str.length(); i++) {
        hashMap[str[i]]++;
    }
    if (hashMap.find(target) != hashMap.end()) {
        cout << hashMap.find(target)->second << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    string s = "aaAAaabcdefg";
    myTolower(s);
    char c = 'a';
    countChar(s, c);
    return 0;
}