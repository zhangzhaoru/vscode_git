//完全背包问题
//各种数量无限，实现背包内物品价值最大
//状态转移方程：  f[ i ][ v ] = max{ f[ i-1 ][ v-k*w[i] ] + k*val[ i ]  |
// 0 <= k*w[i] <=  v}
#include<iostream>
#include<vector>
using namespace std;
int backPack(int T,vector<int> W,vector<int> V){
    int f[T+1] = {0};
    for(int i = 0;i<W.size();i++){
        for(int j = W[i];j<=T;j++){
            f[j] = max(f[j],f[j-W[i]]+V[i]);
        }
    }
    return f[T];
}

int main(){
    vector<int> W = {5,4,3,2,1};
    vector<int> V = {1,2,3,4,5};
    int m = 10;
    int res = backPack(m,W,V);
    cout<<"the max tatol value is : "<<res<<endl;
    system("pause");
    return 0;
}
