/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 16:36:43
 * @LastTime: 2020-03-30 16:54:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\longestSymSubstr.cpp
 * @Description: 最长对称子串长度
 */
#include<iostream>
#include<string>
using namespace std;

int longestSymSubstr(string s){
    const int len = s.size();
    int maxLength = 0;
    for(int i =1;i<len;i++){
        int begin =i-1;
        int end = i;
        while(begin>=0&&end<=len-1&&s[begin]==s[end]){
            begin--;
            end++;
        }
        if(end-begin+1>maxLength){
            maxLength = end-begin-1;
        }
        begin = i-1;
        end = i+1;
        while(begin>=0&&end<=len-1&&s[begin]==s[end]){
            begin--;
            end++;
        }
        if(end-begin+1>maxLength){
            maxLength = end-begin-1;
        }
    }
    return maxLength;
}

int main() {
    string s = "dasdABBAdpsfk";
    cout<<longestSymSubstr(s)<<endl;
    return 0;
}