#include <iostream>
#include <string>
using namespace std;

class A {
public:
	A(int n = 0) :num(n) {}
	A(const A &other):num(other.num) { }
private:
	int num; 
};
int main() {
	A a1;
	A a2(a1);  //ֱ�ӳ�ʼ��
	A a3 = a1; //������ʼ��
	const A a4;
	A a5 = a4; //����û��const,�ʹ���
	return 0;
}