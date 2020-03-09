/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-27 20:35:21
 * @LastTime: 2020-02-27 20:43:09
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\C\CountString.cpp
 * @Description: 
 */
#include<stdio.h>
int count_str_letters(char *str){
    int count = 0;
    int i = 0;
    while(str[i]){
        if(str[i]>='a' && str[i] <= 'z' || 
        str[i]>='A' && str[i]<='Z'){
            count++;
        }
        i++;
    }
    return count;
}
//统计str指向字符串中字母的个数

int count_str_array_letters(char str[][100],int n){
    int count = 0;
    int i;
    for(i = 0;i<n;i++){
        count+=count_str_letters(str[i]);
    }
    return count;
}

int main() {
    char str_array[20][100];
    int n;
    printf("Please input,strings number:\n");
    scanf("d%",&n);
    int i;
    printf("Please input strings,number :\n");
    for(i = 0;i<n;i++){
        scanf("%s",str_array[i]);
    }
    printf("letters = %d\n",count_str_array_letters(str_array,n));
    return 0;
}