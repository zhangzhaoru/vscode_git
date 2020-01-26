//输出所有和为S的连续正数序列
//设置双指针，当总和小于sum,大指针右移
//否则小指针右移
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>  FindContinuousSequence(int sum){
    vector<vector<int>> res;
    int left = 1;
    int right = 2;
    while(left<right){
        int cur = (left+right)*(right-left+1)/2;
        if(cur<sum){
            right++;
        }else if(cur>sum){
            left++;
        }else{
            vector<int> temp;
            for(int i = left;i<=right;i++){
                temp.push_back(i);
            }
            res.push_back(temp);
            left++;
        }
    }
     return res;
}

int main(){
    int sum = 100;
    vector<vector<int>> res;
    res = FindContinuousSequence(sum);
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    system("pause");
    return 0;
}