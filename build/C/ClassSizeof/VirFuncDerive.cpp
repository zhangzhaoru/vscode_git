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
    void set_num(int num)    //��ͨ��Ա����  
    {  
        a=num;  
    }  
private:  
    int  a;                  //ռ4�ֽ�  
    char *p;                 //4�ֽ�ָ��  
};  
class Derive:public Base  
{  
public:  
    Derive():Base(){};       
    ~Derive(){};  
    virtual void foo() { }  
private:  
    static int st;         //��ʵ����ռ  
        int  d;                //ռ4�ֽ�  
};  
int main(int argc, char *argv[])   
{   
    cout<<sizeof(Base)<<endl;  
    cout<<sizeof(Derive)<<endl;  
    return 0;  
}  
// �̳й��̼̳��˻�����麯����δ�½��麯����