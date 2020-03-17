/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:15:49
 * @LastTime: 2020-03-13 19:18:42
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\VirConstruct.cpp
 * @Description:  存在虚析构函数
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
//建立指向虚函数表的指针，大小为4