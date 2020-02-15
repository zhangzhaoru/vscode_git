/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-14 16:14:27
 * @LastTime     : 2020-02-14 16:33:19
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\longestPalingrome.cpp
 * @Description:  最长回文串
 */

#include <iostream>
#include <string>
using namespace std;

int longeestPalingrome(string s) {
    int charMap[128] = {0};
    int maxLength = 0;
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
        charMap[s[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (charMap[i] % 2 == 0) {
            maxLength += charMap[i];
        } else {
            flag = 1;
            maxLength += charMap[i] - 1;
        }
    }
    return maxLength + flag;
}

int main() {
    string s = "aaasssscdsddd";
    int Count = longeestPalingrome(s);
    cout << Count << endl;
    return 0;
}