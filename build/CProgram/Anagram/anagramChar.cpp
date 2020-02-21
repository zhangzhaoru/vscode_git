/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 11:29:35
 * @LastTime: 2020-02-21 16:38:39
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\Anagram\anagramChar.cpp
 * @Description:字符串全排列
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int cmp(char a, char b) {
    if (tolower(a) != tolower(b)) {
        return tolower(a) < tolower(b);
        // tolower将大写字符转化为小写字母
    } else {
        return a < b;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char s[20];
    while (n--) {
        scanf("%s", s);
        int len = strlen(s);
        sort(s, s + len, cmp);
        do {
            printf("%s\n", s);
        } while (next_permutation(s, s + len, cmp));  //自定义函数的使用
    }
    return 0;
}