/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-17 16:20:11
 * @LastTime: 2020-02-17 16:20:11
 * @LastAuthor: Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\fingRepeatedDnaSequence.cpp
 * @Description: 重复的DNA序列
 */
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> findRepeatedDnaSequence(string s) {
    map<string, int> wordMap;
    vector<string> result;
    for (int i = 0; i < s.length(); i++) {
        string word = s.substr(i, 10);
        //从第i位开始长度位10的字符串
        if (wordMap.find(word) != wordMap.end()) {
            wordMap[word]++;
        } else {
            wordMap[word] = 1;
        }
    }
    map<string, int>::iterator it;
    for (it = wordMap.begin(); it != wordMap.end(); it++) {
        if ((it->second) > 1) {
            result.push_back(it->first);
        }
    }
    return result;
}

int main() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result;
    result = findRepeatedDnaSequence(s);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}