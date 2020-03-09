/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-01-26 21:19:36
 * @LastTime: 2020-03-07 19:46:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\FindNumbersWithSum.cpp
 * @Description: 
 */
//在递增数组中寻找两个数使得和等于目标值，两个数的
#include<iostream>
#include<vector>

using namespace std;
//输出和最小的数对
vector<int> FindNumbersWithSum1(vector<int> array,int sum){
    vector<int> res;
    if(array.empty() || array.size()<=1)
        return res;
    int i = 0;
    int j = array.size()-1;
    while(i<j){
        if((array[i]+array[j])<sum){
            i++;
        }else if((array[i]+array[j])>sum){
            j--;
        }else{
            res.push_back(array[i]);
            res.push_back(array[j]);
            return res;
            
        }
    }
    return res;
 }

//输出乘积最大的数对
vector<int> FindNumbersWithSum2(vector<int> array,int sum){
    vector<int> res;
    if(array.empty() || array.size()<=1)
        return res;
    int i = 0;
    int j = array.size()-1;
    while(i<j){
        if((array[i]+array[j])<sum){
            i++;
        }else if((array[i]+array[j])>sum){
            j--;
        }else{
            res.push_back(array[i++]);
            res.push_back(array[j]);
        }
    }
    vector<int> res1(res.end()-2,res.end());
    return res1;
}
int main(){
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    int sum =11;
    vector<int> res = FindNumbersWithSum2(array,sum);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}