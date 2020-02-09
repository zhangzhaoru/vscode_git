//旋转数组查找
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            if (nums[begin] < nums[mid]) {
                if (target > nums[begin]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else if (nums[begin] > nums[mid]) {
                end = mid - 1;
            } else if (nums[begin] == nums[mid]) {
                begin = mid + 1;
            }
        } else {
            if (nums[begin] < nums[mid]) {
                begin = mid + 1;
            } else if (nums[begin] > nums[mid]) {
                if (target >= nums[begin]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else if (nums[begin] == nums[mid]) {
                begin = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,8,9,1,2,3};
    int target = 8;
    int index = search(nums,target);
    cout<<index<<endl;
    return 0;
}