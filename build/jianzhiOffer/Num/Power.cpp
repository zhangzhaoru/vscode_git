/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 21:06:30
 * @LastTime: 2020-03-17 21:08:59
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Power.cpp
 * @Description:计算指数函数
 */
#include<iostream>
using namespace std;
double Power(double base, int exponent) {
    double res = 1.0;
    if (exponent == 0 && base != 0) return res;
    if (exponent > 0) {
        for (int i = 1; i <= exponent; i++) res = res * base;
    } else if (exponent < 0) {
        for (int i = 1; i <= -exponent; i++) {
            res = res / base;
        }
    }
    return res;
}

int main() {
    int base = 2;
    int exponent = 3;
    cout<<Power(base,exponent)<<endl;
    return 0;
}