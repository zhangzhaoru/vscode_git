/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 11:21:24
 * @LastTime: 2020-02-21 11:28:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\Anagram\anagramNum.cpp
 * @Description: 实现全排列函数
 */

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int s[3] = {1, 2, 3};
    do {
        cout << s[0] << s[1] << s[2] << endl;
    } while (next_permutation(s, s + 3));
    // 升序排列
    cout << endl;

    return 0;
}