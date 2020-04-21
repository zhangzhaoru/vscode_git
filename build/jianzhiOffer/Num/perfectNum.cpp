/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-19 19:05:28
 * @LastTime: 2020-04-19 19:44:13
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\perfectNum.cpp
 * @Description: 完全数
 */
#include <bits\stdc++.h>
using namespace std;

// 输出数字num的所有约数
vector<int> divisorNum(int num) {
    vector<int> res;
    res.push_back(1);
    for(int i = 2;i<=num;i++){
        if(num%i== 0){
            res.push_back(i);
        }
    }
    return res;
}

// 判断数字是完美数
bool isPerfectNum(int num){
    vector<int> Num = divisorNum(num);
    int sum = 0;
    for(int i = 0;i<Num.size()-1; i++){
        sum+=Num[i];
    }
    if(sum==num){
        return true;
    }else{
        return false; 
    }
}

vector<int> countPerfect(int num){
    vector<int> res;
    for(int i = 1;i<=num;i++){
        if(isPerfectNum(i)){
            res.push_back(i);
        }
    }
    return res;
}
int main() {
    int num = 1000;
    vector<int> res ;
    res = countPerfect(num);
    for(int i = 0; i < res.size(); i++){
        cout<<res[i]<< " ";
    }
    cout<<endl;
    return 0;
}