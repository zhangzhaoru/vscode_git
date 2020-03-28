/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-27 21:26:44
 * @LastTime: 2020-03-28 01:31:14
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\errorLogging.cpp
 * @Description: 文件记录表,循环覆盖过程中因为map按照红黑树排序，引入name记录插入顺序
 */
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int string2Int(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}

//提取文件名与所在行号，中间由多个空格分隔
string exactFileName(string str, int &lines) {
    vector<string> temp;
    size_t found1 = str.find_first_of(' ');
    size_t found2 = str.find_last_of(' ');
    int start = 0;
    temp.push_back(str.substr(start, found1 - start));
    temp.push_back(str.substr(found2 + 1));
    string str1 = temp[0];
    lines = string2Int(temp[1]);
    size_t found3 = str1.find_last_of('\\');
    string fileName = str1.substr(found3 + 1);
    return fileName;
}

string limitNameLength(string str, int len) {
    size_t found = str.find_last_of('.');
    int start = 0;
    string name = str.substr(start, found - start);
    string suffix = str.substr(found + 1);
    if (name.length() > len) {
        name = name.substr(str.length() - len - 2);
    }
    string res = "";
    res += name;
    res += '.';
    res += suffix;
    return res;
}

void errorLogging(vector<string> strArr) {
    map<string, vector<int>> logging;
    vector<string> name;
    int limitRow = 3;
    //记录表最大长度
    int item = 0;
    for (int i = 0; i < strArr.size(); i++) {
        int lines = 0;
        string fileName = exactFileName(strArr[i], lines);
        fileName = limitNameLength(fileName, 3);
        int count = 1;
        if (logging.empty()) {
            logging.insert(
                pair<string, vector<int>>(fileName, vector<int>{count, lines}));
                name.push_back(fileName);
                item++;
        } else if (logging.find(fileName) == logging.end()) {
            if(item<limitRow){
                logging.insert(
                pair<string, vector<int>>(fileName, vector<int>{count, lines}));
                name.push_back(fileName);
                item++;
            }else{         
                logging.erase(logging.find(name[0]));
                name.erase(name.begin());
                logging.insert(
                pair<string, vector<int>>(fileName, vector<int>{count, lines}));
                name.push_back(fileName);
            }    
        } else if (logging.find(fileName) != logging.end()) {
            logging.find(fileName)->second[0]++;
            logging.find(fileName)->second.push_back(lines);
            //更新行号
        }
    }
    map<string, vector<int>>::iterator iter;
    for(int i = 0;i<name.size(); i++){
        iter = logging.find(name[i]);
        cout << iter->first << " ";
        cout << "count : " << iter->second[0] << " ";
        cout << "lines : ";
        for (int i = 1; i < iter->second.size(); i++) {
            cout << iter->second[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<string> strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325"};
                             
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326"};
                             
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326",
              "E:\\V1R2\\product\\fpgadrive.c   1327"};
                             
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326",
              "E:\\V1R2\\product\\fpgadrive.c   1327",
              "E:\\V1R2\\product\\abc.c   1111"};
                             
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326",
              "E:\\V1R2\\product\\fpgadrive.c   1327",
              "E:\\V1R2\\product\\abc.c   1111",
              "E:\\V1R2\\product\\w3wwedq.c   121"};                          
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326",
              "E:\\V1R2\\product\\fpgadrive.c   1327",
              "E:\\V1R2\\product\\abc.c   1111",
              "E:\\V1R2\\product\\w3wwedq.c   121",
              "E:\\V1R2\\product\\fpgadrive.c   1328"};                          
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
              "E:\\V1R2\\product\\fpgadrive.c   1326",
              "E:\\V1R2\\product\\fpgadrive.c   1327",
              "E:\\V1R2\\product\\abc.c   1111",
              "E:\\V1R2\\product\\w3wwedq.c   121",
              "E:\\V1R2\\product\\fpgadrive.c   1328",
              "E:\\V1R2\\product\\aasdac.c   111"};                          
    errorLogging(strArr);
    cout<<endl;
    strArr = {"E:\\V1R2\\product\\fpgadrive.c   1325",
                             "E:\\V1R2\\product\\fpgadrive.c   1326",
                             "E:\\V1R2\\product\\fpgadrive.c   1327",
                             "E:\\V1R2\\product\\abc.c   1111",
                             "E:\\V1R2\\product\\w3wwedq.c   121",
                             "E:\\V1R2\\product\\fpgadrive.c   1328",
                             "E:\\V1R2\\product\\aasdac.c   111",
                             "E:\\V1R2\\product\\fpgadrive.c   1329"};                            
    errorLogging(strArr);
    return 0;
}