/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 21:12:18
 * @LastTime: 2020-03-28 21:17:40
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\primeMate.cpp
 * @Description: ËØÊý°éÂÂ
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

bool isPrime(int num){
    for(int i = 2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }  
    return true;  
}
