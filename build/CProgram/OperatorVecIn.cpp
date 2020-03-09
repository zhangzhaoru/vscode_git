/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-12 18:26:38
 * @LastTime: 2020-03-07 18:16:26
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\OperatorVecIn.cpp
 * @Description: 
 */
//容器输入输出重载
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

istream &operator>>(istream &input, vector<int> &v) {
    string s;
    getline(input, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return input;
}

ostream &operator<<(ostream &output, vector<int> &v) {
    for (auto i = v.begin(); i < v.end(); i++) {
        output << *i;
        if (i < v.end() - 1) {
            output << " ";
        }
    }
    return output;
}

void inputArr(vector<vector<int>> &data, int col) {
    for (int i = 0; i <= col; i++) {
        vector<int> temp;
        cin >> temp;
        data.push_back(temp);
    }
}

void outputArr(vector<vector<int>> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i];
        cout<<endl;
    }
}

int main() {
    int col;
    cout << "Please input the col : ";
    cin >> col;
    vector<vector<int>> data;
    inputArr(data, col);
    outputArr(data);
    system("pause");
    return 0;
}
