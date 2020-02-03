#include <iostream>
using namespace std;
class Stack {
public:
	Stack(int len = 1024) {
		ps = new int[len];
		size = len;
		topidx = 0;
		cout << "���캯��run..." << endl;
	}
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
	Stack S;
	//S.init(); //������Ҫ�������캯�������
	for (int i = 0; i < 5; i++) {
		if (!S.isFull())
			S.push(i);
	}
	while (!S.isEmpty()) {
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
	//S.destroy(); //������Ҫ�����������������
	return 0;
}