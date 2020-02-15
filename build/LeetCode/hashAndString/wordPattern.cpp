/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-14 16:34:34
 * @LastTime     : 2020-02-15 11:42:51
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\wordPattern.cpp
 * @Description: 词语模式
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

bool wordPattern(string pattern, string str) {
    map<string, char> wordMap;
    char used[128] = {0};
    string word;
    int pointer = 0;
    str.push_back(' ');
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            if (pointer == pattern[pointer]) {
                return false;
            }
            if (wordMap.find(word) == wordMap.end()) {
                if (used[pattern[pointer]]) {
                    return false;
                }
                wordMap[word] = pattern[pointer];
                used[pattern[pointer]] = 1;
            } else {
                if (wordMap[word] != pattern[pointer]) {
                    return false;
                }
            }
            word = "";
            pointer++;
        } else {
            word += str[i];
        }
    }
    if (pointer != pattern.length()) {
        return false;
    }
    return true;
}

int main() {
    string pattern = "abba";
    string str = "cat ps ps cat";
    if (wordPattern(pattern, str)) {
        cout << "the pattern is mapping ! " << endl;
    } else {
        cout << "the pattern is not mapping ! " << endl;
    }
    return 0;
}