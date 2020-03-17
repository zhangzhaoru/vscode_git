/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 21:11:13
 * @LastTime: 2020-03-17 21:21:13
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\string2int.cpp
 * @Description: 字符串与整形数字的相互转化
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string num2str(double i)
{
        stringstream ss;
        ss<<i;
        return ss.str();
}

int str2num(string s)
 {   
        int num;
        stringstream ss(s);
        ss>>num;
        return num;
}

int main() {
    string str1 = "123456789";
    double x = str2num(str1);
    string str2 = num2str(x+1);
    cout<<str2<< endl;
    return 0;
}