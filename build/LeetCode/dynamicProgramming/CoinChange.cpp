/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-21 16:57:49
 * @LastTime: 2020-02-21 17:28:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\dynamicProgramming\CoinChange.cpp
 * @Description:找零钱dp[i]表示金额i的最优解
 */
#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount) {
    vector<int> dp;
    for (int i = 0; i <= amount; i++) {
        dp.push_back(-1);
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }
    return dp[amount];
}

int main() {
    int amount = 14;
    vector<int> coins = {1, 2, 5, 7, 10};
    int res = coinChange(coins, amount);
    cout << res << endl;
    return 0;
}