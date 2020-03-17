/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:19:34
 * @LastTime: 2020-03-13 19:29:17
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\VirFuncDerive.cpp
 * @Description: 
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
class Derive:public Base  
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
// 继承过程继承了基类的虚函数表，未新建虚函数表