#include <iostream>
using namespace std; // ��ʱ��������������const�ģ������Ͳ�һ��
class myString {
public:
	myString(const char* s = NULL) { cout << "const char* ����" << endl; }
	myString(const myString &other) { cout << "copy ����" << endl; }
	myString &operator=(const myString &other) {
		cout << "��ֵ����" << endl; return *this; }
	~myString() { cout << "����" << endl; }
};

myString fun() { myString ss; return ss; }
//myString &fun() {} //���ص�������
//myString *fun() {} //���ص���ָ��
int main() {
	myString s1; //const char* ����
	s1 = fun();  //myString ��ʱ�� = ss;(copy����) --> s1 = ��ʱ��;(��ֵ����)
	//fun(); 
	return 0;
}