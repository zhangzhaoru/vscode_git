/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-15 11:49:35
 * @LastTime: 2020-03-15 11:54:06
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\MemsetAndMemcpy\memset.cpp
 * @Description: ��s��ָ���ĳһ���ڴ��е�ÿ���ֽڵ�����ȫ������Ϊ
 * chָ����ASCIIֵ,��Ĵ�С�ɵ���������ָ��,�������ͨ��Ϊ���������
 * ������ʼ������
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