/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-18 11:34:39
 * @LastTime: 2020-02-21 11:01:56
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\houseRobber.cpp
 * @Description: 相邻两个会触发警报
 */
#include <iostream>
#include <vector>
using namespace std;
int rob(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) {
        return nums[0];
    }
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    for (int i = 0; i < dp.size(); i++) {
        cout << dp[i] << " ";
    }
    cout<<endl;
    vector<int> numPull;
    for (int i = 0; i < dp.size(); i++) {
        if (i == 0) {
            numPull.push_back(nums[i]);
        }
        if (i == 1) {
            if (dp[i] == nums[i]) {
                numPull.pop_back();
                numPull.push_back(nums[i]);
            }
        }
        if (dp[i] == dp[i - 1] + nums[i]) {
            numPull.push_back(nums[i]);
        }
        if (dp[i] == dp[i - 1] - nums[i-1] +nums[i]) {
            numPull.pop_back();
            numPull.push_back(nums[i]);
        }
    }
    for (int i = 0; i < numPull.size(); i++) {
        cout << numPull[i] << " ";
    }
    cout << endl;
    return dp[nums.size() - 1];
}

int main() {
    vector<int> nums = {5, 2, 6, 3, 1, 7};
    int res = rob(nums);
    cout << "the max rob is : " << res << endl;
    return 0;
}