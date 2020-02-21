/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 16:41:28
 * @LastTime: 2020-02-21 16:50:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\maxSubArray.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int maxRes = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        if (maxRes < dp[i]) {
            maxRes = dp[i];
        }
    }
    return maxRes;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = maxSubArray(nums);
    cout << res << endl;
    return 0;
}
