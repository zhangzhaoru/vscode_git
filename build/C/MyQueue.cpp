/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-15 10:36:54
 * @LastTime: 2020-03-15 10:45:19
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\MyQueue.cpp
 * @Description:
 */
#include <iostream>
using namespace std;
template <class T>
struct Node {
    T data;
    Node<T>* next;
};
template <class T>
class MyQueue {
   private:
    Node<T>* head;  //头指针
    int count;      //队列元素数量
   public:
    MyQueue();
    ~MyQueue();
    void outPrint();        //打印队列元素
    void push(const T& e);  //元素入队
    void front();             // 返回队首元素
    void pop();             //弹出队首元素
    int getCount();
};
template <class T>
MyQueue<T>::MyQueue() {
    count = 0;
    head = nullptr;
}

template <class T>
MyQueue<T>::~MyQueue() {
    if (head == nullptr) {
        cout << "已为空队列" << endl;
    } else {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
            count -= 1;
        }
        cout << "析构函数已完成" << endl;
        cout << "队列元素个数为" << count << endl;
    }
}
template <class T>
int MyQueue<T>::getCount() {
    cout << "队列元素个数为： " << count << endl;
    return count;
}

template <class T>
void MyQueue<T>::push(const T& e) {  //元素从链表头入队列
    if (e <= 0) {
        cout << "请输入正数值" << endl;
        return;
    }
    if (count == 0) {
        Node<T>* node = new Node<T>;
          //此处留意,声明新节点，不使用new初始化会报错
        node->data = e;
        node->next = nullptr;
        head = node;

    } else {
        Node<T>* temp = head;
        for (int i = 0; i < count - 1; i++) {
            temp = temp->next;
        }
        Node<T>* node = new Node<T>;
        temp->next = node;
        node->data = e;
        node->next = nullptr;
    }
    count++;  //队列元素数量加1
}//在链表尾部插入节点
template <class T>
void MyQueue<T>::outPrint() {
    if (head == nullptr) {
        cout << "空队列" << endl;
    } else {
        Node<T>* temp = head;
        cout << "队列元素为：";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
template <class T>
void MyQueue<T>::front() {
    if (head == nullptr) {
        cout << "这是空队列，无队首元素。" << endl;
    } else {
        Node<T>* temp;
        temp = head;
        head = head->next;
        cout << "弹出队首元素：" << temp->data << endl;
        delete temp;
        count -= 1;
    }
}

template <class T>
void MyQueue<T>::pop() {
    if (head == nullptr) {
        cout << "此为空队列，无队首元素。" << endl;
        return;
    } else {
        cout << "队首元素为：" << head->data << endl;
    }
}

int main() {
    MyQueue<int> myq;
    int a[] = {3, 59, 21, 54, 7};
    for (int i = 0; i < 5; i++) {
        myq.push(a[i]);
    }
    myq.outPrint();  // 打印队列
    myq.front();       //弹出队首元素
    myq.pop();       //打印队首元素
    myq.front();
    myq.getCount();  //获取队列元素数量
    myq.front();
    myq.front();
    myq.outPrint();
    myq.front();
    myq.front();
    myq.pop();
    return 0;
}
int main() {
    MyQueue<int> myq;
    int a[] = {3, 59, 21, 54, 7};
    for (int i = 0; i < 5; i++) {
        myq.push(a[i]);
    }
    myq.outPrint();  // 打印队列
    myq.front();       //弹出队首元素
    myq.pop();       //打印队首元素
    myq.front();
    myq.getCount();  //获取队列元素数量
    myq.front();
    myq.front();
    myq.outPrint();
    myq.front();
    myq.front();
    myq.pop();
    return 0;
}