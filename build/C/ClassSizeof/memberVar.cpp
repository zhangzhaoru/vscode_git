/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:04:46
 * @LastTime: 2020-03-13 19:07:04
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\memberVar.cpp
 * @Description: ��Ա������Ҫ���봦��,�̳���̳л������ݳ�Ա
 */

#include <iostream>  
using namespace std;  
class Base  
{  
public:  
    Base();                  
    ~Base();           
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