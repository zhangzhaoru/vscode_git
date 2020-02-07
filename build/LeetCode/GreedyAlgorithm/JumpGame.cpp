//判断是否可以跳跃到数组的最后一个元素
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums) {
    vector<int> index;
    for (int i = 0; i < nums.size(); i++) {
        index.push_back(nums[i] + i);
    }
    int jump = 0;
    int maxLength = index[0];
    while (jump < maxLength && jump < nums.size()) {
        if (maxLength < index[jump]) {
            maxLength = index[jump];
        }
        jump++;
    }
    if (jump == nums.size()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    if (canJump(nums)) {
        cout << "Can jump the last position !" << endl;
    } else {
        cout << "Can't jump the last position !" << endl;
    }
    system("pause");
    return 0;
}