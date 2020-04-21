/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-18 18:25:22
 * @LastTime: 2020-04-19 18:27:33
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\pascalTriangle.cpp
 * @Description:
 */
#include <bits\stdc++.h>// 自动对称填充数组
void symArr(vector<int> &nums) {
    if (nums.size() % 2 == 0) {
        int index = nums.size() / 2;
        for (int i = index; i < nums.size(); i++) {
            index--;
            nums[i] = nums[index];
        }
    } else {
        int index = nums.size() / 2;
        for (int i = index + 1; i < nums.size(); i++) {
            index--;
            nums[i] = nums[index];
        }
    }
}
using namespace std;
// 自动对称填充数组
void symArr(vector<int> &nums) {
    if (nums.size() % 2 == 0) {
        int index = nums.size() / 2;
        for (int i = index; i < nums.size(); i++) {
            index--;
            nums[i] = nums[index];
        }
    } else {
        int index = nums.size() / 2;
        for (int i = index + 1; i < nums.size(); i++) {
            index--;
            nums[i] = nums[index];
        }
    }
}

vector<vector<int>> pascalTriangle(int depth) {
    vector<vector<int>> res;
    for (int i = 0; i < depth; i++) {
        vector<int> temp(2 * (i + 1) - 1, 1);
        res.push_back(temp);
    }
    if (depth >= 3) {
        for (int i = 2; i < res.size(); i++) {
            res[i][1] = res[i-1][0]+res[i-1][1];
            for (int j = 2; j <=res[i].size()/2; j++) {
                res[i][j] = res[i-1][j-2]+res[i-1][j-1]+res[i-1][j];
            }
            symArr(res[i]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> res;
    res = pascalTriangle(5);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<< endl;
    }
    return 0;
}