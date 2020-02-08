//多重背包问题
#include<iostream>
#include<vector>
using namespace std;

int backPack(int T,vector<int> W,vector<int> V,vector<int> cot){
    int f[T+1] = {0};
    for(int i = 0;i<W.size();i++){
        for(int k = 1;k<=cot[i];k++){
            for(int j = T;j>=W[i];j--){
                f[j] = max(f[j],f[j-W[i]]+V[i]);
            }
        }
    }
    return f[T];
}

int main(){
    vector<int> W = {5,4,3,2,1};
    vector<int> V = {1,2,3,4,5};
    vector<int> cot = {1,2,1,2,1};
    int m = 10;
    int res = backPack(m,W,V,cot);
    cout<<"the max tatol value is : "<<res<<endl;
    system("pause");
    return 0;
}
