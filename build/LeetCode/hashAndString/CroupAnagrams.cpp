/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-15 11:46:21
 * @LastTime     : 2020-02-15 11:47:33
 * @LastAuthor: Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\CroupAnagrams.cpp
 * @Description: 同字符词语分组
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<string, vector<string>> anagram;
    vector<vector<string>> result;
    for (int i = 0; i < strs.size(); i++) {
        string str = strs[i];
        sort(str.begin(), str.end());
        if (anagram.find(str) == anagram.end()) {
            vector<string> item;
            anagram[str] = item;
        }
        anagram[str].push_back(strs[i]);
    }
    map<string, vector<string>>::iterator it;
    for (it = anagram.begin(); it != anagram.end(); it++) {
        result.push_back((*it).second);
    }
    return result;
}

/**
 * @Name: groupAnagrams1
 * @Param: map<vector<int>,vector<string>> anagram;
 * @Return: 
 * @Description: key为长度为26的的vector，统计单词各个自字符数量
 */
void changeToVector(string &str,vector<int> &vec){
    for(int i = 0;i<26;i++){
        vec.push_back(0);
    }
    for(int i = 0;i<str.length();i++){
        vec[str[i]-'a']++;
    }
}

vector<vector<string>> groupAnagrams1(vector<string> &strs) {
    map<vector<int>,vector<string>> anagram;
    vector<vector<string>> result;
    for(int i = 0;i<strs.size();i++){
        vector<int> vec;
        changeToVector(strs[i],vec);
        if(anagram.find(vec)==anagram.end()){
            vector<string> item;
            anagram[vec] = item;
        }
        anagram[vec].push_back(strs[i]);
        map<vector<int>,vector<string>>::iterator it;
        for(it = anagram.begin();it!=anagram.end();it++){
            result.push_back((*it).second);
        }
        return result;
    }     
}

int main() {
    vector<string> strs = {"asd", "sda", "dsa", "hjk", "jkh"};
    vector<vector<string>> res;
    res = groupAnagrams1(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}