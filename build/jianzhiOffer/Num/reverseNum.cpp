/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 10:09:22
 * @LastTime: 2020-03-26 10:18:19
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\reverseNum.cpp
 * @Description: Êı×ÖÄæĞòÒÔ×Ö·û´®Êä³ö
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseNum(int num) {
    vector<int> temp;
    string res = "";
    while (num) {
        res+=(num % 10)+'0';
        num /= 10;
    }
    return res;
}

int main() {
    int num = 101243;
    string s = reverseNum(num);
    cout << s << endl;
    return 0;
}