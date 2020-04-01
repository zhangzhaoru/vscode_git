/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-01 19:40:23
 * @LastTime: 2020-04-01 20:55:52
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Num\findSum.cpp
 * @Description: 数组中一个数为其他两个数之和
 */
#include<iostream>
#include<vector>
using namespace std;
bool twoSum(vector<int> nums,int target){
    vector<pair<int,int>> res;
    int i = 0;
    int j = nums.size()-1;
    while(i<j){
        int sum = nums[i]+nums[j];
        if(sum== target){
            return true;
            i++;
            j--;
        }
        else if(sum<target){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
}

bool findSum(vector<int> data){
    for(int i = 0;i<data.size();i++){
        vector<int> temp;
        for(int j = 0;j<data.size(); j++){
            if(j!=i){
                temp.push_back(data[j]);
            }
        }
        if(twoSum(temp,data[i])){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> data;
    int num;
    while(cin.get()!='\n'){
        cin>>num;
        data.push_back(num);
    }
    //以false&true 输出
    cout<<boolalpha<<findSum(data)<<endl;
    return 0;
}