/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-01 19:31:02
 * @LastTime: 2020-04-01 20:51:45
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\problem1.cpp
 * @Description: 将字符串各个单词第二个字符小写变成大写
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

string test(string str){
    vector<string> words = splitWord(str);
    string res;
    for(int i = 0;i<words.size();i++){
        if(words[i].length()>=2){
            words[i][1] = words[i][1]-'a'+'A';
        }
        res+=words[i];
        res+=" ";
    }
    res = res.substr(0,res.length()-1);
    return res;
}


int main() {
    string str = "My name is x";
    string res = test(str);
    cout<< res<< endl;
    return 0;
}