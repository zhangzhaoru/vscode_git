/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 09:37:35
 * @LastTime: 2020-03-26 09:53:28
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\extractUnduNum.cpp
 * @Description: 提取不重复数字
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> extractUnreNum(vector<int> data) {
    map<int, int> temp;
    for (int i = 0; i < data.size(); i++) {
        temp[data[i]]++;
    }
    vector<int> res;
    map<int, int>::iterator iter = temp.begin();
    while (iter != temp.end()) {
        if ((iter)->second == 1) {
            res.push_back(iter->first);
        }
        iter++;
    }
    return res;
}

int main() {
    vector<int> data = {9,8,7,6,6,7,3};
    vector<int> res = extractUnreNum(data);
    for(int i = 0;i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<< endl;
    return 0;
}