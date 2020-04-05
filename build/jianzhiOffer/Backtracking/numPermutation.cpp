/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-04 12:57:16
 * @LastTime: 2020-04-04 17:52:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\numPermutation.cpp
 * @Description: ȫ���� vector����û��find����������algorithm��find����ʵ��
 */

#include <bits\stdc++.h>
using namespace std;

void backTrack(vector<int> nums, vector<vector<int>> &res, vector<int> path) {
    if (path.size() == nums.size()) {
        res.push_back(path);
    } else {
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it = find(path.begin(),path.end(),nums[i]);
            if(it==path.end()){
                path.push_back(nums[i]);
                backTrack(nums, res, path);
                path.pop_back();
                //���ݹ���
            } 
        }
    }
}

vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> res;
    vector<int> path;
    backTrack(nums,res,path);
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}