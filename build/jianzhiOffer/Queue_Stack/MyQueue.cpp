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
    Node<T>* head;  //ͷָ��
    int count;      //����Ԫ������
   public:
    MyQueue();
    ~MyQueue();
    void outPrint();        //��ӡ����Ԫ��
    void push(const T& e);  //Ԫ�����
    void front();             // ���ض���Ԫ��
    void pop();             //��������Ԫ��
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
        cout << "��Ϊ�ն���" << endl;
    } else {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
            count -= 1;
        }
        cout << "�������������" << endl;
        cout << "����Ԫ�ظ���Ϊ" << count << endl;
    }
}
template <class T>
int MyQueue<T>::getCount() {
    cout << "����Ԫ�ظ���Ϊ�� " << count << endl;
    return count;
}

template <class T>
void MyQueue<T>::push(const T& e) {  //Ԫ�ش�����ͷ�����
    if (e <= 0) {
        cout << "����������ֵ" << endl;
        return;
    }
    if (count == 0) {
        Node<T>* node = new Node<T>;
          //�˴�����,�����½ڵ㣬��ʹ��new��ʼ���ᱨ��
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
    count++;  //����Ԫ��������1
}//������β������ڵ�
template <class T>
void MyQueue<T>::outPrint() {
    if (head == nullptr) {
        cout << "�ն���" << endl;
    } else {
        Node<T>* temp = head;
        cout << "����Ԫ��Ϊ��";
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
        cout << "���ǿն��У��޶���Ԫ�ء�" << endl;
    } else {
        Node<T>* temp;
        temp = head;
        head = head->next;
        cout << "��������Ԫ�أ�" << temp->data << endl;
        delete temp;
        count -= 1;
    }
}

template <class T>
void MyQueue<T>::pop() {
    if (head == nullptr) {
        cout << "��Ϊ�ն��У��޶���Ԫ�ء�" << endl;
        return;
    } else {
        cout << "����Ԫ��Ϊ��" << head->data << endl;
    }
}

int main() {
    MyQueue<int> myq;
    int a[] = {3, 59, 21, 54, 7};
    for (int i = 0; i < 5; i++) {
        myq.push(a[i]);
    }
    myq.outPrint();  // ��ӡ����
    myq.front();       //��������Ԫ��
    myq.pop();       //��ӡ����Ԫ��
    myq.front();
    myq.getCount();  //��ȡ����Ԫ������
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
    myq.outPrint();  // ��ӡ����
    myq.front();       //��������Ԫ��
    myq.pop();       //��ӡ����Ԫ��
    myq.front();
    myq.getCount();  //��ȡ����Ԫ������
    myq.front();
    myq.front();
    myq.outPrint();
    myq.front();
    myq.front();
    myq.pop();
    return 0;
}