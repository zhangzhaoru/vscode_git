/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 22:45:38
 * @LastTime: 2020-03-25 22:55:53
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\round.cpp
 * @Description: 接收一个精度正浮点数值，四舍五入取整
 */
#include <iostream>
using namespace std;

int myRound(double d){
    int temp = ((int)(d*10))%10;
    int res = 0;
    if(temp>=5){
        res = (int)(d*10-temp)/10+1;
    }else{
        res = (int)(d*10-temp)/10;
    }
    return res;
}

int main() {
    double d = 5.43;
    cout<<myRound(d)<<endl;
    return 0;
}