/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 11:19:34
 * @LastTime: 2020-03-26 11:22:23
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\splitWords.cpp
 * @Description: ·Ö¸ô×Ö·û´®
 */
#include <string.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitWord(string str) {
    stringstream temp(str);
    string ss;
    vector<string> res;
    while (temp >> ss) {
        res.push_back(ss);
    }
    return res;
}

vector<string> splitWords(string s) {
    int pointer1 = 0;
    int pointer2 = 0;
    s += ' ';
    vector<string> res;
    while (s[pointer2]) {
        if (s[pointer2] == ' ') {
            res.push_back(s.substr(pointer1, pointer2 - pointer1));
            pointer2++;
            pointer1 = pointer2;
        } else {
            pointer2++;
        }
    }
    return res;
}

int main() {
    string s = "I Loving Code";
    vector<string> res = splitWords(s);
    for(int i=0;i<res.size(); i++){
        cout<<res[i]<< endl;
    }
    return 0;
}