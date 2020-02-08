//位运算实现子集
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int allset = 1 << nums.size();
    // 2^n
    for (int i = 0; i < allset; i++) {
        vector<int> item;
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << j)) {
                item.push_back(nums[j]);
            }
        }
        result.push_back(item);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> item;
    vector<vector<int>> result;
    result = subsets(nums);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    cout << result.size() << endl;
    cout << endl;
    system("pause");
    return 0;
}