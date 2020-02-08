//火柴棍摆正方形
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool generate(int i,vector<int> &nums,int target,int backet[]);

bool makesquare(vector<int> &nums){
    if(nums.size()<4)
        return false;
    int sum = 0;
    for(int i = 0;i<nums.size();i++){
        sum+=nums[i];
    }
    if(sum%4!=0){
        return false;
    }
    sort(nums.rbegin(),nums.rend());
    int backet[4] = {0};
    return generate(0,nums,sum/4,backet);
}

bool generate(int i,vector<int> &nums,int target,int backet[]){
    if(i>=nums.size()){
        bool condition1 = backet[0] == target;
        bool condition2 = backet[1] == target;
        bool condition3 = backet[2] == target;
        bool condition4 = backet[3] == target;
        return condition1&&condition2&&condition3&&condition4;
    }
    for(int j = 0;j<4;j++){
        if(backet[j]+nums[i]>target){
            continue;
        }
        backet[j]+=nums[i];
        if(generate(i+1,nums,target,backet)){
            return true;
        }
        backet[j]-=nums[i];
    }
    return false;
}

int main(){
    vector<int> nums = {1,1,2,4,3,2,3};
    if(makesquare(nums)){
        cout<<"the arr can construct the squres! "<<endl;
    }else{
        cout<<"the arr can't construct the squres! "<<endl;
    }
    return 0;
}
