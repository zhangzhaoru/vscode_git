/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-23 11:48:20
 * @LastTime: 2020-02-23 13:13:50
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\LeetCode\BinaryTreeandGraph\BinaryTreeClass.cpp
 * @Description: ���������ʵ��
 */
#include <iostream>
using namespace std;
template <class T>
class BinaryTreeNode {
    friend class BinaryTree<T>;

   private:
    T element;                      //����������
    BinaryTreeNode<T>* LeftChild;   //�������ӽ��
    BinaryTreeNode<T>* RightChild;  //�����Һ��ӽ��
   public:
    BinaryTreeNode();
    BinaryTreeNode(const T& ele);
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);
    bool isLeaf() const;  //�жϸý���Ƿ���Ҷ�ӽ�㣬���ǣ��򷵻�true
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
    bool IsEmpty() const;                //�ж϶������Ƿ�Ϊ����
    BinaryTreeNode<T>* getRoot() const;  //���ض������ĸ����
    void breadthFirstOrder(
        BinaryTreeNode<T>* root);  //������ȱ�����rootΪ����������
    void preOrder(BinaryTreeNode<T>* root);  //���������rootΪ����������
    void inOrder(BinaryTreeNode<T>* root);  //���������rootΪ����������
    void postOrder(BinaryTreeNode<T>* root);  //���������rootΪ����������
    void deleteBinaryTree(BinaryTreeNode<T>* root);  //ɾ����rootΪ����������
    void visit(BinaryTreeNode<T>* pointer);  //���ʵ�ǰ���
    BinaryTreeNode<T>* build_from_pre_and_in(char* preorder, char* inorder,
                                             int n);
    //����ǰ�������������ʽ���������
    BinaryTreeNode<T>* build_from_post_and_in(char* postorder, char* inorder,
                                              int m);
    //���ݺ��������������ʽ���������
    int getRootId1(char* preorder, char* inorder,
                   int n);  //���ظ����������������ʽ�����
    int getRootId2(char* postorder, char* inorder,
                   int m);  //���ظ����������������ʽ�����
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
        //��ջ����
        for (; pointer->LeftChild != NULL; pointer = pointer->LeftChild) {
            nodeStack.push(pointer);
        }
        //��ջ����
        while (pointer != NULL &&
               (pointer->RightChild == NULL || pointer->RightChild == pre))
        //��ǰ����Һ���Ϊ�ջ��Һ��Ӹձ����ʹ�������ʸý��
        {
            visit(pointer);
            pre = pointer;
            if (nodeStack.empty()) return;
            pointer = nodeStack.top();
            nodeStack.pop();
        }
        //����ǰ���ѹ��ջ��
        nodeStack.push(pointer);
        //����ǰ�����������ĸ������Ϊ��ǰ���
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
    cout << "������ȱ���Ϊ:" << endl;
    Tree.breadthFirstOrder(&a);
    cout << endl << "�������Ϊ:" << endl;
    Tree.preOrder(&a);
    cout << endl << "�������Ϊ:" << endl;
    Tree.inOrder(&a);
    cout << endl << "�������Ϊ:" << endl;
    Tree.postOrder(&a);
    char* preorder = "ABDFGCEH";
    char* inorder = "BFDGACEH";
    char* postorder = "FGDBHECA";
    int n = strlen(preorder);
    int m = strlen(postorder);
    BinaryTreeNode<char>* root1 =
        Tree.build_from_pre_and_in(preorder, inorder, n);
    cout << endl << "����������������ȱ���Ϊ:" << endl;
    Tree.breadthFirstOrder(root1);
    BinaryTreeNode<char>* root2 =
        Tree.build_from_post_and_in(postorder, inorder, m);
    cout << endl << "����������������ȱ���Ϊ:" << endl;
    Tree.breadthFirstOrder(root2);
    return 0;
}
