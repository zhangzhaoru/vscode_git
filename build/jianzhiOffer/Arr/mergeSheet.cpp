/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 23:09:37
 * @LastTime: 2020-03-25 23:49:46
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Arr\mergeSheet.cpp
 * @Description: 合并记录表
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void mergeSheet(vector<pair<int, int>> sheet) {
    map<int, int> temp;
    for (int i = 0; i < sheet.size(); i++) {
        if (temp.empty()) {
            temp.insert(sheet[i]);
        } else {
            map<int, int>::iterator iter = temp.find(sheet[i].first);
            if (iter == temp.end()) {
                temp.insert(sheet[i]);
            } else {
                iter->second += sheet[i].second;
            }
        }
    }
    map<int, int>::iterator iter1;
    for (iter1 = temp.begin(); iter1 != temp.end(); iter1++) {
        cout << iter1->first << " " << iter1->second << endl;
    }
}

int main() {
    vector<int> key = {0, 0, 1, 3};
    vector<int> value = {1, 2, 2, 4};
    vector<pair<int, int>> sheet;
    for (int i = 0; i < key.size(); i++) {
        sheet.push_back(make_pair(key[i], value[i]));
    }
    for (int i = 0; i < sheet.size(); i++) {
        cout << sheet[i].first << " " << sheet[i].second << endl;
    }
    cout << "----------------merge-----------------" << endl;
    mergeSheet(sheet);
    return 0;
}
