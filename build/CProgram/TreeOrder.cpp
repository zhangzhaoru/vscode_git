//二叉树遍历
//将二叉树镜像输出
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
template <typename T>
void printVec(vector<T> data);
void PreOrder(const TreeNode *root,vector<int> &res);
vector<int> PreOrderLoop(TreeNode *root);
vector<int> LevelOrder(TreeNode *root);
vector<vector<int>> LevelOrder1(TreeNode *pNode);
void print2dVec(vector<vector<int>> data);


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
    res = LevelOrder1(pNode1);
    print2dVec(res);
    cout<<endl;
    cout<<endl;
    vector<int> res1;
    res1 = LevelOrder(pNode1);
    printVec(res1);
    
	DestroyTree(pNode1);
	printf("end!\n");

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

void printVec(vector<int> data){
    for(int i=0;i<data.size();i++){
        cout<<data[i];
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

//借助栈实现非递归先序遍历
vector<int> PreOrderLoop(TreeNode * root){
    std::stack<TreeNode *> s;
    vector<int> res;
    TreeNode *cur,*top;
    cur = root;
    while(cur!=NULL || !s.empty()){
        while(cur!=NULL){
            res.push_back(cur->val);
            s.push(cur);
            cur = cur->left;
        }//找到最左端节点
        top = s.top();
        s.pop();
        cur = top->right;
    } 
    return res;
}

//函数传入参数添加const，则不会修改对象中的数据
void PreOrder(const TreeNode *root,vector<int> &res){
    
    if(root==NULL){
        return;
    }
    res.push_back(root->val);
    PreOrder(root->left,res);
    PreOrder(root->right,res);
}

vector<int> InOrderLoop(TreeNode * root){
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *cur;
    cur = root;
    while(cur||!s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res; 
}

vector<int> PostOrderLoop(TreeNode * root){
    vector<int> res;
    stack<TreeNode *> s;
    TreeNode *cur,*top,*last = NULL;
    cur = root;
    while(cur||!s.empty()){
        while(cur){
            s.push(cur);
            cur = cur->left;
        }
        top = s.top();
        if(top->right==NULL || top->right==last){
            s.pop();
            res.push_back(top->val);
            last = top;
        }else{
            cur = top->right;
        }
    }
    return res; 
}

//借助队列实现非递归层序遍历
vector<int> LevelOrder(TreeNode *root){
    vector<int> res;
    queue<TreeNode *> q;
    TreeNode *front;
    if(root==NULL)
        return res;
    q.push(root);
    while(!q.empty()){
        front = q.front();
        q.pop();
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
        res.push_back(front->val);
    }
    return res;
}

//借助两个栈实现非递归层序遍历
vector<vector<int>> LevelOrder1(TreeNode *pNode){
   stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(pNode);
    int layer = 1;
    vector<vector<int>> res;
    if(!pNode){
        return res;
    }
    while(!s1.empty()||!s2.empty()){
        if(layer%2!=0){
            vector<int> temp;
            while(!s1.empty()){
                TreeNode *top = s1.top();
                temp.push_back(top->val);
                s1.pop();
                if(top->left){
                    s2.push(top->left);
                }
                if(top->right){
                    s2.push(top->right);
                }
            }
            res.push_back(temp);
            layer++;
        }else{
            vector<int> temp1;
            while(!s2.empty()){
                TreeNode *top = s2.top();
                temp1.push_back(top->val);
                s2.pop();
                if(top->right){
                    s1.push(top->right);
                }
                if(top->left){
                    s1.push(top->left);
                }
            }
            res.push_back(temp1);
            layer++;
        }
    }
    return res;
       
}




//添加模板类
template <typename T>
void printVec(vector<T> data){
    for(int i = 0;i<data.size();++i){
        cout<<data[i];
    }
    cout<<endl;
}


int main(){
    Test1();
    system("pause");
    return 0;
}


