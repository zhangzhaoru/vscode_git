/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-19 11:48:00
 * @LastTime: 2020-03-19 17:08:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\printMatrix.cpp
 * @Description: 顺时针打印矩阵
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> printMatrix(vector<vector<int>> matrix) {
    // 存储结果
    vector<int> result;
    // 边界条件
    if (matrix.empty()) return result;
    // 二维矩阵行列
    int rows = matrix.size();
    int cols = matrix[0].size();
    // 圈的四个角标
    int left = 0;
    int right = cols - 1;
    int top = 0;
    int btm = rows - 1;
    // 循环打印圈
    while (left <= right && top <= btm) {  // 循环条件：
        // 圈的第一步
        for (int i = left; i <= right; ++i)    // 第一步循环条件
            result.push_back(matrix[top][i]);  // 第一步坐标
        // 圈的第二步
        if (top < btm)                               // 第二步边界条件
            for (int i = top + 1; i <= btm; ++i)     // 第二步循环条件
                result.push_back(matrix[i][right]);  // 第二步坐标
        // 圈的第三步
        if (top < btm && left < right)               // 第三步边界条件
            for (int i = right - 1; i >= left; --i)  // 第三步循环条件
                result.push_back(matrix[btm][i]);    // 第三步坐标
        // 圈的第四步
        if (top + 1 < btm && left < right)            // 第四步边界条件
            for (int i = btm - 1; i >= top + 1; --i)  // 第四步循环条件
                result.push_back(matrix[i][left]);    // 第四步坐标

        ++left;
        --right;
        ++top;
        --btm;
    }
    return result;
}

int main() {
    int arr[4][4] = {
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> data;
    for (int i = 0; i < 4; i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            temp.push_back(arr[i][j]);
            cout << arr[i][j] << " ";
        }
        cout << endl;
        data.push_back(temp);
    }
    vector<int> res = printMatrix(data);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i]<<" ";
    }
    cout << endl;
    return 0;
}