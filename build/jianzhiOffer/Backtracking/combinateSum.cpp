/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-05 18:20:27
 * @LastTime: 2020-04-05 20:13:40
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\combinateSum.cpp
 * @Description: leetcode 216 ����ܺͣ����� k���������Ϊ 1-9������
 */
#include<bits\stdc++.h>
using namespace std;

void Backtracking(vector<vector<int>> &res,vector<int> &temp,int k,int n,int index){
    if(temp.size()==k&&n== 0){
        res.push_back(temp);
        return;
    }
    for(int i = index;i<=9;i++){
        temp.push_back(i);
        Backtracking(res,temp,k,n-i,i+1);
        //������Χ��i+1��ʼ������
        temp.pop_back();
    }
}

vector<vector<int>> combineSum3(int k,int n){
    vector<vector<int>> res;
    if(n<3||n>45)
    //����2���������9����
        return res;
    vector<int> temp;
    Backtracking(res,temp,k,n,1);
    return res;
}

int main() {
    int k = 3;
    int n = 9;
    vector<vector<int>> res = combineSum3(k,n);
    for(int i = 0;i<res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<< endl;
    }
    return 0;
}