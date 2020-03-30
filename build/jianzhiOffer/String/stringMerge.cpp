/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 11:39:53
 * @LastTime: 2020-03-30 16:31:16
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\stringMerge.cpp
 * @Description: 字符串合并
 */
#include <string.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

string convern(char c) {
    int num;
    if (c >= '0' && c <= '9') {
        num = c - '0';
    } else if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        if (c >= 'A' && c <= 'F') {
            c = c - 'A' + 'a';
        }  //大写转化为对应小写
        switch (c) {
            case 'a':
                num = 10;
                break;
            case 'b':
                num = 11;
                break;
            case 'c':
                num = 12;
                break;
            case 'd':
                num = 13;
                break;
            case 'e':
                num = 14;
                break;
            case 'f':
                num = 15;
                break;
        }
    }  // 16进制转化为10进制
    string Binres;
    while (num) {
        if (num) {
            if (num % 2 == 0) {
                Binres += '0';
            } else {
                Binres += '1';
            }
        }
        num /= 2;
    }  // 10进制转化为2进制反序
    //从高位开始补齐4位
    //reverse(Binres.begin(), Binres.end());
    while (Binres.length() < 4) {
        Binres += '0';
    }
    int tempNum = 0;
    for (int i = Binres.length() - 1; i >= 0; i--) {
        tempNum += (Binres[i] - '0') * pow(2, Binres.length() - 1 - i);
    }
    string res;
    if (tempNum >= 0 && tempNum <= 9) {
        res = tempNum + '0';
    } else {
        switch (tempNum) {
            case 10:
                res = 'A';
                break;
            case 11:
                res = 'B';
                break;
            case 12:
                res = 'C';
                break;
            case 13:
                res = 'D';
                break;
            case 14:
                res = 'E';
                break;
            case 15:
                res = 'F';
                break;
        }
    }
    return res;
}

char shiftChar(char c) {
    const string helper1 = "0123456789abcdefABCDEF";
    const string helper2 = "084C2A6E195D3B7F5D3B7F";
    char res;
    if (helper1.find(c) != -1) {
        res = helper2[helper1.find(c)];
    }
    return res;
}

string mergeSort(string str1, string str2) {
    string s;
    s = str1 + str2;
    int len = s.size();
    str1.clear();
    str2.clear();
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            str1 += s[i];
        } else {
            str2 += s[i];
        }
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    s.clear();
    for (int i = 0, j = 0, k = 0; i < len; i++) {
        if (i % 2 == 0) {
            s += str1[j++];
        } else {
            s += str2[k++];
        }
    }  //对于奇偶位分别进行排序
    string res;
    for(int i = 0;i<len;i++){
        res+=convern(s[i]);
    }
    return res;
}

//将16进制字符转化为2进制字符串反序后转为对应16进制字符
int main() {
    string str1 = "dec";
    string str2 = "fab";
    string res = mergeSort(str1,str2);
    cout<<res<< endl;
    return 0;
}