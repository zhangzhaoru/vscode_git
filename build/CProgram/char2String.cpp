/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-13 11:24:36
 * @LastTime     : 2020-02-13 11:48:39
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\CProgram\char2String.cpp
 * @Description: string char* &int 相互转化
 */
#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string s = "90";
    int a = 123;
    s += to_string(a);  //将整形123转换为字符串123之后添加到字符串s中
    cout << s << endl;  //输出90123
    char ch[4] = "123";
    int b = atoi(ch);  //将字符串转换为int型，字符串123转换为数字123
    cout << b << endl;
    char c = '9';
    int c_to_i = c - '0';  //单个字符数字转换为int型
    string str = "123";
    // atoi(str);//报错
    string s="0123456789";
	char op[15];
	strncpy(op,s.c_str(),s.length()+1);
    ///s.c_str() 字符强制转化为字符串函数
    return 0;
}
