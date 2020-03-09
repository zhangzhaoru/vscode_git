/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-08 14:53:25
 * @LastTime: 2020-03-08 15:45:42
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \build\CProgram\test.cpp
 * @Description:
 */
#include <stdlib.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
vector<const char *> raw{"132", "465", "798", "174", "285", "396",
                         "195", "375", "312", "645", "978", "714",
                         "825", "936", "915", "735"};
string num{"123456789"};
unsigned int valid_count = 0;
int main() {
    auto s = chrono::system_clock::now();
    vector<bool> com;
    map<string, char> imp;
    for (const auto &ele : raw) {
        string str{ele};
        imp[str.substr(0, 2)] = str[2];
    }
    for (auto i = 4; i < 10; ++i) {
        com.resize(9, false);
        for (auto iter = com.end() - i; iter != com.end(); ++iter) *iter = true;
        do {
            string per;
            for (auto j = 0; j < 9; ++j)
                if (com[j]) per.push_back(num[j]);
            do {
                bool valid = true;
                for (auto iter = imp.begin(); iter != imp.end(); ++iter) {
                    auto pos = per.find(iter->first);
                    if (pos != string::npos &&
                        per.substr(0, pos).find(iter->second) == string::npos) {
                        valid = false;
                        break;
                    }
                }
                if (valid) ++valid_count;
            } while (next_permutation(per.begin(), per.end()));
        } while (next_permutation(com.begin(), com.end()));
    }
    cout << valid_count << endl;
    auto e = chrono::system_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(e - s).count() << endl;
    system("pause");
}
