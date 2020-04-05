/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-04 21:55:34
 * @LastTime: 2020-04-05 18:16:21
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\theSum.cpp
 * @Description: leetcode 39 给定一个数组candidate = [2, 3, 5]，寻找数
 * 组中数字加和为target的所有组合，且数组中元素可以重复使用。(回溯法)
 * leetcode 40 无重复使用元素其和等于target
 */
#include <bits\stdc++.h>
using namespace std;

//有重复
void backtracks1(vector<int> nums, int target, int index, vector<int> temp,
                vector<vector<int>> &res) {
    for (int i = index; i < nums.size(); i++) {
        if (target == 0) {
            res.push_back(temp);
            return;
        } else if (target < 0) {
            return;
        } else {
            temp.push_back(nums[i]);
            backtracks1(nums, target - nums[i], i, temp, res);
            temp.pop_back();
        }
    }
}

//无重复
void backtracks2(vector<int> nums, int target, int index, vector<int> temp,
                vector<vector<int>> &res) {
    for (int i = index; i < nums.size(); i++) {
        if (target == 0) {
            res.push_back(temp);
            return;
        } else if (target < 0) {
            return;
        } else {
            temp.push_back(nums[i]);
            backtracks2(nums, target - nums[i], i+1, temp, res);
            //遍历第i个元素从第i+1个元素区间开始搜索，去重
            temp.pop_back();
        }
    }
}

vector<vector<int>> theSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    // 搜索元素需要升序处理
    int index = 0;
    backtracks2(nums, target, index, temp, res);
    return res;
}

int main() {
    vector<int> nums = {2,3,6,7};
    int target = 8;
    vector<vector<int>> res = theSum(nums, target);
    for(int i = 0;i<res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}