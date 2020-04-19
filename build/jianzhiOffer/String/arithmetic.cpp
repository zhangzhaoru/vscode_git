/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-10 10:03:21
 * @LastTime: 2020-04-10 10:55:45
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\arithmetic.cpp
 * @Description: 实现四则运算
 */
#include<iostream>
#include<string>
#include <stack>
using namespace std;

//将字符串中中括号与大括号括号替换成小括号
string changeBracket(string str){
    for(int i = 0;i<str.length(); i++){
        if(str[i]=='['||str[i]=='{'){
            str[i]=='(';
        }
        if(str[i]==']'||str[i]=='}'){
            str[i]==')';
        }
    }
    return str;
}

// 中缀表达式转化为后缀表达式
int mid2Post(string str){
    int flag = 0;
    stack<int> num;
    stack<int> symbol;
    for(int i = 0;i<str.length(); i++){
        char temp;
        if(str[i]>='0'&&str[i]<='9'){
            
        }
    }
}