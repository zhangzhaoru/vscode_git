#include <iostream>
using namespace std;
class Stack {
public:
	Stack() { //�޲ι��캯��
		ps = new int[1024];
		size = 1024;
		topidx = 0;
		cout << "Stack() run" << endl;
	}
	Stack(int len) { //���ι��캯��
		ps = new int[len];
		size = len;
		topidx = 0;
		cout << "Stack(int len) run" << endl;
	}

	/*Stack(int len = 1024) {
	ps = new int[len];
	size = len;
	topidx = 0;
	}*/
	~Stack() {
		if (ps) delete[] ps;
		ps = NULL;
		cout << "��������run..." << endl;
	}
	bool isEmpty()const { return topidx == 0; }
	bool isFull()const { return topidx == size; }
	int top()const {
		return ps[topidx - 1];
	}
	void push(int data) {
		ps[topidx++] = data;
	}
	void pop() {
		topidx--;
	}
private:
	int *ps;
	int topidx;
	int size;
};
int main() {
	Stack S1;      //�����޲ι��� ����д Stack S1();
	Stack S2(100); //���ô��ι���
	Stack S3{ 10 };//���ô��ι���
	Stack *p1 = new Stack; //�޲ι���
	Stack *p2 = new Stack(10);//���ι���
	Stack *p3 = new Stack{ 10 };//���ι���
								//���գ�
	int a1; //����д int a1(); ���Ǻ�������
	int a2(10);
	int a3{ 10 };
	int *pa1 = new int;
	int *pa2 = new int(10);
	int *pa3 = new int{ 20 };
	return 0;
}