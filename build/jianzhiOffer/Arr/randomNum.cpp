/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 19:55:38
 * @LastTime: 2020-03-25 20:17:48
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\randomNum.cpp
 * @Description: 输入一组随机数，去重从小到大排序输出
 */
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define random(a,b) ((rand() % (b-a+1))+ a)
using namespace std;

vector<int> removeDuplicates(int n){
    vector<int> data;
    for(int i = 0;i<n;i++){
        data.push_back(random(1,1000));
    }
    set<int> mySet;
    for(int i = 0;i<data.size();i++){
        mySet.insert(data[i]);
    }
    set<int>::iterator iter = mySet.begin();
    vector<int> res;
    while(iter!=mySet.end()){
        res.push_back(*iter);
        iter++;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> res = removeDuplicates(10);
    for(int i = 0;i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}