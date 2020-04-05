/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-05 21:07:03
 * @LastTime: 2020-04-05 21:28:24
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\subSet.cpp
 * @Description: leetCode 78 Çó×Ó¼¯
 */
#include<bits\stdc++.h>
using namespace std;

void backTrack(vector<vector<int>> &res,vector<int> temp,int index,vector<int> nums){
    res.push_back(temp);
    for(int i = index;i<nums.size(); i++){
        temp.push_back(nums[i]);
        backTrack(res,temp,i+1,nums);
        temp.pop_back();
    }
    return;
}

vector<vector<int>> subSet(vector<int> nums){
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    backTrack(res,temp,0,nums);
    return res;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subSet(nums);
    for(int i = 0;i<res.size(); i++){
        if(res[i].empty()){
            cout<<"[]"<< endl;
            continue;
        }
        for(int j = 0;j< res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        if(i!=res.size()-1)
            cout<< endl;
    }
    return 0;
}