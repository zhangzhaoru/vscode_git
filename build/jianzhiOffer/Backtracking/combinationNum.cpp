/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-04 20:46:24
 * @LastTime: 2020-04-04 21:47:41
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\combinationNum.cpp
 * @Description: c(n,m)
 */
#include <bits\stdc++.h>
using namespace std;

int M = 3;
void backTrack(vector<int> nums, vector<vector<int>> &res, vector<int> path,
               int index,vector<int> flags) {
    if (index == M) {
        res.push_back(path);
    } else {
        for (int i = nums[index]-1; i < nums.size(); i++) {

            if (flags[i]==0) {
                path.push_back(nums[i]);
                flags[i] = 1;
                backTrack(nums, res, path, index + 1,flags);
                path.pop_back();
                //»ØËÝ¹ý³Ì
            }
        }
    }
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<int> flags(nums.size(),0);
    backTrack(nums, res, path, 0,flags);
    return res;
    // for(int i = 0;i<res.size(); i++){
    //     sort(res[i].begin(),res[i].end());
    // }
    // vector<vector<int>> temp;
    // for(int i = 0;i<res.size();i++){
    //     vector<vector<int>>::iterator it = find(temp.begin(),temp.end(),res[i]);
    //     if(it==temp.end()){
    //         temp.push_back(res[i]);
    //     }
    // }
    // return temp;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> res = permute(nums);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout<<res.size()<<endl;
    return 0;
}
