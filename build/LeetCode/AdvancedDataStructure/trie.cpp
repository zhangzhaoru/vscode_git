/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-23 18:20:04
 * @LastTime: 2020-02-23 21:17:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\AdvancedDataStructure\trie.cpp
 * @Description: 字典树 利用字符串的公共前缀减少存储空间与查询时间
 */
#define TRIE_MAX_CHAR_NUM 26
#include <iostream>
#include <vector>
using namespace std;
struct TrieNode {
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode() : is_end(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            child[i] = 0;
        }
    }
};

void preOrder_trie(TrieNode *node, int layer);
void get_all_word_from_trie(TrieNode *node, string &word,
                            vector<string> &word_list);

int main() {
    TrieNode root;
    TrieNode n1;
    TrieNode n2;
    TrieNode n3;
    root.child['a' - 'a'] = &n1;
    root.child['b' - 'a'] = &n2;
    root.child['e' - 'a'] = &n3;
    n2.is_end = true;

    TrieNode n4;
    TrieNode n5;
    TrieNode n6;
    n1.child['b' - 'a'] = &n4;
    n2.child['c' - 'a'] = &n5;
    n3.child['f' - 'a'] = &n6;

    TrieNode n7;
    TrieNode n8;
    TrieNode n9;
    TrieNode n10;
    n4.child['c' - 'a'] = &n7;
    n4.child['d' - 'a'] = &n8;
    n5.child['d' - 'a'] = &n9;
    n6.child['g' - 'a'] = &n10;
    n7.is_end = true;
    n8.is_end = true;
    n9.is_end = true;
    n10.is_end = true;

    TrieNode n11;
    n7.child['d' - 'a'] = &n11;
    n11.is_end = true;
    preOrder_trie(&root, 0);

    cout << endl;
    vector<string> word_list;
    string word;
    get_all_word_from_trie(&root, word, word_list);
    for (int i = 0; i < word_list.size(); i++) {
        cout << word_list[i] << endl;
    }
    return 0;
}

void preOrder_trie(TrieNode *node, int layer) {
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            for (int j = 0; j < layer; j++) {
                cout << "----";
            }
            cout << (char)(i + 'a');
            if (node->child[i]->is_end) {
                cout << "(end)";
            }
            cout << endl;
            preOrder_trie(node->child[i], layer + 1);
        }
    }
}

// 读取Trie树中的字符串
void get_all_word_from_trie(TrieNode *node, string &word,
                            vector<string> &word_list) {
    for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
        if (node->child[i]) {
            word.push_back(i + 'a');
            if (node->child[i]->is_end) {
                word_list.push_back(word);
            }
            get_all_word_from_trie(node->child[i], word, word_list);
            word.erase(word.length() - 1, 1);  // 弹出栈顶元素
        }
    }
}
