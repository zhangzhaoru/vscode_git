/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 14:01:18
 * @LastTime: 2020-03-28 14:34:37
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\simplePassWord.cpp
 * @Description:加密，大写变小写循环后移，小写依照九宫格对应转换为数字
 */
#include <iostream>
#include <string>
using namespace std;

char shiftMove(char C) {
    char c = C - 'A' + 'a';
    if (c == 'z') {
        c = 'a';
    } else {
        c = c + 1;
    }
    return c;
}

char capital2Num(char c) {
    char res;
    if (c >= 'a' & c <= 'c') {
        c = '2';
    }
    if (c >= 'd' & c <= 'f') {
        c = '3';
    }
    if (c >= 'g' & c <= 'i') {
        c = '4';
    }
    if (c >= 'j' & c <= 'l') {
        c = '5';
    }
    if (c >= 'm' & c <= 'o') {
        c = '6';
    }
    if (c >= 'p' & c <= 's') {
        c = '7';
    }
    if (c >= 't' & c <= 'v') {
        c = '8';
    }
    if (c >= 'w' & c <= 'z') {
        c = '9';
    }
    return c;
}

string encryption(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = shiftMove(s[i]);
        } else if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = capital2Num(s[i]);
        }
    }
    return s;
}

int main() {
    string s = "YUANzhi1987";
    string res = encryption(s);
    cout << res << endl;
    return 0;
}