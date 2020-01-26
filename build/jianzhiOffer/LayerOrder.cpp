//层序遍历二叉树
//之字形输出二叉树
#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include<stack>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode (int x):val(x),left(NULL),right(NULL){}
};

struct TreeNode *CreateTreeNode(int val);
void ConnectTreeNodes(struct TreeNode *pRoot, struct TreeNode *pLeft, struct TreeNode *pRight);
void PrintTreeNode(struct TreeNode *pNode);
void PrintTree(struct TreeNode *pRoot);
void DestroyTree(struct TreeNode *pRoot);
void Test1();
vector<vector<int>> Print(TreeNode *pRoot);
void print2dVec(vector<vector<int>> data);


vector<vector<int>> Print(TreeNode *pRoot){
    vector<vector<int>> res;
    if(pRoot==NULL){
        return res;
    }
    queue<TreeNode *> q;
    q.push(pRoot);
    while(!q.empty()){
        int left = 0;
        int right = q.size(); 
        vector<int> temp;       
        while(left++<right){
            TreeNode * node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        res.push_back(temp);
    }
    return res;
}

void print2dVec(vector<vector<int>> data){
    for(int i = 0;i<data.size();i++){
        for(int j = 0;j<data[i].size();j++){
            cout<<data[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
} 


void Test1()
{
	printf("begin:\n");
	struct TreeNode *pNode1 = CreateTreeNode(1);
	struct TreeNode *pNode2 = CreateTreeNode(2);
	struct TreeNode *pNode3 = CreateTreeNode(3);
	struct TreeNode *pNode4 = CreateTreeNode(4);
	struct TreeNode *pNode5 = CreateTreeNode(5);
	struct TreeNode *pNode6 = CreateTreeNode(6);
	struct TreeNode *pNode7 = CreateTreeNode(7);
 
	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, NULL, pNode6);
	ConnectTreeNodes(pNode5, pNode7, NULL);
    vector<vector<int>> res;
    res = Print(pNode1);
    print2dVec(res);
	DestroyTree(pNode1);
	printf("end!\n");

}


struct TreeNode *CreateTreeNode(int val)
{
	struct TreeNode *pNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	pNode->val = val;
	pNode->left = NULL;
	pNode->right = NULL;
	return pNode;
}
 
void ConnectTreeNodes(struct TreeNode *pRoot, struct TreeNode *pLeft, struct TreeNode *pRight)
{
	if (pRoot != NULL)
	{
		pRoot->left = pLeft;
		pRoot->right = pRight;
	}
}
void PrintTreeNode(struct TreeNode *pNode)
{
	if (pNode != NULL)
	{
		printf("the val of this node is :%d\n", pNode->val);
		if (pNode->left != NULL)
		{
			printf("the val of left child is %d\n",pNode->left->val);
		}
		else
		{
			printf("the left child is NULL\n");
		}
		if (pNode->right != NULL)
		{
			printf("the val of right child is %d\n",pNode->right->val);
		}
		else
		{
			printf("the right child is NULL\n");
		}
	}
	printf("\n");
}
void PrintTree(struct TreeNode *pRoot)
{
	PrintTreeNode(pRoot);
	if (pRoot != NULL)
	{
		if (pRoot->left != NULL)
			PrintTree(pRoot->left);
		if (pRoot->right != NULL)
			PrintTree(pRoot->right);
	}
}
void DestroyTree(struct TreeNode *pRoot)
{
	if (pRoot != NULL)
	{
		struct TreeNode *pLeft = pRoot->left;
		struct TreeNode *pRight = pRoot->right;
 
		free(pRoot);
		pRoot == NULL;
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}




int main(){
    Test1();
    system("pause");
    return 0;
}


