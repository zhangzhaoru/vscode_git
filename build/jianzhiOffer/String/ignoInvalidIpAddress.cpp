/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-27 20:17:08
 * @LastTime: 2020-03-27 21:22:26
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\ignoInvalidIpAddress.cpp
 * @Description: 识别有效的IP地址并进行分类统计
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int string2int1(string str) {
    stringstream ss;
    ss << str;
    int x;
    ss >> x;
    return x;
}

int string2int2(string str) {
    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

vector<int> ip2Vec(string str) {
    str += '.';
    vector<int> res;
    string temp;
    int num = 0;
    int start = 0;
    size_t found = str.find_first_of('.');
    while (found != string::npos) {
        temp = str.substr(start, found - start);
        start = found + 1;
        found = str.find_first_of('.', start);
        res.push_back(string2int1(temp));
    }
    return res;
}

bool maskIsValid(vector<int> res) {
    if (res.size() != 4) {
        return false;
    }
    if (res[0] == 255) {
        if (res[1] == 255) {
            if (res[2] == 255) {
                if (res[3] == 254 || res[3] == 252 || res[3] == 248 ||
                    res[3] == 240 || res[3] == 224 || res[3] == 192 ||
                    res[3] == 128 || res[3] == 0) {
                    return true;
                } else {
                    return false;
                }
            } else {
                if (res[2] == 254 || res[2] == 252 || res[2] == 248 ||
                    res[2] == 240 || res[2] == 224 || res[2] == 192 ||
                    res[2] == 128 || res[2] == 0) {
                    if (res[3] == 0) {
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        } else {
            if (res[1] == 254 || res[1] == 252 || res[1] == 248 ||
                res[1] == 240 || res[1] == 224 || res[1] == 192 ||
                res[1] == 128 || res[1] == 0) {
                if (res[3] == 0 && res[2] == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    } else {
        if (res[0] == 254 || res[0] == 252 || res[0] == 248 || res[0] == 240 ||
            res[0] == 224 || res[0] == 192 || res[0] == 128) {
            if (res[3] == 0 && res[2] == 0 && res[1] == 0) {
                return true;
            }
        } else {
            return false;
        }
    }
    return false;
}

vector<int> classifyIP(vector<string> strArr) {
    vector<int> res(7, 0);
    string str;
    for (int i = 0; i < strArr.size(); i++) {
        str = strArr[i];
        string ipString;
        string maskString;
        int j = 0;
        for (; str[j] != '~'; j++) {
            ipString.push_back(str[j]);
        }
        j++;
        for (; j < str.length(); j++) {
            maskString.push_back(str[j]);
        }
        vector<int> ip, mask;
        ip = ip2Vec(ipString);
        mask = ip2Vec(maskString);
        if (maskIsValid(mask)) {
            if (ip[1] >= 0 && ip[1] <= 255 && ip[2] >= 0 && ip[2] <= 255 &&
                ip[3] >= 0 && ip[3] <= 255) {
                if (ip[0] >= 1 && ip[0] <= 126) {
                    res[0]++;
                    if (ip[0] == 10) res[6]++;
                } else if (ip[0] >= 128 && ip[0] <= 191) {
                    res[1]++;
                    if (ip[0] == 172 && ip[1] >= 16 && ip[1] <= 32) res[6]++;
                } else if (ip[0] >= 192 && ip[0] <= 223) {
                    res[2]++;
                    if (ip[0] == 192 && ip[1] == 168) res[6]++;
                } else if (ip[0] >= 224 && ip[0] <= 239) {
                    res[3]++;
                } else if (ip[0] >= 240 && ip[0] <= 255) {
                    res[4]++;
                }
            }
        } else {
            res[5]++;
        }
    }
    return res;
}

int main() {
    vector<string> strArr = {
        "10.70.44.68~255.254.255.0",
        "1.0.0.1~255.0.0.0",
        "192.168.0.2~255.255.255.0",
        "19..0.~255.255.255.0"
    };
    vector<int> res = classifyIP(strArr);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
