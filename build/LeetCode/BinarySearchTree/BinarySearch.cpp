/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-22 18:21:42
 * @LastTime: 2020-02-22 20:53:21
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\BinarySearchTree\BinarySearch.cpp
 * @Description: ??????????????????
 */

#include <stdio.h>
#include <iostream>
#include<vector>
#include<sstream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool BST_search(TreeNode *node, int value) {
    if (node->val == value) {
        return true;
    }
    if (value < node->val) {
        if (node->left) {
            return BST_search(node->left, value);
        } else {
            return false;
        }
    } else {
        if (node->right) {
            return BST_search(node->right, value);
        } else {
            return false;
        }
    }
}

void BST_insert(TreeNode *node, TreeNode *&insert_node) {
    if (insert_node->val < node->val) {
        if (node->left) {
            BST_insert(node->left, insert_node);
        } else {
            node->left = insert_node;
        }
    } else {
        if (node->right) {
            BST_insert(node->right, insert_node);
        } else {
            node->right = insert_node;
        }
    }
}

void midOrderPrint(TreeNode *root) {
    if (!root) {
        return;
    }
    midOrderPrint(root->left);
    cout << root->val << " ";
    midOrderPrint(root->right);
}

void preOrderInsert(const vector<int> &nums, vector<TreeNode *> &nodeVec,
                    int begin, int end) {
    if (begin > end) {
        return;
    }
    int mid = (begin + end) / 2;
    nodeVec.push_back(new TreeNode(nums[mid]));
    preOrderInsert(nums, nodeVec, begin, mid - 1);
    preOrderInsert(nums, nodeVec, mid + 1, end);
}


TreeNode *CreateBST(vector<int> &nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode *> nodeVec;
    preOrderInsert  (nums, nodeVec, 0, nums.size() - 1);
    for (int i = 1; i < nodeVec.size(); i++) {
        BST_insert(nodeVec[0], nodeVec[i]);
    }
    return nodeVec[0];
}

void Swap(int*& pointer1,int *&pointer2){
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

void qSort(int left,int right,vector<int> &v){
    if(left>right)
        return;
    int i,j,base;
    i = left;
    j = right;
    base = v[left];
    while(i<j){
        while(v[j]>=base && i<j){
            j--;
        }
        while(v[i]<=base && i<j){
            i++;
        }
        if(i<j){
            int *pointer1 = &v[i];
            int *pointer2 = &v[j];
            Swap(pointer1,pointer2);
        }

    }
    v[left] = v[i];
    v[i] = base;
    qSort(left,i-1,v);
    qSort(i+1,right,v);
}



istream& operator >>(istream &input1,vector<int> &v){
    string s;
    getline(input1,s);
    stringstream ss(s);
    int x;
    while(ss>>x){
        v.push_back(x);
    }
    return input1;
}

ostream &operator<<(ostream &output,vector<int> &v){
    for(auto i = v.begin();i<v.end();i++){
        output<<*i;
        if(i<v.end()-1){
            output<<" ";
        }
    }
    return output;
}



int main() {
    vector<int> data = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93, 36, 39, 42, 62};
    qSort(0,data.size()-1,data);
    TreeNode *root = CreateBST(data);
    midOrderPrint(root);
    cout << endl;
    return 0;
}
