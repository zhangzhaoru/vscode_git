#include <iostream>
using namespace std;
class A {
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
};
void fun() { A a2; }
int main() {
	{
		A a1;
	}
	//�����a1�Ѿ������ˡ�
	fun();
	//�����fun�е�a2�Ѿ������ˡ�
	cout << "----------" << endl;
	int i = 0;
	//ע��a3��������
	for (A a3; i < 3; i++) {
		cout << i << endl;
	}
	cout << "----------" << endl;
	//ע��a4��������
	for (int j = 0; j < 3; j++) {
		A a4; //ÿ��ѭ�����ṹ��
		cout << j << endl;
	}//whileѭ��Ҳ�����
	cout << "----------" << endl;
	A *pa = new A; //����
	delete pa; //����delete����
	return 0;
}