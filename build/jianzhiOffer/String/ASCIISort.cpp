/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-31 12:37:10
 * @LastTime: 2020-03-31 12:46:54
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\photoAssign.cpp
 * @Description: 将字符串按照ASCII码进行排序
 */
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main() {
    string s;
    while(cin>>s){
        sort(s.begin(), s.end());
        cout<<s<< endl;
    }
    return 0;
}