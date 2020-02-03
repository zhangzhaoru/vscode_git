#include <iostream>
using namespace std;

// ��ʱ��������������const�ģ������Ͳ�һ��
class A {
public:
	A(const char* s = NULL){}
	A& operator+(const A& other) {
		cout << "+++" << endl;
		return *this;
	}
	const A& operator-(const A& other) {
		cout << "---" << endl;
		return *this;
	}
};
void fun(const int &i) { cout << "const int" << endl; }
void fun(int &i) { cout << "int" << endl; }
void fun(const A &a) { cout << "const A" << endl; }
void fun(A &a) { cout << "A" << endl; }
int main() {
	fun(1+1); //����const�汾
	cout << "-----" << endl;
	int i = 10;
	fun(i); //���÷�const�汾
	cout << "-----" << endl;
	A a;
	fun(a + "aa"); //���÷�const
	fun(a - "aa"); //����const
	return 0;
}
