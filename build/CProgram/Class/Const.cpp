/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-22 11:03:47
 * @LastTime: 2020-02-22 11:16:27
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\Class\Const.cpp
 * @Description:
 */
// const成员只能调用const函数
// 普通成员变量可以调用非const对象也可以调用const函数
#include <iostream>
using namespace std;

class A {
   public:
    A(int i = 0) : ci(i), num(i) {}
    int get_ci() const { return ci; }
    void show() const {
        cout << num * ci << endl;
        get_ci();
        cout << "show() const" << endl;
    }
    void show() { cout << "show()" << endl; }
    int set_num(int i) { num = i; }

   private:
    const int ci;
    int num;
};

int main() {
    A a;
    const A ca;
    ca.show();
    a.show();
    return 0;
}