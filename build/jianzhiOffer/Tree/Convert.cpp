/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-22 10:05:00
 * @LastTime: 2020-03-22 10:17:47
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Tree\Convert.cpp
 * @Description: 将二叉搜索树转化为双向链表
 */
/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-22 18:21:42
 * @LastTime: 2020-02-22 23:24:37
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\BinarySearchTree\BinarySearch.cpp
 * @Description: ??????????????????
 */

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void Swap(int *&pointer1, int *&pointer2);
void qSort(int left, int right, vector<int> &v);
istream &operator>>(istream &input1, vector<int> &v);
ostream &operator<<(ostream &output, vector<int> &v);
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

// ???????????
TreeNode *findParent(TreeNode *node, int value, TreeNode *&parent) {
    while (node) {
        if (node->val == value) {
            break;
        }
        parent = node;
        if (value < node->val) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node;
}

// ??????(????????????????)
TreeNode *findSuccessor(TreeNode *node, TreeNode *&parent) {
    parent = node;
    TreeNode *ptr = node->right;
    while (ptr->left) {
        parent = ptr;
        ptr = ptr->left;
    }
    return ptr;
}

// ???????????(?)??
void deletenode(TreeNode *parent, TreeNode *node) {
    if (node->val < parent->val) {
        if (node->left && !node->right) {
            parent->left = node->left;
        } else if (!node->left && node->right) {
            parent->left = node->right;
        } else {
            parent->left = NULL;
        }
    } else if (node->val > parent->val) {
        if (node->left && !node->right) {
            parent->right = node->left;
        } else if (!node->left && node->right) {
            parent->right = node->right;
        } else {
            parent->right = NULL;
        }
    }
}

TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *parent = NULL;
    TreeNode *node = findParent(root, key, parent);
    if (!node) {
        return root;
    }
    if (node->left && node->right) {
        TreeNode *successor = findSuccessor(node, parent);
        deletenode(parent, successor);
        node->val = successor->val;
        return root;//???????????????????
    }
    if (parent) {
        deletenode(parent, node);
        return root;
    }
    // ????????????
    if (node->left) {
        node = node->left;
    } else {
        root = node->right;
    }
    return root;
}

// ???????????????
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

// ?????????????????
TreeNode *CreateBST(vector<int> &nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    vector<TreeNode *> nodeVec;
    qSort(0, nums.size() - 1, nums);
    preOrderInsert(nums, nodeVec, 0, nums.size() - 1);
    for (int i = 1; i < nodeVec.size(); i++) {
        BST_insert(nodeVec[0], nodeVec[i]);
    }
    return nodeVec[0];
}

void Swap(int *&pointer1, int *&pointer2) {
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

void qSort(int left, int right, vector<int> &v) {
    if (left > right) return;
    int i, j, base;
    i = left;
    j = right;
    base = v[left];
    while (i < j) {
        while (v[j] >= base && i < j) {
            j--;
        }
        while (v[i] <= base && i < j) {
            i++;
        }
        if (i < j) {
            int *pointer1 = &v[i];
            int *pointer2 = &v[j];
            Swap(pointer1, pointer2);
        }
    }
    v[left] = v[i];
    v[i] = base;
    qSort(left, i - 1, v);
    qSort(i + 1, right, v);
}

istream &operator>>(istream &input1, vector<int> &v) {
    string s;
    getline(input1, s);
    stringstream ss(s);
    int x;
    while (ss >> x) {
        v.push_back(x);
    }
    return input1;
}

ostream &operator<<(ostream &output, vector<int> &v) {
    for (auto i = v.begin(); i < v.end(); i++) {
        output << *i;
        if (i < v.end() - 1) {
            output << " ";
        }
    }
    return output;
}

///////////////////////////////////////////////////////////
TreeNode *Convert(TreeNode *pRoot){
    if(pRoot== NULL)
        return NULL;
    TreeNode *pre  =NULL;
    convert2Lists(pRoot,pre);
    TreeNode *res = pRoot;
    while(res->left){
        res = res->left;
    }
    return res;
}

void convert2Lists(TreeNode *cur,TreeNode *&pre){
    if(cur==NULL)
        return;
    convert2Lists(cur->left,pre);
    cur->left = pre;
    if(pre)
    pre->right = cur;
    pre = cur;
    convert2Lists(cur->right,pre);
}

int main() {
    vector<int> data = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93, 36, 39, 42, 62};
    TreeNode *root = CreateBST(data);
    midOrderPrint(root);
    cout<<endl;
    root = deleteNode(root,99);
    midOrderPrint(root);
    cout << endl;
    return 0;
}
