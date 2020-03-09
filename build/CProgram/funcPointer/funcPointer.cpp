/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-07 18:30:21
 * @LastTime: 2020-03-07 18:36:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\funcPointer\funcPointer.cpp
 * @Description: 函数指针定义与调用方式
 */
#include <stdio.h>
int sum(int x,int y){
    return x+y;
}

int difference(int x,int y){
    return x-y;
}

int product(int x,int y){
    return x*y;
}
int main(){
    int a = 5;
    int b = 8;
    int (*p_func[3])(int,int) = {
        sum,
        difference,
        product
    };
    for(int i = 0;i<3;i++){
        printf("(%d,%d) = %d\n",a,b,p_func[i](a,b));
    }
    return 0;
}