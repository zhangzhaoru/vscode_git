/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-02 12:31:07
 * @LastTime: 2020-04-02 18:09:18
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\weightBalance.cpp
 * @Description:给定一组砝码，计算能称出的重量
 */
#include<bits/stdc++.h>
using namespace std;

int WeightBalance(vector<int> count,vector<int> weight){
    set<int> res = {0};
    set<int> temp = {0};
    for(int i = 0;i<weight.size(); i++){
        for(int j = 1;j<=count[i]; j++){
            for(auto it:temp)
                res.insert(j*weight[i]+it);
        }
        temp = res;
    }
    return res.size();
}

int main() {
    vector<int> weight = {1,2};
    vector<int> count = {2,1}; 
    int res = WeightBalance(count,weight);
    cout<<res<< endl;
    return 0;
}