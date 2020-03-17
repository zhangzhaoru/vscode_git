/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-17 10:30:21
 * @LastTime: 2020-03-17 10:41:22
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Tree\reConstructBinaryTree.cpp
 * @Description: 根据二叉树的前序与中序遍历序列重建二叉树
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin);
struct TreeNode *CreateTreeNode(int val);
void ConnectTreeNodes(struct TreeNode *pRoot, struct TreeNode *pLeft,
                      struct TreeNode *pRight);
void PrintTreeNode(struct TreeNode *pNode);
void PrintTree(struct TreeNode *pRoot);
void DestroyTree(struct TreeNode *pRoot);
void Test1();


////////////////////////////////////////////////////////////


void Test1() {   
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};
    TreeNode *root = reConstructBinaryTree(pre,vin);
    PrintTree(root);
    DestroyTree(root);
    printf("end!\n");
}
/////////////////////////////////////////////////////////////////
struct TreeNode *CreateTreeNode(int val) {
    struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    pNode->val = val;
    pNode->left = NULL;
    pNode->right = NULL;
    return pNode;
}

void ConnectTreeNodes(struct TreeNode *pRoot, struct TreeNode *pLeft,
                      struct TreeNode *pRight) {
    if (pRoot != NULL) {
        pRoot->left = pLeft;
        pRoot->right = pRight;
    }
}
void PrintTreeNode(struct TreeNode *pNode) {
    if (pNode != NULL) {
        printf("the val of this node is :%d\n", pNode->val);
        if (pNode->left != NULL) {
            printf("the val of left child is %d\n", pNode->left->val);
        } else {
            printf("the left child is NULL\n");
        }
        if (pNode->right != NULL) {
            printf("the val of right child is %d\n", pNode->right->val);
        } else {
            printf("the right child is NULL\n");
        }
    }
    printf("\n");
}
void PrintTree(struct TreeNode *pRoot) {
    PrintTreeNode(pRoot);
    if (pRoot != NULL) {
        if (pRoot->left != NULL) PrintTree(pRoot->left);
        if (pRoot->right != NULL) PrintTree(pRoot->right);
    }
}
void DestroyTree(struct TreeNode *pRoot) {
    if (pRoot != NULL) {
        struct TreeNode *pLeft = pRoot->left;
        struct TreeNode *pRight = pRoot->right;

        free(pRoot);
        pRoot == NULL;
        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

/////////////////////////////////////////////////////

TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    int len = vin.size();
    if (len == 0) return NULL;
    int val = pre[0];
    TreeNode *node = new TreeNode(pre[0]);
    vector<int> pre_left, in_left, pre_right, in_right;
    int root = 0;
    for (; root < len; root++) {
        if (vin[root] == val) break;
    }
    for (int i = 0; i < len; i++) {
        if (i < root) {
            in_left.push_back(vin[i]);
            pre_left.push_back(pre[i + 1]);
        } else if (i > root) {
            in_right.push_back(vin[i]);
            pre_right.push_back(pre[i]);
        }
    }
    node->left = reConstructBinaryTree(pre_left, in_left);
    node->right = reConstructBinaryTree(pre_right, in_right);
    return node;
}

int main() {
    Test1();
    system("pause");
    return 0;
}
