//回溯法常见算法
// 0-1背包问题
//状态转移方程f[i][v]=max{ f[i-1][v],f[i-1][v-w[i]]+val[i] }
#include <iostream>
#include <vector>
using namespace std;
// *@param m : An integer m denotes the size of a backpack
// *@param A : Given n items with size A[i]
// *@ return : The maximum size
// f[j]剩余空间为j时的最大价值
int backPack(int m, vector<int> W, vector<int> V) {
    int k = W.size();
    vector<int> f(m + 1, 0);

    for (int i = 0; i < k; i++) {
        for (int j = m; j >= W[i]; j--) {
            f[j] = max(f[j], f[j - W[i]] + V[i]);
        }
    }
    return f[m];
}

int main() {
    vector<int> W = {5, 4, 3, 2, 1};
    vector<int> V = {1, 2, 3, 4, 5};
    int m = 11;
    int res = backPack(m, W, V);
    cout << "the max tatol value is : " << res << endl;
    system("pause");
    return 0;
}
