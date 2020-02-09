//寻找所在区间的左右下标
#include <iostream>
#include <vector>
using namespace std;

int searchLeft(vector<int> nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            if (mid == 0 || target > nums[mid - 1]) {
                return mid;
            } else {
                end = mid - 1;
            }
        } else if (target < nums[mid]) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}

int searchRight(vector<int> &nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                return mid;
            } else {
                begin = mid + 1;
            }
        } else if (target > nums[mid]) {
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res;
    res.push_back(searchLeft(nums, target));
    res.push_back(searchRight(nums, target));
    return res;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 2, 2, 3, 4, 5, 5};
    int target = 5;
    vector<int> res = searchRange(nums, target);
    cout << "< " << res[0] << "," << res[1] << " >" << endl;
    return 0;
}