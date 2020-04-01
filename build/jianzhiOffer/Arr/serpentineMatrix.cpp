/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-31 12:48:47
 * @LastTime: 2020-03-31 20:59:28
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\serpentineMatrix.cpp
 * @Description:  蛇形矩阵输出上三角矩阵
 */
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> constructArr(int num) {
    int temp = 1;
    vector<vector<int>> res(5, vector<int>(5, 0));
    for (int k = 0; k < res.size(); k++) {
        int i = k;
        int j = 0;
        while (temp <= num & i >= 0 && j <= k) {
            res[i][0j] = temp;
            temp++;
            i--;
            j++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> res=constructArr(15);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            if(res[i][j]!=0){
            cout << res[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}