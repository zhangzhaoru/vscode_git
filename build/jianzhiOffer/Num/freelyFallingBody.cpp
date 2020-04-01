/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-01 16:05:56
 * @LastTime: 2020-04-01 16:21:55
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\freelyFallingBody.cpp
 * @Description: 自由落体反弹该高度为原先一半
 */
#include<iostream>
#include<vector>
using namespace std;

void distance(double height,double bounceCount){
    if(bounceCount==1){
        cout<< height<<endl;
        cout<<height/2<<endl;
        return ;
    }
    double res = height;
    double curHeight = height;
    for(int i = 2;i<=bounceCount;i++){
        curHeight/=2;
        res+=2*curHeight;
    }
    cout<<res<< endl;
    cout<<curHeight/2<<endl;
}


int main() {
    double height = 1;
    distance(height,5);
    return 0;
}