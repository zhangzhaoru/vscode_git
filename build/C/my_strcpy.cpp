/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 20:50:51
 * @LastTime: 2020-02-27 21:00:26
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\mt_strcpy.cpp
 * @Description: 
 */
#include <stdio.h>
#include<string.h>

void my_strcpy(char *to,const char *from){
    int i = 0;
    while(from[i]){
        to[i] =from[i];
        i++;
    }
    to[i]+='\0';
}

void my_strcpy_s(char *to,int size,const char *from){
    int i = 0;
    size--;
    while(from[i] && i<size){
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

int main(){
    char str[10] = "123456789";
    char str2_1[20] = "13456789123456789";
    char str2_2[20] = "13456789123456789";
    char str2_3[20] = "13456789123456789";
    printf("str = [%s]\n",str);
    printf("str2_1 = [%s]\n",str2_1);
    printf("str2_2 = [%s]\n",str2_2);
    printf("str2_3 = [%s]\n",str2_3);
    strcpy(str2_1,str);
    my_strcpy(str2_2,str);
    my_strcpy_s(str2_3,20,str);
    printf("str2_1 = [%s]\n",str2_1);
    printf("str2_2 = [%s]\n",str2_2);
    printf("str2_3 = [%s]\n",str2_3);
    char str3[5];
    my_strcpy_s(str3,sizeof(str3),str);
    printf("str3 = [%s]\n",str3);
    return 0;
}