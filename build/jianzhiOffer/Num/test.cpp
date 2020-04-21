/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 20:12:48
 * @LastTime: 2020-03-30 20:13:40
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\test.cpp
 * @Description: 
 */
/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-30 19:32:13
 * @LastTime: 2020-03-30 20:11:02
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\integer2IPAdress.cpp
 * @Description: 整数与IP地址之间的相互转化
 */
#include<iostream>
#include<string>
#include<vector>
#include <cstddef>
#include<algorithm>
using namespace std;

//十进制转化为二进制字符串

vector<string> splitWords(string str){
    vector<string> res;
    str+='.';
    size_t found = str.find_first_of('.');
    int start = 0;
    string temp;
    while(found!=string::npos){
        temp = str.substr(start,found-start);
        res.push_back(temp);
        start = found+1;
        found = str.find_first_of('.');
    }
    return res;
}


int main() {
    string s = "10.0.3.193";
    vector<string> res = splitWords(s);
    for(int i = 0;i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<< endl;
    return 0;
}