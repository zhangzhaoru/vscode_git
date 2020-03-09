/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 18:19:55
 * @LastTime: 2020-02-27 18:30:48
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\string.cpp
 * @Description: 
 */
#include <stdio.h>
int main() {
    char name[100];
    char something[100];
    printf("What is your name?\n");
    printf("Please input : ");
    scanf("%s",name);//读入字符串，直到换行，空格结束
    getchar();//从标准输入接收一个换行符
    printf("Say something to us : \n");
    gets(something);
    printf("Your name is : %s \n",name);
    printf("You say %s \n",something);
    printf("Your name is spelled :\n");
    int i = 0;
    while(name[i]){
        printf("%c\n",name[i]);
        i++;
    }
    printf("\n");
    return 0;
}