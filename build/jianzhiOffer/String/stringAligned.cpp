/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-25 20:18:16
 * @LastTime: 2020-03-25 20:50:42
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\stringAligned.cpp
 * @Description: 字符串每8个字符进行分隔，剩余字符对齐处理
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitAligned(vector<string> strArr) {
    vector<string> res;
    for (int i = 0; i < strArr.size(); i++) {
        if (strArr[i] == "") {
            continue;
        } else if (strArr[i].length() <= 8) {
            string temp = strArr[i];
            while (temp.length() < 8) {
                temp += '0';
            }
            res.push_back(temp);
        } else if (strArr[i].length() > 8){
            string temp1 = strArr[i].substr(0, 8);
            string temp2 = strArr[i].substr(8);
            res.push_back(temp1);
            while(temp2.length() > 8){
                temp1 = temp2.substr(0,8);
                temp2 = temp2.substr(8);
                res.push_back(temp1);
            }
            if (temp2.length() < 8) {
                while (temp2.length() < 8) {
                    temp2 += '0';
                }
                res.push_back(temp2);
            }
        }
    }
    return res;
}

int main() {
    vector<string> strArr = {"","abc", "123456789123456789"};
    vector<string> res = splitAligned(strArr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
