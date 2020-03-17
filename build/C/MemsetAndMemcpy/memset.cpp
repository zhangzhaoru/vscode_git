/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-15 11:49:35
 * @LastTime: 2020-03-15 11:54:06
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\MemsetAndMemcpy\memset.cpp
 * @Description: 将s所指向的某一块内存中的每个字节的内容全部设置为
 * ch指定的ASCII值,块的大小由第三个参数指定,这个函数通常为新申请的内
 * 存做初始化工作
 */
#include<string.h>
#include<stdio.h>
#include<memory.h>

int main(){
    char buffer[] = "Hello world\n";
    printf("Buffer before memset : %s\n",buffer);
    memset(buffer,'*',strlen(buffer));
    printf("Buffer after memset: %s\n",buffer);
    return 0;
}