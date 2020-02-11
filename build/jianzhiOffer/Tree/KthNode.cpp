//二叉搜索树第K个节点
//二叉搜索树中序遍历而升序序列
//建立二叉搜索树

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
TreeNode* KthNode(TreeNode* pRoot, int k);
vector<vector<int>> Print(TreeNode *pRoot);
void print2dVec(vector<vector<int>> data);
void printLeverOrder(TreeNode* pRoot);
void dfs(TreeNode *pRoot,int k,int &num,TreeNode *&res);
bool InsertBST(TreeNode *&bt, int num);
TreeNode* CreateBST(int A[],int count);
TreeNode* SearchMax(TreeNode* root);
bool DeleteBST(TreeNode *&bt, int k);
void Delete(TreeNode *&p);
void Delete1(TreeNode *p, TreeNode *&r);
////////////////////////////////////////////////////////////
void Test1()
{
	printf("begin:\n");
    int data[] = {62,88,58,47,35,73,51,99,37,93};
    int count = 10;
    TreeNode *pNode1 = NULL;
    pNode1 = CreateBST(data,count);
    int k = 1;
    TreeNode *res = KthNode(pNode1,k);
    cout<<"The "<<k<<"th min node is : "<<res->val<<endl;
    //层序输出二叉搜索树
	printf("end!\n");
}



bool InsertBST(TreeNode *&bt, int num)
{
    if (bt == NULL)
    {
        bt = (TreeNode *)malloc(sizeof(TreeNode));
        bt->val = num;
        bt->left = bt->right = NULL;
        return true;
    }
    else if (num == bt->val)
        return false;
    else if (num < bt->val)
        return InsertBST(bt->left, num);
    else
        return InsertBST(bt->right, num);
}
 
TreeNode* CreateBST(int A[],int n)
{
    TreeNode *bt = NULL;
    int i = 0;
    while(i < n)
    if (InsertBST(bt, A[i]) == 1)
    {
        ++i;
    }
    return bt;
}

TreeNode* SearchMax(TreeNode* root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL)
        return root;
    else   
        return SearchMax(root->right);
         //一直往右孩子找，直到没有左孩子的结点 
}



void Delete1(TreeNode *p, TreeNode *&r)
{
    TreeNode *q;
    if (r->left != NULL)
        Delete1(p, r->left);
    else
    {
        p ->val = r->val;
        q = r;
        r = r->right;
        free(q);
    }
}
 
void Delete(TreeNode *&p)
{
    TreeNode *q;
    if (p->right == NULL)
    {
        q = p;
        p = p->left;
        free(q);
    }
    else if (p->left == NULL)
    {
        q = p;
        p = p->right;
        free(q);
    }
    else
        Delete1(p, p->right);
}
 
bool DeleteBST(TreeNode *&bt, int k)
{
    if (bt == NULL)
        return false;
    if (k <bt->val)
        return DeleteBST(bt->left, k);
    else if (k >bt->val)
        return DeleteBST(bt->right, k);
    else
    {
        Delete(bt);
        return true;
    }

}






//层序输出二叉树
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

void printLeverOrder(TreeNode* pRoot){
    if(pRoot!=NULL){
        queue<TreeNode *> q;
        q.push(pRoot);
        while(!q.empty()){
            TreeNode *top = q.front();
            cout<<top->val;
            q.pop();
        }
        cout<<endl;
        if(pRoot->left){
            q.push(pRoot->left);
        }
        if(pRoot->right){
            q.push(pRoot->right);
        }
    }
}


TreeNode* KthNode(TreeNode* pRoot, int k){
    int num = 0;
    TreeNode * res = NULL;
    dfs(pRoot,k,num,res);
    return res;
}

void dfs(TreeNode *pRoot,int k,int &num,TreeNode *&res){
    if(!pRoot)
        return;
    dfs(pRoot->left,k,num,res);
    num++;
    if(num==k){
        res = pRoot;
    }
    dfs(pRoot->right,k,num,res);
}


int main(){
    Test1();
    system("pause");
    return 0;
}


