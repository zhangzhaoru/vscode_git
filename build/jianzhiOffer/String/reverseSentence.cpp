/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 10:31:27
 * @LastTime: 2020-03-30 16:27:40
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\reverseSentence.cpp
 * @Description: ??????????
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

string reverseStr(string s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return s;
}

string reverseSentence(string s) {
    vector<string> words = splitWords(s);
    string res = "";
    for (int i = words.size() - 1; i >= 1; i--) {
        res += reverseStr(words[i]);
        res += ' ';
    }
    res += words[0];
    res += '\0';
    return res;
}

int main() {
    string s = "I am a boy";
    string res = reverseSentence(s);
    cout << res << endl;
    return 0;
}