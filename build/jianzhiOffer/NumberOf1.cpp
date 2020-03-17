/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 20:37:43
 * @LastTime: 2020-03-17 21:01:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\NumberOf1.cpp
 * @Description: ��������1�ĸ���
 */

#include <bitset>
#include <iostream>
using namespace std;

int numberOf1(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n = (n - 1) & n;
        //�������ƴ��������λ1��Ϊ0
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