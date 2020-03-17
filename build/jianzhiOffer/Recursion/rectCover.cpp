/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 20:20:02
 * @LastTime: 2020-03-17 20:30:36
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\recursion\rectCover.cpp
 * @Description: æÿ’Û∏≤∏«
 */
#include<iostream>
using namespace std;

int rectCover(int number){
    if(number==0)
        return 0;
    if(number==1)
        return 1;
    if(number==2)
        return 2;
    return rectCover(number-1)+rectCover(number-2); 
}

int main() {
    cout<<rectCover(10)<<endl;
    return 0;
}