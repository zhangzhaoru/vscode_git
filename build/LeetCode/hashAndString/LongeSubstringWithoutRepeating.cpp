/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-16 19:09:24
 * @LastTime: 2020-02-16 19:09:24
 * @LastAuthor: Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\LongeSubstringWithoutRepeating.cpp
 * @Description: 字符串无重复字符的最长子串
 */
#include<iostream>
#include<vector>
using namespace std;
int lengthOfLongestSubstring(vector<int> &nums){
    if(nums.size()==0)
        return 0;
    vector<int> dp(nums.size(),0);
    dp[0] = 1;
    int maxLen =1;
    for(int i = 1;i<nums.size();i++){
        dp[i] = 1;
        for(int j = 0;j<i;j++){
            if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
                dp[i] = dp[j] + 1;
            }
        }
        if(maxLen<dp[i]){
            maxLen = dp[i];
        }
    }
    return maxLen;
}

int main(){
    vector<int> nums = {1,3,2,3,1,4};
    int maxLen = lengthOfLongestSubstring(nums);
    cout<<"the length of longest susbstring is : "<<maxLen<<endl;
    return 0;
}