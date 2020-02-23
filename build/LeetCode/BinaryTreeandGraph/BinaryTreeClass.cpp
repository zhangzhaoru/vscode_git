/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-23 11:48:20
 * @LastTime: 2020-02-23 13:13:50
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\BinaryTreeandGraph\BinaryTreeClass.cpp
 * @Description: 二叉树类的实现
 */
#include <iostream>
using namespace std;
template <class T>
class BinaryTreeNode {
    friend class BinaryTree<T>;

   private:
    T element;                      //结点的数据域
    BinaryTreeNode<T>* LeftChild;   //结点的左孩子结点
    BinaryTreeNode<T>* RightChild;  //结点的右孩子结点
   public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
    bool isLeaf() const;  //判断该结点是否是叶子结点，若是，则返回true
};

template <class T>
BinaryTreeNode<T>::BinaryTreeNode() {
    LeftChild = RightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele) {
    element = ele;
    LeftChild = RightChild = NULL;
}
template <class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l,
                                  BinaryTreeNode<T>* r) {
    element = ele;
    LeftChild = l;
    RightChild = r;
}
template <class T>
bool BinaryTreeNode<T>::isLeaf() const {
    if (LeftChild == NULL && RightChild == NULL)
        return true;
    else
        return false;
}

template <class T>
class BinaryTree {
   private:
    BinaryTreeNode<T>* root;

   public:
    BinaryTree();
    ~BinaryTree() {}
    bool IsEmpty() const;                //判断二叉树是否为空树
    BinaryTreeNode<T>* getRoot() const;  //返回二叉树的根结点
    void breadthFirstOrder(
        BinaryTreeNode<T>* root);  //广度优先遍历以root为根结点的子树
    void preOrder(BinaryTreeNode<T>* root);  //先序遍历以root为根结点的子树
    void inOrder(BinaryTreeNode<T>* root);  //中序遍历以root为根结点的子树
    void postOrder(BinaryTreeNode<T>* root);  //后序遍历以root为根结点的子树
    void deleteBinaryTree(BinaryTreeNode<T>* root);  //删除以root为根结点的子树
    void visit(BinaryTreeNode<T>* pointer);  //访问当前结点
    BinaryTreeNode<T>* build_from_pre_and_in(char* preorder, char* inorder,
                                             int n);
    //根据前序和中序遍历表达式构造二叉树
    BinaryTreeNode<T>* build_from_post_and_in(char* postorder, char* inorder,
                                              int m);
    //根据后序和中序遍历表达式构造二叉树
    int getRootId1(char* preorder, char* inorder,
                   int n);  //返回根结点在中序遍历表达式中序号
    int getRootId2(char* postorder, char* inorder,
                   int m);  //返回根结点在中序遍历表达式中序号
};

template <class T>
void BinaryTree<T>::breadthFirstOrder(BinaryTreeNode<T>* root) {
    queue<BinaryTreeNode<T>*> nodeQueue;
    BinaryTreeNode<T>* pointer = root;
    if (pointer) nodeQueue.push(pointer);
    while (!nodeQueue.empty()) {
        pointer = nodeQueue.front();
        visit(pointer);
        nodeQueue.pop();
        if (pointer->LeftChild) nodeQueue.push(pointer->LeftChild);
        if (pointer->RightChild) nodeQueue.push(pointer->RightChild);
    }
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root) {
    stack<BinaryTreeNode<T>*> nodeStack;
    BinaryTreeNode<T>* pointer = root;
    while (!nodeStack.empty() || pointer) {
        if (pointer) {
            visit(pointer);
            if (pointer->RightChild != NULL)
                nodeStack.push(pointer->RightChild);
            pointer = pointer->LeftChild;
        } else {
            pointer = nodeStack.top();
            nodeStack.pop();
        }
    }
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root) {
    stack<BinaryTreeNode<T>*> nodeStack;
    BinaryTreeNode<T>* pointer = root;
    while (!nodeStack.empty() || pointer) {
        if (pointer) {
            nodeStack.push(pointer);
            pointer = pointer->LeftChild;
        } else {
            pointer = nodeStack.top();
            visit(pointer);
            pointer = pointer->RightChild;
            nodeStack.pop();
        }
    }
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* root) {
    stack<BinaryTreeNode<T>*> nodeStack;
    BinaryTreeNode<T>*pre = root, *pointer = root;
    while (pointer) {
        //入栈过程
        for (; pointer->LeftChild != NULL; pointer = pointer->LeftChild) {
            nodeStack.push(pointer);
        }
        //出栈过程
        while (pointer != NULL &&
               (pointer->RightChild == NULL || pointer->RightChild == pre))
        //当前结点右孩子为空或右孩子刚被访问过，则访问该结点
        {
            visit(pointer);
            pre = pointer;
            if (nodeStack.empty()) return;
            pointer = nodeStack.top();
            nodeStack.pop();
        }
        //将当前结点压入栈中
        nodeStack.push(pointer);
        //将当前结点的右子树的根结点设为当前结点
        pointer = pointer->RightChild;
    }
}

template <class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T>* root) {
    if (root->LeftChild != NULL) deleteBinaryTree(root->LeftChild);
    if (root->RightChild != NULL) deleteBinaryTree(root->RightChild);
    delete root;
    root = NULL;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::build_from_pre_and_in(char* preorder,
                                                        char* inorder, int n) {
    if (n == 0) return NULL;
    char root_element = preorder[0];
    int i = 0;
    for (; i < n; i++) {
        if (root_element == inorder[i]) break;
    }
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>;
    root->element = root_element;
    root->LeftChild = build_from_pre_and_in(preorder + 1, inorder, i);
    root->RightChild =
        build_from_pre_and_in(preorder + i + 1, inorder + i + 1, n - i - 1);
    return root;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::build_from_post_and_in(char* postorder,
                                                         char* inorder, int m) {
    if (m == 0) return NULL;
    char root_element = postorder[m - 1];
    int i = 0;
    for (; i < m; i++) {
        if (root_element == inorder[i]) break;
    }
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>;
    root->element = root_element;
    root->LeftChild = build_from_post_and_in(postorder, inorder, i);
    root->RightChild =
        build_from_post_and_in(postorder + i, inorder + i + 1, m - i - 1);
    return root;
}

int main() {
    BinaryTreeNode<char>* zero = 0;
    BinaryTreeNode<char> f('F'), g('G'), h('H');
    BinaryTreeNode<char> d('D', &f, &g), e('E', zero, &h);
    BinaryTreeNode<char> b('B', zero, &d), c('C', zero, &e);
    BinaryTreeNode<char> a('A', &b, &c);
    BinaryTree<char> Tree;
    cout << "广度优先遍历为:" << endl;
    Tree.breadthFirstOrder(&a);
    cout << endl << "先序遍历为:" << endl;
    Tree.preOrder(&a);
    cout << endl << "中序遍历为:" << endl;
    Tree.inOrder(&a);
    cout << endl << "后序遍历为:" << endl;
    Tree.postOrder(&a);
    char* preorder = "ABDFGCEH";
    char* inorder = "BFDGACEH";
    char* postorder = "FGDBHECA";
    int n = strlen(preorder);
    int m = strlen(postorder);
    BinaryTreeNode<char>* root1 =
        Tree.build_from_pre_and_in(preorder, inorder, n);
    cout << endl << "先序中序构造后广度优先遍历为:" << endl;
    Tree.breadthFirstOrder(root1);
    BinaryTreeNode<char>* root2 =
        Tree.build_from_post_and_in(postorder, inorder, m);
    cout << endl << "后序中序构造后广度优先遍历为:" << endl;
    Tree.breadthFirstOrder(root2);
    return 0;
}
