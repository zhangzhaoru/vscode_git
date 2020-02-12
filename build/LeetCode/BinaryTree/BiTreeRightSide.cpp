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

vector<int> rightSideView(TreeNode *root) {
    vector<int> view;
    queue<pair<TreeNode *, int>> Q;
    if (root) {
        Q.push(make_pair(root, 0));
    }
    while (!Q.empty()) {
        TreeNode *node = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        if (view.size() == depth) {
            view.push_back(node->val);
        } else {
            view[depth] = node->val;
        }
        if (node->left) {
            Q.push(make_pair(node->left, depth + 1));
        }
        if (node->right) {
            Q.push(make_pair(node->right, depth + 1));
        }
    }
    return view;
}

//实现二叉树按层输出
vector<pair<TreeNode *, int>> layerOrder(TreeNode *root) {
    vector<pair<TreeNode *, int>> res;
    queue<pair<TreeNode *, int>> Q;
    if (root) {
        Q.push(make_pair(root, 0));
    }
    while (!Q.empty()) {
        TreeNode *node = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        res.push_back(make_pair(node, depth));
        if (node->left) {
            Q.push(make_pair(node->left, depth + 1));
        }
        if (node->right) {
            Q.push(make_pair(node->right, depth + 1));
        }
    }
    return res;
}

//实现二叉树按层输出
void printLayer(vector<pair<TreeNode *, int>> &data) {
    int i = 0;
    int curDepth = 0;
    while (i < data.size()) {
        int depth = data[i].second;
        if (depth == curDepth) {
            cout << data[i].first->val << " ";
        } else {
            cout << endl;
            cout<<data[i].first->val << " ";
            curDepth++;
        }
        i++;
    }
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
    /* vector<int> rightView = rightSideView(a);
    cout << "the right side view node is : ";
    for (int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    } */
    vector<pair<TreeNode *, int>> res;
    res = layerOrder(a);
    printLayer(res);
    cout << endl;
    DestroyTree(a);
    system("pause");
    return 0;
}
