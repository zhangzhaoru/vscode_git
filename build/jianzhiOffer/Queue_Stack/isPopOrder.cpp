/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-20 13:37:29
 * @LastTime: 2020-03-20 13:57:44
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Queue_Stack\isPopOrder.cpp
 * @Description: 判断出栈序列是否合法
 */
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isPopOrder(vector<int> pushV,vector<int> popV){
    if(pushV.size()!=popV.size()){
        return false;
    }
    std::stack<int> temp;
    int j = 0;
    for(int i =0;i<popV.size(); i++){
        while(temp.size()== 0||temp.top()!=popV[i]){
            temp.push(pushV[j]);
            j++;
            if(j>pushV.size()){
                return false;
            }
        }
        temp.pop();
    }
    if(temp.empty()){
        return true;
    }else{
        return false;
    }
}

int main() {
    vector<int> pushV = {1,2,3,4,5};
    vector<int> popV = {5,4,3,2,1};
    bool res = isPopOrder(pushV,popV);
    if(res){
        cout<<"the pop series is valid ! "<<endl;
    }else{
        cout<<"the pop series is not valid ! "<<endl;
    }
    return 0;
}