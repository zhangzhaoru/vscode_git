/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-19 11:48:00
 * @LastTime: 2020-03-19 17:08:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\printMatrix.cpp
 * @Description: ˳ʱ���ӡ����
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int> printMatrix(vector<vector<int>> matrix) {
    // �洢���
    vector<int> result;
    // �߽�����
    if (matrix.empty()) return result;
    // ��ά��������
    int rows = matrix.size();
    int cols = matrix[0].size();
    // Ȧ���ĸ��Ǳ�
    int left = 0;
    int right = cols - 1;
    int top = 0;
    int btm = rows - 1;
    // ѭ����ӡȦ
    while (left <= right && top <= btm) {  // ѭ��������
        // Ȧ�ĵ�һ��
        for (int i = left; i <= right; ++i)    // ��һ��ѭ������
            result.push_back(matrix[top][i]);  // ��һ������
        // Ȧ�ĵڶ���
        if (top < btm)                               // �ڶ����߽�����
            for (int i = top + 1; i <= btm; ++i)     // �ڶ���ѭ������
                result.push_back(matrix[i][right]);  // �ڶ�������
        // Ȧ�ĵ�����
        if (top < btm && left < right)               // �������߽�����
            for (int i = right - 1; i >= left; --i)  // ������ѭ������
                result.push_back(matrix[btm][i]);    // ����������
        // Ȧ�ĵ��Ĳ�
        if (top + 1 < btm && left < right)            // ���Ĳ��߽�����
            for (int i = btm - 1; i >= top + 1; --i)  // ���Ĳ�ѭ������
                result.push_back(matrix[i][left]);    // ���Ĳ�����

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