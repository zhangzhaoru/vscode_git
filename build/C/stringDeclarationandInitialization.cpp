/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 18:37:27
 * @LastTime: 2020-02-27 18:49:54
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\stringDeclarationandInitialization.cpp
 * @Description: 字符串的声明与初始化
 */
#include<stdio.h>
int main() {
    char str1[20] = "I Love coding .";
    //sizeof 为实际开辟的空间20
    printf("sizeof(str1) = %d\n",sizeof(str1));
    printf("str1 = [%s]\n",str1);
    int i = 0;
    while(str1[i]){
        printf("[%c] : %d\n",str1[i],str1[i]);
        i++;
    }
    printf("\n");
    char str2[] = "I Love Coding !";
    // sizeof为实际使用的空间16,包括结束字符
    printf("sizeof(str2) = %d\n",sizeof(str2));
    printf("str2 = [%s]\n",str2);
    i = 0;
    while(str2[i]){
        printf("[%c] : %d\n",str2[i],str2[i]);
        i++;
    }
    return 0;
}
