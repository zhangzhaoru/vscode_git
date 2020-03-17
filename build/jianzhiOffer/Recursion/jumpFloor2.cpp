/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 20:09:51
 * @LastTime: 2020-03-17 20:17:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\recursion\jumpFloor2.cpp
 * @Description: 一次所跳的台阶不受限制
 */
#include <iostream>
using namespace std;

int jumpFloor2(int number) {
    if (number == 1) {
        return 1;
    }
    return 2 * jumpFloor2(number - 1);
}

int main() {
    cout<<jumpFloor2(10)<<endl;
    return 0;
}