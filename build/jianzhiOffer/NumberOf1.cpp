/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 20:37:43
 * @LastTime: 2020-03-17 21:01:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\NumberOf1.cpp
 * @Description: 二进制中1的个数
 */

#include <bitset>
#include <iostream>
using namespace std;

int numberOf1(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = (n - 1) & n;
        //将二进制代码中最第位1变为0
    }
    return count;
}

int main() {
    bitset<10> bit("010101");
    int a = bit.to_ullong();
    int count = numberOf1(a);
    cout << count << endl;
    return 0;
}