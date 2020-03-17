/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-16 19:53:13
 * @LastTime: 2020-03-16 20:02:01
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\temp.cpp
 * @Description: 
 */
#include<iostream>
#include<vector>
using namespace std;
bool Find(int target,vector<vector<int>> arr){
    int col = arr.size();
    int row = arr[0].size();
    int i = 0;
    int j = row-1;
    while(i<col && j>=0){
        if(arr[i][j]<target){
            i++;
        }
        else if(arr[i][j]>target){
            j--;
        }
        else if(arr[i][j]==target){
            return true;
        }
    }
    return false;
}