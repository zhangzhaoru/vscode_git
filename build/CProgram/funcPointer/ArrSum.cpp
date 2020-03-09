/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-08 19:55:27
 * @LastTime: 2020-03-08 20:00:59
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\funcPointer\ArrSum.cpp
 * @Description: 1 2 2 3 3 3寻找第n个数的
 */
#include<iostream>
using namespace std;
int theNum(int n){
    int curNum = 1;
    while((int)curNum*(curNum+1)/2<=n){
        curNum++;
    }
    return curNum;
}

int main() {
    int n = 200;
    int res = theNum(n);
    cout<<res<<endl;
    return 0;
}