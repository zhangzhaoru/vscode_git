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
    scanf("%s",name);//�����ո񡢻��з���tabֹͣ����
    char ch = getchar();//getchar��\n����ch��
    printf("Say something to us :\n");
    gets(something);//��ȡ�������ַ���ֱ���������з�Ϊֹ
    printf("Your name is \"%s\".\n",name);
    printf("You say \" %s\".\n",something);
    printf("ch = [%c][%d]\n",ch,ch);
    return 0;
}

