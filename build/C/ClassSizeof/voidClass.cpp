/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 19:01:20
 * @LastTime: 2020-03-13 19:03:04
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ClassSizeof\voidClass.cpp
 * @Description: 空类实例化占1个字节
 */
#include<iostream>
using namespace std;
class Base{
    public:
    Base();
    ~Base();
};

int main() {
    cout<<sizeof(Base)<<endl;
}