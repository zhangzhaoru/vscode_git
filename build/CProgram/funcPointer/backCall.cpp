/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-08 19:31:58
 * @LastTime: 2020-03-08 19:38:34
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\funcPointer\backCall.cpp
 * @Description: 函数指针作为函数的参数
 */
#include<stdio.h>

int sum(int x,int y){
    return x+y;
}

int difference(int x,int y){
    return x-y;
}

int product(int x,int y){
    return x*y;
}
//回调函数

int compute_func(int (*p_func)(int,int),int x,int y){
    return p_func(x,y);
}

int main() {
    int a = 5;
    int b = 8;
    int result;
    result = compute_func(sum,a,b);
    printf("sum = %d\n",result);
    result = compute_func(difference,a,b);
    printf("difference = %d\n",result);
    result =  compute_func(product,a,b);
    printf("product = %d\n",result);
    return 0;
}