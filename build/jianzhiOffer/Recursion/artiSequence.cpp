/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 19:04:42
 * @LastTime: 2020-03-17 19:54:30
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\recursion\artiSequence.cpp
 * @Description: 递归实现等差数列与等比数列和
 */
#include<iostream>
using namespace std;

int artiSequence(int n,int begin,int diff){
    if(n==1)
        return begin;
    else
    {
        return begin+artiSequence(n-1,begin+diff,diff);
    }
    
}

int geomeSequence(int n,int begin,int q){
    if(n==1)
        return begin;
    else{
        return begin+q*geomeSequence(n-1,begin,q);
    }
}

int main(){
    int begin = 2;
    int diff = 2;
    int n = 10;
    int q = 2;
    //cout<<artiSequence(n,begin,diff)<<endl;
    cout<<geomeSequence(3,begin,q)<<endl;
    return 0;
}
