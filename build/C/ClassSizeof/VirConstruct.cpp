/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:15:49
 * @LastTime: 2020-03-13 19:18:42
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\VirConstruct.cpp
 * @Description:  ��������������
 */

#include<iostream>
using namespace std;
class Base{
    public:
    Base(){}
    virtual ~Base(){}
};

int main() {
    cout<<sizeof(Base)<<endl;
    return 0;
}
//����ָ���麯�����ָ�룬��СΪ4