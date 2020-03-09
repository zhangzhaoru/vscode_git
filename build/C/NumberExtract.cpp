/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 20:11:05
 * @LastTime: 2020-03-07 16:52:43
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\NumberExtract.cpp
 * @Description:
 */
#include <stdio.h>
int main() {
    char str[100] = "1234";
    int number = -1;
    int i;
    for (int i = 0; str[i]; i++) {
        if (number == -1) {
            if (str[i] >= '0' && str[i] <= '9') {
                number = str[i] - '0';
            }
        } else {
            if (str[i] >= '0' && str[i] <= '9') {
                number = number * 10 + str[i] - '0';
            } else {
                printf("%d\n", number);
                number = -1;
            }
        }
    }
    if (number != -1) {
        printf("%d\n", number);
    }
    return 0;
}