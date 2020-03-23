/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-23 11:19:13
 * @LastTime: 2020-03-23 11:31:18
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\MergeArr.cpp
 * @Description: 合并去重,并集去除交集
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int> mergeArr(vector<int> Arr1,vector<int> Arr2){
    set<int> temp;
    for(int i = 0;i<Arr1.size(); i++){
        temp.insert(Arr1[i]);
    }
    for(int i = 0;i<Arr2.size(); i++){
        if(temp.find(Arr2[i])==temp.end()){
            temp.insert(Arr2[i]);
        }else{
            temp.erase(temp.find(Arr2[i]));
        }
    }
    vector<int> res;
    set<int>::iterator iter = temp.begin();
    while(iter!=temp.end()){
        res.push_back(*iter);
        iter++;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> Arr1 = {1,2,3,4,5,6};
    vector<int> Arr2 = {5,6,7,8,9};
    vector<int> res = mergeArr(Arr1,Arr2);
    for(int i = 0;i<res.size(); i++){
        cout<< res[i]<<" ";
    }
    cout<<endl;
    return 0;
}