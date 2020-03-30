/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 19:21:35
 * @LastTime: 2020-03-28 20:18:33
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\stringSort.cpp
 * @Description: 字符串排序
 *  规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
    规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
    规则 3 ：非英文字母的其它字符保持原来的位置。
 */


#include <iostream>
#include <vector>
#include<string>
using namespace std;
string String_Sorting(string str) {
    vector<char> temp;  
    for(int i = 0;i<26;i++){
        for(int j = 0;j<str.size();j++){
            if(str[j]-'a'==i||str[j]-'A'==i){
                temp.push_back(str[j]);
            }
        }
    }
    for(int i = 0,k = 0;i<str.size(),k<temp.size();i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            str[i] = temp[k++];
        }
    }
    return str;
}
//主函数
int main() {
    string str;
    //不能读取空格，读取空格制表符换行符停止读取   
    while (getline(cin, str)) {
        cout << String_Sorting(str) << endl;
    }
    return 0;
}