// 组合数之和
//数组中存在重复元素，寻找各个元素之和等于目标数
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void generate(int i, vector<int> &nums, vector<int> &item,
              vector<vector<int>> &result, set<vector<int>> &resSet, int target,
              int sum);


vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> item;
    set<vector<int>> resSet;
    sort(candidates.begin(), candidates.end());
    result.push_back(item);
    generate(0,candidates,item,result,resSet,target,0);
    return result;
}

void generate(int i, vector<int> &nums, vector<int> &item,
              vector<vector<int>> &result, set<vector<int>> &resSet, int target,
              int sum) {
    if (i >= nums.size() || sum > target) {
        return;
    }
    sum += nums[i];
    item.push_back(nums[i]);
    if (sum == target && resSet.find(item) == resSet.end()) {
        result.push_back(item);
        resSet.insert(item);
    }
    generate(i + 1, nums, item, result, resSet, target, sum);
    sum -= nums[i];
    item.pop_back();
    generate(i + 1, nums, item, result, resSet, target, sum);
}

int main() {
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result;
    result = combinationSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
