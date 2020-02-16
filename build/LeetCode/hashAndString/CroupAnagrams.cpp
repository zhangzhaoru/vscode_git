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

int main() {
    vector<string> strs = {"asd", "sda", "dsa", "hjk", "jkh"};
    vector<vector<string>> res;
    res = groupAnagrams(strs);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}