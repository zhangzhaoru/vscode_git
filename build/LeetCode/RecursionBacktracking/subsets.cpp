//无重复元素集合求子集
#include <iostream>
#include <vector>
using namespace std;
void generate(int i,vector<int>&nums,vector<int> &item,
vector<vector<int>> &result);


vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> item;
    result.push_back(item);
    generate(0,nums,item,result);
    return result;
}

void generate(int i,vector<int>&nums,vector<int> &item,
vector<vector<int>> &result){
    if(i>=nums.size()){
        return;
    }
    item.push_back(nums[i]);
    result.push_back(item);
    generate(i+1,nums,item,result);
    item.pop_back();
    generate(i+1,nums,item,result);
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    vector<int> item;
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