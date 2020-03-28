/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 12:54:32
 * @LastTime: 2020-03-26 12:58:22
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\countOne.cpp
 * @Description: 记录二进制数字中1的个数0
 */
#include<iostream>
using namespace std;

int countOne(int num){
    int count = 0;
    while(num){
        count++;
        num&=(num-1);
    }
    return count;
}

int main() {
    cout<<countOne(5)<<endl;
    return 0;
}
