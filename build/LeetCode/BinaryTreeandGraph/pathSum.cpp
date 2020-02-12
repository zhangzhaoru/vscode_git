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

void preOrder(TreeNode *root, int &curSum, int sum, vector<int> &path,
              vector<vector<int>> &res);
              
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

vector<vector<int>> pathsum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    int curSum = 0;
    preOrder(root, curSum, sum, path, res);
    return res;
}

void preOrder(TreeNode *root, int &curSum, int sum, vector<int> &path,
              vector<vector<int>> &res) {
    if (!root) {
        return;
    }
    curSum += root->val;
    path.push_back(root->val);
    if (curSum == sum && !root->left && !root->right) {
        res.push_back(path);
    }
    preOrder(root->left, curSum, sum, path, res);
    preOrder(root->right, curSum, sum, path, res);
    curSum -= root->val;
    path.pop_back();
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
    vector<vector<int>> res;
    int sum = 22;
    res = pathsum(a,sum);
    for (int i = 0; i < res.size(); i++) {
        for(int j = 0;j<res[i].size();j++)
            cout << res[i][j] << " ";
        cout<<endl;
    }
    cout << endl;
    DestroyTree(a);
    system("pause");
    return 0;
}