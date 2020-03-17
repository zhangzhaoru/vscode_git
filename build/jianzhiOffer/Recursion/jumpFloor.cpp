/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 19:59:31
 * @LastTime: 2020-03-17 20:06:24
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\recursion\jumpFloor.cpp
 * @Description: 没回只能跳1级或者2级台阶
 */
#include<iostream>
using namespace std;
int jumpFloor1(int number) {
    if (number == 1) {
        return 1;
    }
    if (number == 2) {
        return 2;
    }
    return jumpFloor1(number - 1) + jumpFloor1(number - 2);
}

int main() {
    cout << jumpFloor1(10) << endl;
    return 0;
}