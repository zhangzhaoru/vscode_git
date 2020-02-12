//二叉树的遍历
#include <iostream>
#include <vector>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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

void preOrder(TreeNode *node, vector<TreeNode *> &preList) {
    if (!node) return;
    preList.push_back(node);
    if (node->left) {
        preOrder(node->left, preList);
    }
    if (node->right) {
        preOrder(node->right, preList);
    }
}

void layerOrder(TreeNode *node, vector<TreeNode *> &prelist) {
    queue<TreeNode *> q;
    q.push(node);
    while(!q.empty()){
        TreeNode * root = q.front();
        q.pop();
        prelist.push_back(root);
        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
    }
}

int main() {
    TreeNode *a = CreateTreeNode(1);
    TreeNode *b = CreateTreeNode(2);
    TreeNode *c = CreateTreeNode(5);
    TreeNode *d = CreateTreeNode(3);
    TreeNode *e = CreateTreeNode(4);
    TreeNode *f = CreateTreeNode(6);
    ConnectTreeNodes(a, b, c);
    ConnectTreeNodes(b, d, e);
    ConnectTreeNodes(c, NULL, f);
    vector<TreeNode *> preList;
    layerOrder(a,preList);
    for (int i = 0; i < preList.size(); i++) {
        cout << preList[i]->val << " ";
    }
    cout << endl;
    DestroyTree(a);
    system("pause");
    return 0;
}