//查找插入元素的位置
//二分查找法
#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> &nums, int target) {
    int index = -1;
    int begin = 0;
    int end = nums.size() - 1;
    while (index == -1) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            index = mid;
        } else if (target < nums[mid]) {
            if (mid == 0 || target > nums[mid - 1]) {
                index = mid;
            } else {
                end = mid - 1;
            }
        } else {
            if (mid == nums.size() - 1 || target < nums[mid + 1]) {
                index = mid + 1;
            } else {
                begin = mid + 1;
            }
        }
    }
    return index;
}

int main(){
    vector<int> nums = {1,3,5,7,9};
    int target = 4;
    int res = searchInsert(nums,target);
    cout<<res<<endl;
    return 0;
}