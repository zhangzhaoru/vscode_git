/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 11:31:17
 * @LastTime: 2020-03-17 13:50:27
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\minNumberInRotateArray.cpp
 * @Description: 旋转数组寻找最小值
 */
#include <iostream>
#include <vector>
using namespace std;
static int min(vector<int> data) {
    if ( data.size() == 0)
        return -1;
    int left = 0;
    int right = data.size() - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        // left < right
        if (data[left] < data[right]) return data[left];
        // left > right
        else if (data[left] > data[right]) {
            if (data[mid] >= data[left])
                left = mid + 1;
            else
                right = mid;
        }
        // left = right
        else {
            if (data[left] < data[mid])
                left = mid + 1;
            else if (data[left] > data[mid])
                right = mid;
            else {
                left = left + 1;
                right = right - 1;
            }
        }
    }
    return data[right];
}

int main() {
    vector<int> data = {4,5,1,2,3};
    int res = min(data);
    cout<<res<< endl;
    return 0;
}