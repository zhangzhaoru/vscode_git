/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 11:20:54
 * @LastTime: 2020-03-30 11:39:15
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\stringEncryption.cpp
 * @Description: ×Ö·û´®¼ÓÃÜ
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char shiftMove1(char c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
    if (c == 'Z') {
        c = 'A';
    } else if(c>='A'&&c<='Y'){
        c++;
    }
    if (c >= '0' && c <= '8') {
        c++;
    } else if (c == '9') {
        c = '0';
    }
    return c;
}

string stringEncryption(string str) {
    if (str.length() > 100) return "Error";
    string res;
    for (int i = 0; i < str.length(); i++) {
        res += shiftMove1(str[i]);
    }
    return res;
}

char shiftMove2(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c - 'A' + 'a';
    }
    if (c == 'A') {
        c = 'Z';
    } else if(c>='B'&&c<='Z'){
        c--;
    }
    if (c == '0') {
        c = '9';
    } else if (c >= '1' && c <= '9') {
        c--;
    }
    return c;
}

string unEncrypt(string str){
    if (str.length() > 100) return "Error";
    string res;
    for (int i = 0; i < str.length(); i++) {
        res += shiftMove2(str[i]);
    }
    return res;
}
int main() {
    string s = "abcdefg123";
    cout << stringEncryption(s) << endl;
    cout<<unEncrypt(stringEncryption(s))<<endl;
    return 0;
}