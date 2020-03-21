/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-21 15:42:18
 * @LastTime: 2020-03-21 15:56:40
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\aAddb.cpp
 * @Description: //以回车 ctrl+z 回车结束输入
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a,b;
    vector<vector<int>> data;
    while(cin>>a>>b){
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        data.push_back(temp);
    }
    for(int i = 0;i<data.size();i++){
        cout<<data[i][0]+data[i][1]<<endl;
    }
    return 0;
}   