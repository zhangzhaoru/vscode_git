/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-13 16:29:56
 * @LastTime     : 2020-02-13 16:45:21
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\CProgram\mapExapmple.cpp
 * @Description: stl::map
 */
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct ListNode {
    string key;
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int main() {
    map<string, int> hashMap;
    string str1 = "abc";
    string str2 = "aaa";
    string str3 = "xxxxxx";
    hashMap[str1] = 1;
    hashMap[str2] = 2;
    hashMap[str3] = 100;
    if (hashMap.find(str1) != hashMap.end()) {
        cout << str1 << " is in hash map, the value is " << hashMap[str1]
             << endl;
    }
    map<string, int>::iterator it;
    for (it = hashMap.begin(); it != hashMap.end(); it++) {
        cout << "hashMap[ " << it->first << " ]  = " << it->second << endl;
    }
    return 0;
}