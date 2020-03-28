/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 12:41:00
 * @LastTime: 2020-03-28 13:40:10
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\passwordValid.cpp
 * @Description: 密码验证
 */
#include <iostream>
#include <string>
using namespace std;

//统计字符串中数字、大小写字母、特殊符号出现次数
int countSymbol(string str) {
    int lowerCount = 0;
    int capitalCount = 0;
    int numberCount = 0;
    int otherSymCount = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            lowerCount++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            capitalCount++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            numberCount++;
        } else {
            otherSymCount++;
        }
    }
    int res = 0;
    if (lowerCount) {
        res++;
    }
    if (capitalCount) {
        res++;
    }
    if (numberCount) {
        res++;
    }
    if (otherSymCount) {
        res++;
    }
    return res;
}

//相同子串长度不超过2
bool isRepeat(string str) {
    for (int i = 0; i < str.size() - 2; ++i)
        for (int j = i + 1; j < str.size() - 1; ++j) {
            int temp = 0;
            while (str[i + temp] == str[j + temp]){
                temp++;
            } 
            if (temp > 2){
                return false;
            } 
        }
    return true;
}

bool passwordValid(string passWord){
    if(passWord.length()<=8){
        return false;
    }
    if(countSymbol(passWord)<3){
        return false;
    }
    return isRepeat(passWord);
}

int main() {
    string  str = "021$bc9000";
    if(passwordValid(str)){
        cout<<"The password is valid !"<< endl;
    }else{
        cout<<"The password is invalid !"<< endl;
    }
    return 0;
}