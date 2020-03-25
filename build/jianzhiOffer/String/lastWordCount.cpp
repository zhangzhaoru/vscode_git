/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-24 15:08:12
 * @LastTime: 2020-03-24 15:18:35
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\lastWordCount.cpp
 * @Description: 计算最后一个单词长度
 */
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



int main() {
    string s = "I Love Coding";
    vector<string> res = splitWord(s);
    int count = res[res.size()-1].length();
    cout<<count<<endl;
    return 0;
}
