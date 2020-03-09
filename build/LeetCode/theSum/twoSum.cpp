/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-07 18:59:36
 * @LastTime: 2020-03-07 19:09:34
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\LeetCode\theSum\twoSum.cpp
 * @Description: 
 */
#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> twoSum(vector<int> nums,int target){
    vector<pair<int,int>> res;
    int i = 0;
    int j = nums.size()-1;
    while(i<j){
        int sum = nums[i]+nums[j];
        if(sum== target){
            res.push_back(make_pair(nums[i],nums[j]));
            i++;
            j--;
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }

}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 10;
    vector<pair<int,int>> res = twoSum(nums,target);
    for(int i = 0;i<res.size(); i++){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
    return 0;
}