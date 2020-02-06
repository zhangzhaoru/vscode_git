//最长摇摆子序列
#include<iostream>
#include<vector>

using namespace std;

int wiggleMaxLength(vector<int> &nums){
    if(nums.size()<2)
        return nums.size();
    static const int Begin = 0;
    static const int Up = 1;
    static const int Down = 2;
    int State = Begin;
    int maxLenght = 1;
    for(int i=1;i<nums.size();i++){
        switch (State)
        {
        case Begin:
            if(nums[i]>nums[i-1]){
                State = Up;
                maxLenght++;
            }else if(nums[i]<nums[i-1]){
                State = Down;
                maxLenght++;
            }
            break;
        case Up:
            if(nums[i]<nums[i-1]){
                State = Down;
                maxLenght++;
            }
            break;
        case Down:
            if(nums[i]>nums[i-1]){
                State = Up;
                maxLenght++;
            }
            break;
        }
    }
    return maxLenght;
}

int main(){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    int res = wiggleMaxLength(nums);
    cout<<"The max length wiggle subsequence is : "<<res<<endl;
    system("pause");
    return 0;
}