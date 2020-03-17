/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:04:46
 * @LastTime: 2020-03-13 19:07:04
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\memberVar.cpp
 * @Description: 成员变量需要对齐处理,继承类继承基类数据成员
 */

#include <iostream>  
using namespace std;  
class Base  
{  
public:  
    Base();                  
    ~Base();           
    void set_num(int num)    //普通成员函数  
    {  
        a=num;  
    }  
private:  
    int  a;                  //占4字节  
    char *p;                 //4字节指针  
};  
class Derive:public Base  
{  
public:  
    Derive():Base(){};       
    ~Derive(){};  
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