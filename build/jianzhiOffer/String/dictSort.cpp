/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-26 11:29:29
 * @LastTime: 2020-03-26 12:49:21
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\dictSort.cpp
 * @Description: �����ַ��������ֵ�����
 */
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// strcmp ��������Ϊchar * ʹ��c_str��stringת��Ϊconst char *
void dictSort(vector<string> strArr) {
    for (int i = 0; i < strArr.size()-1; i++) {
        for (int j = 0; j < strArr.size() - i-1; j++) {
            if (strcmp(strArr[j].c_str(), strArr[j + 1].c_str()) > 0) {
                string temp = strArr[j];
                strArr[j] = strArr[j + 1];
                strArr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < strArr.size(); i++) {
        cout << strArr[i] << endl;
    }
}

int main() {
    vector<string> strArr = {"cap", "to", "cat",  "card", "two",
                             "too",  "up", "boat", "boot"};
    for (int i = 0; i < strArr.size(); i++) {
        cout << strArr[i] << endl;
    }
    cout << "----------------Sort--------------" << endl;
    dictSort(strArr);
    return 0;
}