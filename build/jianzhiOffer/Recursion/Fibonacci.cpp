/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 18:58:35
 * @LastTime: 2020-03-17 19:04:04
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\recursion\Fibonacci.cpp
 * @Description: 
 */
#include<iostream>
using namespace std;

int Fibonacci(int n){
    if(n== 0)
        return 0;
    if(n==1){
        return 1;
    }
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int main() {
    int n = 8;
    cout<<Fibonacci(n)<<endl;
    return 0;
}