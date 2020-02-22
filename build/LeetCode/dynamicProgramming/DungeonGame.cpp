/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 20:08:23
 * @LastTime: 2020-02-22 20:40:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\DungeonGame.cpp
 * @Description:从右下向左上递推 dp[i][j]至少需要血量
 */
#include <iostream>
#include <vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>> &dungeon) {
    if (dungeon.size() == 0) {
        return 0;
    }
    int row = dungeon.size();
    int col = dungeon[0].size();
vector<vector<int>> dp(row, vector<int>(col, 0));   
    dp[row - 1][col - 1] = max(1, 1 - dungeon[row - 1][col - 1]);
    for (int i = col - 2; i >= 0; i--) {
        dp[row - 1][i] = max(1, dp[row - 1][i + 1] - dungeon[row - 1][i]);
    }
    for (int i = row - 2; i >= 0; i--) {
        dp[i][col - 1] = max(1, dp[i + 1][col - 1] - dungeon[i][col - 1]);
    }
    for (int i = row - 2; i >= 0; i--) {
        for (int j = col - 2; i >= 0; i--) {
            int dpMin = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, dpMin - dungeon[i][j]);
        }
    }
    return dp[0][0];
}

int main() {
    vector<vector<int>> dungeon = {{-2 - 3, 3}, {-5, -10, 1}, {10, 30, -5}};
    int res = calculateMinimumHP(dungeon);
    cout << "the minimum HP is : " << res << endl;
    return 0;
}
