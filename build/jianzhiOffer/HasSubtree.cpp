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
bool dfs(TreeNode *pRoot1,TreeNode *pRoot2);
void DestroyTree(struct TreeNode *pRoot);
bool HasSubtree1(TreeNode* pRoot1, TreeNode* pRoot2);
void Test(struct TreeNode *pRoot, struct TreeNode *pRoots);
void Test1();


bool HasSubtree1(TreeNode* pRoot1, TreeNode* pRoot2){
    if(!pRoot1||!pRoot2){
        return false;
    }
    return dfs(pRoot1,pRoot2)||HasSubtree1(pRoot1->left,pRoot2)||HasSubtree1(pRoot1->right,pRoot2);
}

bool dfs(TreeNode * pRoot1,TreeNode * pRoot2){
    if(pRoot2==NULL){
        return true;
    }
    if(pRoot1==NULL){
        return false;
    }
    if(pRoot1->val!=pRoot2->val){
        return false;
    }
    return dfs(pRoot1->left,pRoot2->left)&&dfs(pRoot1->right,pRoot2->right);    
}


void Test(TreeNode *pRoot, TreeNode *pRoots)
{
	bool result = HasSubtree1(pRoot,pRoots);
	if (result == true)
		printf("The tree2 is the tree1's subtree!\n");
	else
		printf("The tree2 is not the tree1's subtree!\n");
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
    
    struct TreeNode *pNodes1 = CreateTreeNode(1);
	struct TreeNode *pNodes2 = CreateTreeNode(2);
	struct TreeNode *pNodes3 = CreateTreeNode(4);
    ConnectTreeNodes(pNodes1, pNodes2, pNodes3);

	Test(pNode1, pNodes1);
	DestroyTree(pNode1);
	DestroyTree(pNodes1);
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

