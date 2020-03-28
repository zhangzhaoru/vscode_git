/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 10:23:32
 * @LastTime: 2020-03-26 10:27:36
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\reverseStr.cpp
 * @Description: ×Ö·û´®·­×ª
 */
#include <iostream>
#include <string>
using namespace std;

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

int main() {
    string s = "abcd";
    s = reverseStr(s);
    cout << s << endl;
    return 0;
}