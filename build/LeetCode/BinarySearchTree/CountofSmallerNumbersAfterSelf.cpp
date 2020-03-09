/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-23 16:55:04
 * @LastTime: 2020-02-23 18:18:09
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\BinarySearchTree\CountofSmallerNumbersAfterSelf.cpp
 * @Description: 逆序数(二叉排序树 计算复杂度为O(nlog(n)))
 */
#include <iostream>
#include <vector>
using namespace std;

struct BSTnode {
    int val;
    int count;
    BSTnode *left;
    BSTnode *right;
    BSTnode(int x) : val(x), left(NULL), right(NULL), count(0) {}
};
// count插入节点左子树节点个数

void BST_insert(BSTnode *node, BSTnode *insert_node, int &countSmall) {
    if (insert_node->val <= node->val) {
        node->count += 1;
        if (node->left) {
            BST_insert(node->left, insert_node, countSmall);
        } else {
            node->left = insert_node;
        }
    } else {
        countSmall += node->count + 1;
        if (node->right) {
            BST_insert(node->right, insert_node, countSmall);
        } else {
            node->right = insert_node;
        }
    }
}

vector<int> countSmaller(vector<int> &nums) {
    vector<int> res;
    vector<BSTnode *> nodeVec;
    vector<int> count;
    for (int i = nums.size() - 1; i >= 0; i--) {
        nodeVec.push_back(new BSTnode(nums[i]));
    }
    count.push_back(0);
    for (int i = 1; i < nodeVec.size(); i++) {
        int countSmall = 0;
        BST_insert(nodeVec[0], nodeVec[i], countSmall);
        count.push_back(countSmall);
    }
    for (int i = nodeVec.size() - 1; i >= 0; i--) {
        delete nodeVec[i];
        res.push_back(count[i]);
    }
    return res;
}

int main() {
    vector<int> nums = {5, -7, 9, 1, 3, 5, -2, 1};
    vector<int> count;
    count = countSmaller(nums);
    for (int i = 0; i < count.size(); i++) {
        cout << count[i] << " ";
    }
    cout << endl;
    return 0;
}