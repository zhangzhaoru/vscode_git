//二叉树转换为链表
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

void preOrder(TreeNode *node, vector<TreeNode *> &preNode) {
    if (!node) {
        return;
    }
    preNode.push_back(node);
    preOrder(node->left, preNode);
    preOrder(node->right, preNode);
}

void flatten(TreeNode *root) {
    vector<TreeNode *> preNode;
    preOrder(root, preNode);
    for (int i = 0; i < preNode.size() - 1; i++) {
        preNode[i]->left = NULL;
        preNode[i]->right = preNode[i + 1];
    }
    preNode[preNode.size() - 1]->left = NULL;
    preNode[preNode.size() - 1]->right = NULL;
    root = preNode[0];
}

void preOrder2(TreeNode *node, TreeNode *&last) {
    if (!node) {
        return;
    }
    if (!node->left && !node->right) {
        last = node;
        return;
    }
    TreeNode *left = node->left;
    TreeNode *right = node->right;
    TreeNode *leftLast = NULL;
    TreeNode *rightLast = NULL;
    if (left) {
        preOrder2(left, leftLast);
        node->left = NULL;
        node->right = left;
        last = leftLast;
    }
    if (right) {
        preOrder2(right, rightLast);
        if (leftLast) {
            leftLast->right = right;
        }
        last = rightLast;
    }
}

//递归写法，将左右子树转换为二叉树
void flatten1(TreeNode *root) {
    TreeNode *last = NULL;
    preOrder2(root, last);
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
    flatten1(a);
    TreeNode *head = a;
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
    DestroyTree(a);
    system("pause");
    return 0;
}