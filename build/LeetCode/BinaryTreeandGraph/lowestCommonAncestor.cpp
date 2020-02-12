//最近的公共祖先
// 路径之和
#include <iostream>
#include <stack>
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

void pathNode(TreeNode *node, TreeNode *search, vector<TreeNode *> &path,
              vector<TreeNode *> &result, int &finish) {
    if (!node || finish == 1) {
        return;
    }
    path.push_back(node);
    if (node == search) {
        finish = 1;
        result = path;
    }
    pathNode(node->left, search, path, result, finish);
    pathNode(node->right, search, path, result, finish);
    path.pop_back();
}

TreeNode *lowestCommonAncestor(TreeNode *node, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> path;
    vector<TreeNode *> nodePPath;
    vector<TreeNode *> nodeQPath;
    int finish = 0;
    pathNode(node, p, path, nodePPath, finish);
    path.clear();
    finish = 0;
    pathNode(node, q, path, nodeQPath, finish);
    TreeNode *commonNode = NULL;
    int i = 0;
    while (nodePPath[i] == nodeQPath[i]) {
        commonNode = nodePPath[i];
        i++;
    }
    return commonNode;
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
    TreeNode *res;
    res = lowestCommonAncestor(a, e, y);
    cout << res->val << endl;
    DestroyTree(a);
    system("pause");
    return 0;
}