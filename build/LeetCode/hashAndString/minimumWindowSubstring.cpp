/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-17 22:06:07
 * @LastTime: 2020-02-20 22:54:05
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\hashAndString\minimumWindowSubstring.cpp
 * @Description: 最小窗口子串
 */
#include<iostream>
#include<string>
#include<vector>
#define maxN 128
using namespace std;

/**
 * @Name: isComtain
 * @Param: vec将字符串t中出现的字符保存在vec中
 * @Return:
 * @Description: 判断字符串s是否包含字符串t
 */
bool isComtain(int mapS[],int mapT[],vector<int> &vec){
    for(int i =0;i<vec.size();i++){
        if(mapS[vec[i]]<mapT[vec[i]]){
            return false;
        }
    }
    return true;
}

string minimumWindowSubstring(string &s,string &t){
    int mapS[maxN] = {0};
    int mapT[maxN] = {0};
    for(int i = 0;i<t.length();i++){
        mapT[t[i]]++;
    }
    vector<int> vec;
    for(int i = 0;i<maxN;i++){
        if(mapT[i]>0){
            vec.push_back(i);
        }
    }
    int begin = 0;
    string res ;
    for(int i = 0;i<s.length();i++){
        mapS[s[i]]++;
        while(begin<i){
            char beginC = s[begin];
            if(mapT[beginC]==0){
                begin++;
            }else if(mapS[beginC]>mapT[beginC]){
                mapS[beginC]--;
                begin++;
            }else{
                break;
            }
        }
        if(isComtain(mapS,mapT,vec)){
            int curLen = i-begin+1;
            if(res==""||res.length()>curLen){
                res = s.substr(begin,curLen);
            }
        }
    }
    return res;
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minimumWindowSubstring(s,t);
    cout<<"the min windows substr is : "<<result<<endl;
    return 0;
}


