#include <iostream>
#include <string.h>
using namespace std;
class A {
public:
	A(int n, double f) { num = n; fd = f; }
private:
	int num;
	double fd;
};
class B {
public:
	              //���캯���ĳ�ʼֵ�б�
	B(int n, double f) :num(n), fd(f) {}
private:
	int num;
	double fd;
};
int main() {
	A a(10, 1.2);
	B b(10, 1.2);
	return 0;
}