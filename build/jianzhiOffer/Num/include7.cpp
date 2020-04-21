/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-19 18:33:12
 * @LastTime: 2020-04-19 19:02:17
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\include7.cpp
 * @Description: 输出与7相关的所有数
 */
#include <bits\stdc++.h>
using namespace std;

bool isIncludeSeven(int num) {
    bool flag = false;
    if (num == 7) {
        return true;
    }
    while (num) {
        if (num % 10 == 7) {
            flag = true;
            break;
        }
        num /= 10;
    }
    return flag;
}

bool isSevenMultiple(int num) {
    if(num%7!=0){
        return false;
    }else{
        return true;
    }
}

vector<int> includeSeven(int num) {
    vector<int> res;
    for (int i = 1; i <= num; i++) {
        if ( isIncludeSeven(i)|| isSevenMultiple(i) ) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    int num = 30;
    vector<int> res;
    res = includeSeven(num);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}