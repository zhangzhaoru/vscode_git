//动态数组
#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct Stu{
    int id;
    char name[20];
};

struct Stu_arr{
    struct Stu * pstu;
    int size;
};

int main(){
    struct Stu_arr ss;
    in
}

void init(struct Stu_arr *p_ss){
    p_ss->size = 0;
    p_ss->pstu = NULL;
}

void destroy(struct Stu_arr *p_ss){
    if(p_ss->pstu)
        free(p_ss->pstu);
}

void push_back(struct Stu_arr *p_ss,struct Stu *p_stu){
    struct Stu * p_new =
 
 0}