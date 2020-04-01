/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 19:32:13
 * @LastTime: 2020-03-31 12:33:39
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\integer2iPAdress.cpp
 * @Description: 整数与IP地址之间的相互转化
 */
#include<iostream>
#include<string>
#include<vector>
#include <cstddef>
#include<algorithm>
#include<cmath>
using namespace std;

//十进制转化为二进制字符串
string dec2bin(int num){
    string res;
    while(num){
        if(num%2==0){
            res+='0';
        }else{
            res+='1';
        }
        num/=2;
    }
    while(res.length()<8){
        res+='0';
    }
    reverse(res.begin(),res.end());
    return res;
}

int bin2dec(string str){
    int num = 0;
    for(int i = 0;i<str.length(); i++){
        num += (str[i]-'0')*pow(2,str.length()-1-i);
    }
    return num;
}

int str2Num(string str){
    int num = 0;
    for(int i = 0;i<str.length(); i++){
        num = num*10+str[i]-'0';
    }
    return num;
}



vector<int> splitWords(string str) {
    str += '.';
    vector<int> res;
    string temp;
    int num = 0;
    int start = 0;
    size_t found = str.find_first_of('.');
    while (found != string::npos) {
        temp = str.substr(start, found - start);
        start = found + 1;
        found = str.find_first_of('.', start);
        res.push_back(str2Num(temp));
    }
    return res;
}

string ip2Number(string s){
    vector<int> number = splitWords(s);
    string res;
    for(int i = 0;i<number.size(); i++){
        res+=dec2bin(number[i]);
    }
    return res;    
}



int main() {
    string s = "10.0.3.193";
    string res = ip2Number(s);
    cout<<res<< endl;
    cout<<bin2dec(res)<<endl;
    return 0;
}