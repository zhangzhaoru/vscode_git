/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 18:48:56
 * @LastTime: 2020-02-27 19:59:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\stringEOF.cpp
 * @Description: ×Ö·û´®µÄ½áÊø·û
 */
#include<stdio.h>
int main() {
    char ch = '\0';
    printf("ch = %d\n",ch);
    char str[20] = "I Love Coding.\0";
    printf("str = [%s]\n",str);
    int i = 0;
    while(str[i]){
        printf("[%c] : %d\n",str[i],str[i]);
        i++;
    }
    printf("\n");
    for(i = 0;i<20;i++){
        printf("i = %d [%d][%c]\n",i,str[i],str[i]);
    }
    printf("\n");
    str[3] = '\0';
    printf("str = [%s]\n",str);
    printf("[%s]\n",&str[10]);
    return 0;
}