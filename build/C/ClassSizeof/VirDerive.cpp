/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:29:46
 * @LastTime: 2020-03-13 19:31:37
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\VirDerive.cpp
 * @Description: 虚继承，在原来的基础上添加一个间接指针
 */
#include <iostream>  
using namespace std;  
class Base  
{  
public:  
    Base();                  
    virtual ~Base();           
    void set_num(int num)    //普通成员函数  
    {  
        a=num;  
    }  
private:  
    int  a;                  //占4字节  
    char *p;                 //4字节指针  
};  
class Derive:virtual public Base  
{  
public:  
    Derive():Base(){};       
    ~Derive(){};  
    virtual void foo() { }  
private:  
    static int st;         //非实例独占  
        int  d;                //占4字节  
};  
int main(int argc, char *argv[])   
{   
    cout<<sizeof(Base)<<endl;  
    cout<<sizeof(Derive)<<endl;  
    return 0;  
}  
/* 这里由于虚继承而引入了一个间接的指针(vbc)，
该指针是指向虚函数表的一个slot，表中存放着该
slot中存放虚基类子对象的偏移量的负值。所以大
小比之前多了4字节。就算同时虚继承自两个类，也
只会有一个这样的间接指针，也就是大小也只多4字节。 */