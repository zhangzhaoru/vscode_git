/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-12 19:35:46
 * @LastTime: 2020-03-12 19:40:21
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \build\C\Abnormal.cpp
 * @Description:  异常的抛出与捕获
 */

#include<iostream>
using namespace std;
 double division(int a,int b){
     if(b==0){
         throw "Division by zero condition !";
     }
     return a/b;
 }

int main() {
    int x = 50;
    int y = 0;
    double z = 0;
    try{
        z = division(x,y);
        cout<<z<<endl;
    }catch(const char *msg){
        cerr<<msg<<endl;
    }
    return 0;
}
