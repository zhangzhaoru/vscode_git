/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-13 11:09:09
 * @LastTime     : 2020-02-13 16:08:11
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\definition.cpp
 * @Description: 哈希表的实现
 */

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define maxN 1000
using namespace std;

int intMod(int key, int tableLen);
int stringMod(string key, int tableLen);
void Insert(ListNode *hashTable[], ListNode *node, int tableLen);
bool Search(ListNode *hashTable[], int value, int tableLen);

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


int main() {
    //////////////////////////strmap/////////////////////////////////////////
    /* int charMap[128] = {0};
    //定义字符哈希表
    string str = "aaabcdefghhxxy";
    for (int i = 0; i < str.length(); i++) {
        charMap[str[i]]++;
    }
    for (int i = 0; i < 128; i++) {
        if (charMap[i] > 0) {
            cout << (char)i << " " << i << " : " << charMap[i] << endl;
        }
    }
    cout << endl; */
    ///////////////////////////map///////////////////////////////////////////
    /* map<int, int> charCount;
    for (int i = 0; i < str.length(); i++) {
        charCount[str[i]]++;
    }
    map<int, int>::iterator iter2 = charCount.begin();
    while (iter2 != charCount.end()) {
        cout << (char)(*iter2).first << ": " << (*iter2).second;
        cout << endl;
        iter2++;
    } */
    //////////////////////////hashSort///////////////////////////////////////
    /* int random[maxN] = {123, 12, 3, 4, 435, 2, 34, 3, 54, 32};
    map<int, int> hashMap;
    for (int i = 0; i < maxN; i++) {
        hashMap[random[i]]++;
    }
    map<int, int>::iterator iter = hashMap.begin();
    while (iter != hashMap.end()) {
        if ((*iter).second >= 1 && (*iter).first != 0) {
            cout << (*iter).first << " ";
        }
        iter++;
    }
    cout << endl; */
    /////////////////////////any element mapping/////////////////////////////
    /* const int TableLen = 10;
    int Map[TableLen] = {0};
    Map[intMod(99999999, TableLen)]++;
    Map[intMod(5, TableLen)]++;
    Map[stringMod("abs", TableLen)]++;
    Map[stringMod("safdaswadf", TableLen)]++; */
    ////////////////////////////hash >///////////////////////////////////////
    const int TableLen = 11;
    // 优先选择为素数
    ListNode *hashTable[TableLen] = {0};
    vector<ListNode *> hashNodeVec;
    int test[] = {1, 1, 4, 9, 20, 30, 150, 500};
    int testLen = sizeof(test) / sizeof(int);
    for (int i = 0; i < testLen; i++) {
        hashNodeVec.push_back(new ListNode(test[i]));
    }
    for (int i = 0; i < hashNodeVec.size(); i++) {
        Insert(hashTable, hashNodeVec[i], TableLen);
    }
    cout << "Hash Table has construct !" << endl;
    cout << "Hash Table : " << endl;
    for (int i = 0; i < TableLen; i++) {
        cout << "[" << i << "] : ";
        ListNode *head = hashTable[i];
        while (head) {
            cout << "->" << head->val;
            head = head->next;
        }
        cout << endl;
    }
    cout << endl;
    cout << "Test Search : " << endl;
    for (int i = 0; i < 10; i++) {
        if (Search(hashTable, i, TableLen)) {
            cout << i << " is in the hash table !" << endl;
        } else {
            cout << i << " is not in the hash table !" << endl;
        }
    }
    return 0;
}

/**
 * @Name: intMod&stringMod
 * @Param:
 * @Return:
 * @Description: 对于整形或者字符串建立映射的规则
 */
// 对于整数取余表长后返回
int intMod(int key, int tableLen) { return key % tableLen; }

//将字符串中的ASC2码相加的得到整数取余表长
int stringMod(string key, int tableLen) {
    int sum = 0;
    for (int i = 0; i < key.length(); i++) {
        sum += key[i];
    }
    return sum % tableLen;
}

/**
 * @Name: Insert&Search
 * @Param:
 * @Return:
 * @Description: 实现整形hash表的插入与查找
 */

void Insert(ListNode *hashTable[], ListNode *node, int tableLen) {
    int hashKey = intMod(node->val, tableLen);
    node->next = hashTable[hashKey];
    hashTable[hashKey] = node;
}

bool Search(ListNode *hashTable[], int value, int tableLen) {
    int hashKey = intMod(value, tableLen);
    ListNode *head = hashTable[hashKey];
    while (head) {
        if (head->val == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}