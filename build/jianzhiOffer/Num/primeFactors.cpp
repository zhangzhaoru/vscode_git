/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 22:32:34
 * @LastTime: 2020-03-25 22:40:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\primeFactors.cpp
 * @Description:  输出整数的所有质数因子
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> primeFactor(int num){
    vector<int> res;
    for(int i = 2;i<=num;){
        if(num%i== 0){
            res.push_back(i);
            num/=i;
        }else{
            i++;
        }
    }
    return res;
}

int main() {
    int num =180;
    vector<int> res = primeFactor(num);
    for(int i = 0;i<res.size(); i++){
        cout<< res[i]<<" ";
    }
    cout<< endl;
    return 0;
}
