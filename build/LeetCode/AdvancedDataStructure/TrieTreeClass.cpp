/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-26 18:01:34
 * @LastTime: 2020-02-28 13:08:37
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscodegit\vscode_git\build\LeetCode\AdvancedDataStructure\TrieTreeClass.cpp
 * \vscodegit\vscode_git\build\LeetCode\AdvancedDataStructure\TrieTreeClass.cpp
 * @Description:
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

class TrieTree {
   public:
    TrieTree() {}
    ~TrieTree() {
        for (int i = 0; i < nodeVec.size(); i++) {
            delete nodeVec[i];
        }
    }
    void insert(const char *word) {}
    bool search(const char *word) {}
    bool startsWith(const char *prefix) {}
    TrieNode *returnRoot() { return &root; }

   private:
    TrieNode *new_node() {
        TrieNode *node = new TrieNode();
        nodeVec.push_back(node);
        return node;
    }
    vector<TrieNode *> nodeVec;
    TrieNode root;
};

void TrieTree::insert(const char *word) {
    TrieNode *ptr = &root;
    while (*word) {
        int pos = *word - 'a';
        if (!ptr->child[pos]) {
            ptr->child[pos] = new_node();
        }
        ptr = ptr->child[pos];
        word++;
    }
    ptr->is_end = true;
}

bool TrieTree::search(const char *word) {
    TrieNode *ptr = &root;
    while (*word) {
        int pos = *word - 'a';
        if (!ptr->child[pos]) {
            return false;
        }
        ptr = ptr->child[pos];
        word++;
    }
    return ptr->is_end;
}

bool TrieTree::startsWith(const char *prefix) {
    TrieNode *ptr = &root;
    while (*prefix) {
        int pos = *prefix - 'a';
        if (!ptr->child[pos]) {
            return false;
        }
        ptr = ptr->child[pos];
        prefix++;
    }
    return true;
}

class WordDictionary {
   public:
    WordDictionary() {}
    void addWord(string word) { _trie_tree.insert(word.c_str()); }
    bool search(string word) {
        return search_trie(_trie_tree,word.c_str());
    }

   private:
    TrieTree _trie_tree;
};

bool search_trie(TrieNode *node, const char *word) {
    if (*word == '\0') {
        if (node->is_end) {
            return true;
        }
        return false;
    }
    if (*word == '.') {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; i++) {
            if (node->child[i] && search_trie(node->child[i], word + 1)) {
                return true;
            }
        }
    } else {
        int pos = *word - 'a';
        if (node->child[pos] && search_trie(node->child[pos], word + 1)) {
            return true;
        }
    }
    return false;
}
int main() {
    TrieTree trieTree;
    trieTree.insert("abcd");
    trieTree.insert("abc");
    trieTree.insert("b");
    trieTree.insert("bcd");
    trieTree.insert("efg");
}