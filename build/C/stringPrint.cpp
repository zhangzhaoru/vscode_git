/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 20:00:40
 * @LastTime: 2020-02-27 20:09:30
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\stringPrint.cpp
 * @Description: 
 */
#include<stdio.h>
int main() {
    char name[100];
    char something[100];
    puts("What is your name ?");
    printf("Please input : ");
    scanf("%s",name);//遇到空格、换行符、tab停止读入
    char ch = getchar();//getchar将\n读入ch中
    printf("Say something to us :\n");
    gets(something);//读取输入流字符，直到遇到换行符为止
    printf("Your name is \"%s\".\n",name);
    printf("You say \" %s\".\n",something);
    printf("ch = [%c][%d]\n",ch,ch);
    return 0;
}

