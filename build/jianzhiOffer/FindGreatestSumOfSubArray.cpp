//输出数组的连续子数组的最大和，左端点及右端点的位置
#include<iostream>
#include<vector>

using namespace std;

vector<int> FindGreatestSumOfSubArray(vector<int> array) {
    int len = array.size();
    vector<int> res = {0,-1,-1};
    if(len==0)
        return res;
    if(len==1){
        res[0] = array[0];
        res[1] = 0;
        res[2] = 0;
        return res;
    }
    vector<int> dp,left,right;
    dp.push_back(array[0]);
    left.push_back(0);
    right.push_back(0);
    for(int i=1;i<array.size();i++){
        dp.push_back(max(dp[i-1]+array[i],array[i]));
        if(dp[i]==array[i]){
            left.push_back(i);
        }else{
            left.push_back(left[i-1]);
        }
        right.push_back(i);
        
    }
    int maxSum = array[0];
    int Left,Right;
    for(int i=1;i<array.size();i++){
        if(dp[i]>maxSum){    
            maxSum = dp[i];
            Left = left[i];
            Right = right[i];
        }
    }
    res[0] = maxSum;
    res[1] = Left;
    res[2] = Right;
    return res;
}

int main(){
    vector<int> array = {6,-3,-2,7,-15,1,2,2};
    vector<int> res = FindGreatestSumOfSubArray(array);
    cout<<"The max sum of subArr is : "<<res[0]<<endl;
    cout<<"The left index is : "<<res[1]<<endl;
    cout<<"The right index is : "<<res[2]<<endl;
    system("pause");
    return 0;
}