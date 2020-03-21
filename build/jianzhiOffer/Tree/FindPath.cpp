/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-20 17:38:48
 * @LastTime: 2020-03-21 12:00:53
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Tree\FindPath.cpp
 * @Description:
 */
/*
 * @Author: ZhangZhaoru
 * @Date: 2020-02-12 21:07:26
 * @Last Modified by: ZhangZhaoru
 * @Last Modified time: 2020-02-12 21:32:16
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void pathNode(TreeNode *node, TreeNode *search, vector<TreeNode *> &path,
              vector<TreeNode *> &result, int &finish);

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

///////////////////////////////////////////////////////////

vector<vector<int>> buffer;
vector<int> tmp;
vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    if (root == NULL) return buffer;
    tmp.push_back(root->val);
    if ((expectNumber - root->val) == 0 && root->left == NULL &&
        root->right == NULL) {
        buffer.push_back(tmp);
    }
    FindPath(root->left, expectNumber - root->val);
    FindPath(root->right, expectNumber - root->val);
    if (tmp.size() != 0) tmp.pop_back();
    return buffer;
}                                                                                         

int main() {
    TreeNode *a = CreateTreeNode(5);
    TreeNode *b = CreateTreeNode(4);
    TreeNode *c = CreateTreeNode(8);
    TreeNode *d = CreateTreeNode(11);
    TreeNode *e = CreateTreeNode(13);
    TreeNode *f = CreateTreeNode(4);
    TreeNode *g = CreateTreeNode(7);
    TreeNode *h = CreateTreeNode(2);
    TreeNode *x = CreateTreeNode(5);
    TreeNode *y = CreateTreeNode(1);
    ConnectTreeNodes(a, b, c);
    ConnectTreeNodes(b, d, NULL);
    ConnectTreeNodes(c, e, f);
    ConnectTreeNodes(d, g, h);
    ConnectTreeNodes(f, x, y);

    
    cout << endl;
    DestroyTree(a);
    return 0;
}
