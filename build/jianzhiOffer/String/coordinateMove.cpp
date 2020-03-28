/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-27 19:44:24
 * @LastTime: 2020-03-27 20:15:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\coordinateMove.cpp
 * @Description: 坐标移动
 */
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

pair<int, int> coordinateMove(string str) {
    pair<int, int> point(0, 0);
    size_t found = str.find_first_of(';');
    //找到第一个;位置,失败返回npos
    int start = 0;
    while (found != string::npos) {
        string s1 = str.substr(start, found - start);
        start = found + 1;
        found = str.find_first_of(';', found + 1);
        if (s1.size() > 1 && s1.size() <= 3) {
            char direction = s1[0];
            int displacement = 0;
            int invalid = 0;
            for (int i = 1; i < s1.size(); i++) {
                if (s1[i] >= '0' && s1[i] <= '9') {
                    displacement = displacement * 10 + (s1[i] - '0');
                } else {
                    invalid = 1;
                    break;
                }
            }
            if (invalid == 0) {
                switch (direction) {
                    case 'A': {
                        point.first -= displacement;
                        break;
                    }
                    case 'D': {
                        point.first += displacement;
                        break;
                    }
                    case 'W': {
                        point.second += displacement;
                        break;
                    }
                    case 'S': {
                        point.second -= displacement;
                        break;
                    }
                }
            }
        }
    }
    return point;
}

int main() {
    string str = "A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    pair<int, int> res = coordinateMove(str);
    cout << "<" << res.first << "," << res.second << ">" << endl;
    return 0;
}