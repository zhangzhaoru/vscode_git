/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 19:18:28
 * @LastTime: 2020-03-26 19:22:57
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\countCaplital.cpp
 * @Description: 统计大写字符的个数
 */
#include<iostream>
#include<string>
using namespace std;

int CalcCapital(string s){
    int count = 0;
    for(int i = 0;i<s.length(); i++){
        if(s[i]>='A' && s[i]<='Z'){
            count++;
        }
    }
    return count;
}

int main() {
    string s = "add123#$%#%#O";
    cout<<CalcCapital(s)<<endl;
    return 0;
}
