/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:29:46
 * @LastTime: 2020-03-13 19:31:37
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\VirDerive.cpp
 * @Description: ��̳У���ԭ���Ļ��������һ�����ָ��
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
class Derive:virtual public Base  
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
/* ����������̳ж�������һ����ӵ�ָ��(vbc)��
��ָ����ָ���麯�����һ��slot�����д���Ÿ�
slot�д��������Ӷ����ƫ�����ĸ�ֵ�����Դ�
С��֮ǰ����4�ֽڡ�����ͬʱ��̳��������࣬Ҳ
ֻ����һ�������ļ��ָ�룬Ҳ���Ǵ�СҲֻ��4�ֽڡ� */