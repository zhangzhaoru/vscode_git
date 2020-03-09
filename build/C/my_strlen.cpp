/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 20:43:45
 * @LastTime: 2020-02-27 20:49:22
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\my_strlen.cpp
 * @Description: 
 */
#include<stdio.h>
#include<string.h>
int my_strlen(const char *str){
    int i = 0;
    while(str[i]){
        i++;
    }
    return i;
}

int my_strlen_s(const char *str,int size){
    int i = 0;
    while(str[i] && i<size){
        i++;
    }
    return i;
}

int main(){
    char str[10] = "123456789";
    printf("str = [%s]\n",str);
    printf("strlen =%d\n",strlen(str));
    printf("my_strlen = %D\n",my_strlen(str));
    printf("mt_strlen_s = %d\n", my_strlen_s(str,sizeof(str)));
    return 0;
}
