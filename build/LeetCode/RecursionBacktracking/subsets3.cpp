//有重复元素求子集
#include <iostream>
#include <vector>
#include<set>
#include<algorithm>
using namespace std;
void generate(int i,vector<int>&nums,vector<int> &item,
vector<vector<int>> &result,set<vector<int>> &resSet);


vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> item;
    set<vector<int>> resSet;
    sort(nums.begin(),nums.end());
    result.push_back(item);
    generate(0,nums,item,result,resSet);
    return result;
}

void generate(int i,vector<int>&nums,vector<int> &item,
vector<vector<int>> &result,set<vector<int>> &resSet){
    if(i>=nums.size())
        return;
    item.push_back(nums[i]);
    if(resSet.find(item)==resSet.end()){
        resSet.insert(item);
        result.push_back(item);
    }
    generate(i+1,nums,item,result,resSet);
    item.pop_back();
    generate(i+1,nums,item,result,resSet);
}

int main(){
    vector<int> nums = {2,1,2,2};
    vector<vector<int>> result;
    result = subsets(nums);
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j];
        }
        cout<<endl;
    }
    cout<<result.size()<<endl;
    cout<<endl;
    system("pause");
    return 0;
}