/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 14:47:22
 * @LastTime: 2020-03-28 15:22:06
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\eraseLessChar.cpp
 * @Description: 删除出现最少的字符
 */
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

vector<char> findLessChar(string s){
    int count = s.length();
    map<char,int> charCount;
    vector<char> res;
    for(int i = 0;i<s.length(); i++){
        charCount[s[i]]++;
    }
    map<char,int>::iterator iter = charCount.begin();
    while(iter!=charCount.end()){
        if(iter->second<count){
            if(res.empty()){
                res.push_back(iter->first);
            }else{
                res.clear();
                res.push_back(iter->first);
            }
            count = iter->second;
        }else if(iter->second==count){
            res.push_back(iter->first);
        }
        iter++;
    }
    return res;
}

string eraseLessChar(string str){
    vector<char> eraseTarget = findLessChar(str);
    string::iterator it;
    for(it = str.begin();it!=str.end();it++){
        for(int i = 0;i<eraseTarget.size();i++){
            if(*it==eraseTarget[i]){
                str.erase(it);
                it--;
            }
        }
    }
    return str;
}

int main() {
    string s = "aaabccdde";
    string res = eraseLessChar(s);
    cout<< res << endl;
    return 0;
}