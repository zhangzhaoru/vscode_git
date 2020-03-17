/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 09:52:02
 * @LastTime: 2020-03-17 09:58:45
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\replaceSpace.cpp
 * @Description:
 */
#include<iostream>
using namespace std;
void replaceSpace(char *str, int length) {
    if (str == NULL || length < 0) return;
    int blankNumber = 0;
    int oldSize = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            blankNumber++;
        }
        oldSize++;
    }
    int newSize = oldSize + blankNumber * 2;
    int pointer1 = oldSize;
    int pointer2 = newSize;
    while (pointer1 < pointer2 && pointer1 >= 0) {
        if (str[pointer1] == ' ') {
            str[pointer2--] = '0';
            str[pointer2--] = '2';
            str[pointer2--] = '%';
        } else {
            str[pointer2] = str[pointer1];
            pointer2--;
        }
        pointer1--;
    }
}

int main() {
    int length = 20;
    char str[length] = "We Are Happy.";
    replaceSpace(str,length);
    cout<<str;
    return 0;
}