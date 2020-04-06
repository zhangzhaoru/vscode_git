/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-05 21:40:16
 * @LastTime: 2020-04-06 09:41:35
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\beautifulName.cpp
 * @Description: ÿ���ַ�ӵ�С�Ư���ȡ�����������������Ư���̶�
 * �����ַ��������������Ӷ��������θ�Ȩ���
 */
#include <bits\stdc++.h>
using namespace std;

int mostWeight(string str) {
    vector<int> charCount(26, 0);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            charCount[str[i] - 'a']++;
        }
        if (str[i] >= 'A' && str[i] <= 'Z') {
            charCount[str[i] - 'A']++;
        }
    }
    sort(charCount.begin(), charCount.end());
    int w = 26;
    int res = 0;
    for (int i = 25; i >= 0; i--) {
        res += charCount[i] * w;
        w--;
    }
    return res;
}

int main() {
    string str = "zhangsan";
    int res = mostWeight(str);
    cout<<res<< endl;
    return 0;
}