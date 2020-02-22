/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 19:27:15
 * @LastTime: 2020-02-21 19:47:56
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\longestIncreasingSubsequence.cpp
 * \vscode_git\build\LeetCode\dynamicProgramming\longestIncreasingSubsequence.cpp
 * \vscode_git\build\LeetCode\dynamicProgramming\longestIncreasingSubsequence.cpp
 * \vscode_git\build\LeetCode\dynamicProgramming\longestIncreasingSubsequence.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums) {
    if (nums.size() < 2)
     return nums.size();
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    int maxLen = 1;
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i]>maxLen){
            maxLen = dp[i];
        }

    }
    return maxLen;
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1, 4};
    int res = lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}