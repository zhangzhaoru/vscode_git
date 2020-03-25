/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 21:58:58
 * @LastTime: 2020-03-25 22:25:23
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\hexadecimalConversion.cpp
 * @Description: 进制转化
 */
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

//16进制转化为10进制
long long myConversion(string s) {
    int len = s.length();
    reverse(s.begin(),s.end());
    long long res = 0;
    int temp = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        switch (s[i]) {
            case 'A':
                temp = 10;
                break;
            case 'B':
                temp = 11;
                break;
            case 'C':
                temp = 12;
                break;
            case 'D':
                temp = 13;
                break;
            case 'E':
                temp = 14;
                break;
            case 'F':
                temp = 15;
                break;
            default:
                temp = s[i] - '0';
                break;
        }
        res = res+temp*pow(16,i);
    }
    return res;
}

int main() {
    long long res;
    string s = "ABCD123";
    res = myConversion(s);
    cout<<res<< endl;
    return 0;
}
