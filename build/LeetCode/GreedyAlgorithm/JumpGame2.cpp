//求最少需要几次跳动
#include <iostream>
#include <vector>
using namespace std;

int jump(vector<int> &nums) {
    if (nums.size() < 2) return 0;
    int jumpMin = 1;
    int curMaxIndex = nums[0];
    int preMaxIndex = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (i > curMaxIndex) {
            jumpMin++;
            curMaxIndex = preMaxIndex;
        }
        if (preMaxIndex < i + nums[i]) {
            preMaxIndex = i + nums[i];
        }
    }
    return jumpMin;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    int res = jumpe(nums);
    cout << "The min jumpMin count is : ";
    cout << res << endl;
    system("pause");
    return 0;
}