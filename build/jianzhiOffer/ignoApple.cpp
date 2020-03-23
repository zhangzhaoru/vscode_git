/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-23 11:39:19
 * @LastTime: 2020-03-23 12:05:10
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\ignoApple.cpp
 * @Description: 识别字符串中“apple”出现的个数,一个用户只能记录一次
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitWord(string str) {
    stringstream temp(str);
    string ss;
    vector<string> res;
    while (temp >> ss) {
        res.push_back(ss);
    }
    return res;
}

int countApple(vector<string> sArr) {
    int count = 0;
    for (int i = 0; i < sArr.size(); i++) {
        string tempStr = sArr[i];
        vector<string> temp = splitWord(tempStr);
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == "apple") {
                count++;
                break;
            }
        }
    }
    return count;
}

int main() {
    vector<string> sArr = {"apple orange banana pear", "orange banana pear",
                           "apple banana pear apple", "apple orange banana"};
    int count = countApple(sArr);
    cout << count << endl;
    return 0;
}