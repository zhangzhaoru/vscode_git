/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-20 17:10:58
 * @LastTime: 2020-03-20 17:31:08
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Tree\VerifySquenceOfBST.cpp
 * @Description: 验证二叉搜索树后序遍历序列
 */
#include <iostream>
#include <vector>
using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
    vector<int> leftTree, rightTree;
    if (sequence.empty()) return false;
    int len = sequence.size();
    int root = sequence[len - 1];
    int i, j;
    for (i = 0; i < len - 1; i++) {
        if (sequence[i] > root) break;
    }
    for (j = i; j < len - 1; j++) {
        if (sequence[j] < root) return false;
    }
    if (i != 0) {
        for (int k1 = 0; k1 < i; k1++) {
            leftTree.push_back(sequence[k1]);
        }
    }
    if (j != len - 2) {
        for (int k2 = i; k2 < len - 1; k2++) {
            rightTree.push_back(sequence[k2]);
        }
    }
    bool left = true;
    bool right = true;
    if (!leftTree.empty()) left = VerifySquenceOfBST(leftTree);
    if (!rightTree.empty()) right = VerifySquenceOfBST(rightTree);
    return left && right;
}

int main() {
    vector<int> sequence = {2, 4, 3, 8, 6, 5};
    bool res = VerifySquenceOfBST(sequence);
    if (res) {
        cout << "The sequence is valid ! " << endl;
    } else {
        cout << "The sequence is not valid ! " << endl;
    }
    return 0;
}