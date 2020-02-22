

/*  * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 19:49:03
 * @LastTime: 2020-02-21 20:06:07
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\MinimumPathSum.cpp
 * @Description: 最小路径和(每次只能向下或者向右移动) */

#include <iostream>
#include <vector>
using namespace std;

int minimumPathSum(vector<vector<int>> &grid){
    if(grid.size()==0)
        return 0;
    int row =grid.size();
    int col =grid[0].size();
    vector<vector<int>> dp(row,vector<int>(col,0));
    dp[0][0]  = grid[0][0];
    for(int i = 1;i<col;i++){
        dp[0][i] = grid[0][i];
    }
    for(int i = 1;i<row;i++){
        dp[0][i] = dp[0][i-1]+grid[0][i];
    }
    for(int i = 1;i<row;i++){
        dp[i][0] =dp[i-1][0]+grid[i][0];
        for(int j = 1;j<col;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
    }
    return dp[row-1][col-1];
}

int main() {
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int res =minimumPathSum(grid);
    cout<<"the minimum path sum is : "<<res<<endl;
    return 0;
}
