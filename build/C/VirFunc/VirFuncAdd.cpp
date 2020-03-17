/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 21:50:31
 * @LastTime: 2020-03-13 21:56:57
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\VirFunc\VirFuncAdd.cpp
 * @Description: �麯�����ַ���麯����ַ
 */
#include<iostream>
using namespace std;
class Base{
    public:
    virtual void f(){cout<<"Base::f()"<<endl;}
    virtual void g(){cout<<"Base::g()"<<endl;}
    virtual void h(){cout<<"Base::h()"<<endl;}
};

typedef void(*Fun)(void);

int main() {
    Base b;
    Fun pFun = NULL;
    cout<<"�麯����ĵ�ַΪ �� "<<(int *)(&b)<<endl;
    cout<<"�麯�����һ�������ĵ�ַΪ �� "<<(int *)*(int *)(&b)+0<<endl;
    cout<<"�麯����ڶ��������ĵ�ַΪ �� "<<(int *)*(int *)(&b)+1<<endl;
    pFun = (Fun)*((int*)*(int*)(&b));
    pFun();
    return 0;
}