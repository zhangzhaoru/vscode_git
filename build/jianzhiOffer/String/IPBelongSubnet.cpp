/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-01 16:24:10
 * @LastTime: 2020-04-01 17:31:44
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\IPBelongSubnet.cpp
 * @Description: �ж�IP�Ƿ�����ͬһ����
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string dec2bin(string str) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num = num * 10 + str[i] - '0';
    }
    string res = "";
    while (num) {
        if (num % 2 == 0) {
            res += '0';
        } else {
            res += '1';
        }
        num /= 2;
    }
    while (res.length() < 8) {
        res += '0';
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<string> ExactIPAdress(string str) {
    str += '.';
    vector<string> res;
    int start = 0;
    size_t found = str.find_first_of('.');
    string temp;
    while (found != string::npos) {
        temp = str.substr(start, found - start);
        res.push_back(dec2bin(temp));
        start = found + 1;
        found = str.find_first_of('.', start);
    }
    return res;
}

// �������룬�����Ϊ 1��������Ϊ 0
vector<string> subNetMask() {
    string str1 = "11111111";
    string str2 = "00000000";
    vector<string> res;
    for (int i = 0; i < 3; i++) {
        res.push_back(str1);
    }
    res.push_back(str2);
    return res;
}

//ip��ַ��������������λ������
vector<string> andByBit(string ip) {
    vector<string> IPAdress = ExactIPAdress(ip);
    vector<string> mask = subNetMask();
    vector<string> res;
    string temp;
    for (int i = 0; i < IPAdress.size(); i++) {
        string str1 = IPAdress[i];
        string str2 = mask[i];
        for (int j = 0; j < str1.length(); j++) {
            temp += ((str1[j] - '0') & (str2[j] - '0')) + '0';
        }
        res.push_back(temp);
        temp.clear();
    }
    return res;
}

//�ж�����IP��ַ���������밴λ������Ƿ���ͬ
bool isSameSubNet(string ip1,string ip2){
    vector<string> Ip1 = andByBit(ip1);
    vector<string> Ip2 = andByBit(ip2);
    for(int i = 0;i<Ip1.size(); i++){
        if(Ip1[i]!=Ip2[i]){
            return false;
        }
    }
    return true;
}

int main() {
    string ip1 = "192.168.224.256";                                      
    string ip2 = "192.168.10.4";                                      
    if(isSameSubNet(ip1,ip2)){
        cout<<"Both IP addresses belong to the same subnet ! "<<endl;
    }else{
        cout<<"The two IP addresses belong to different subnets ! "<<endl;
    }
    return 0;
}