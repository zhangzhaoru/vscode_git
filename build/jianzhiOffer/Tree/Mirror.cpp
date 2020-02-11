//将二叉树镜像输出
#include<iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

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
void Mirror(TreeNode *pRoot);


void Mirror(TreeNode *pRoot){
    if(pRoot==NULL)
        return;
    if(pRoot->left ==NULL && pRoot->right){
        return;
    }
    TreeNode *temp;
    temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
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
    
    
    PrintTree(pNode1);
    Mirror(pNode1);
    cout<<"the Mirror Tree is:"<<endl;
    cout<<endl;
    PrintTree(pNode1);
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


