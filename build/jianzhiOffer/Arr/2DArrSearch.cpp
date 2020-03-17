/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 09:33:37
 * @LastTime: 2020-03-17 09:44:55
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\2DArrSearch.cpp
 * @Description:
 */
#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int>> array) {
    int hang = array.size();
    int lie = array[0].size();
    int i = 0;
    int j = lie - 1;
    while (i < hang && j >= 0) {
        if (array[i][j] == target) {
            return true;
        } else if (array[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    return false;
}

int main() {
    int Arr[][3] = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> arr ;
    for(int i = 0;i<3;i++){
        vector<int> temp;
        for(int j = 0;j<3;j++){
            temp.push_back(Arr[i][j]);
        }
        arr.push_back(temp);
    }
    int target = 8;
    bool res = Find(target,arr);
    if(res){
        cout<<"The target has Find ! "<<endl;
    }else{
        cout<<"The target has not Find ! "<<endl;
    }
    return 0;
}