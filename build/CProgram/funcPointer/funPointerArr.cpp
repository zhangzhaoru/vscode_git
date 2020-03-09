/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-08 19:22:00
 * @LastTime: 2020-03-08 19:28:28
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\funcPointer\funPointerArr.cpp
 * @Description: 函数指针数组
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

int main() {
    int a = 5;
    int b = 8;
    int (*p_func[3])(int,int) = {
        sum,
        difference,
        product
    };
    char name[3][20]={
        "sum",
        "difference",
        "product"
    };
    printf("p_func sizeof = %d\n",sizeof(p_func));
    for(int i = 0;i<3;i++){
        printf("%s(%d,%d)=%d\n",name[i],a,b,p_func[i](a,b));
    }
    return 0;
}