/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-06 17:02:22
 * @LastTime: 2020-04-06 17:36:09
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\cutHunchar.cpp
 * @Description: 截取带有汉字的字符串
 */
#include<iostream>
#include<string>
using namespace std;

string curHanChar1(string str,int num){
    return str.substr(0,num);
} 
//string本身就会判断最后一个字节是否为多余的半个汉字，是的话不输出该字节。

// 汉字占两个字节，每个字节的ASCII码最高位均为1，由于char默认为带符号类型，所
// 以汉字的ASCII码小于0，而英文数字等其他字符占一个字节，ASCII码最高位为0，值
// 在0~127之间。因此，只需要判断该字节是否小于0就能推断出是否为半个汉字。再向前
// 推算有连续几个半个汉字，若有偶数个，则输出最后半个汉字，否则不输出。

string curHanChar2(string str,int num){
    int temp = num-1;
    while(temp>=0&&str[temp]<0){
        temp--;
    }
    if((num-temp)%2==0){
        num--;
    }
    return str.substr(0,num);
}

int countHunChar(string s){
    int count = 0;
    for(int i = 0;i<s.length(); i++){
        if(s[i]<0){
            count++;
        }
    }
    return count/2;
}

int main() {
    string str = "我ABC汉DEF张昭儒";
    int num = 6;
    cout<<curHanChar2(str,num)<<endl;
    cout<<countHunChar(str)<<endl;
    return 0;
}