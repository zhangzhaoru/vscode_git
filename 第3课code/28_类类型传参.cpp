#include <iostream>
using namespace std; // ��ʱ��������������const�ģ������Ͳ�һ��
class myString {
public:
	myString(const char* s = NULL) { cout << "const char* ����" << endl; }
	myString(const myString &other) { cout << "copy ����" << endl; }
	myString &operator=(const myString &other) { cout << "��ֵ����" << endl; }
	~myString() { cout << "����" << endl; }
};
void fun(myString ss){}
//void fun(myString &ss) {} //���ò������൱�� myString &ss = s1; û�п����ڴ�
//void fun(myString *ss) {} //ָ�������ֻ�Ǹ�����4�ֽڵ�ָ������
int main() {
	myString s1 = "abc"; // �����ǣ�����ʽת����Ȼ��copy���졣
						 // �������Ż���ֱ�� const char* ����
	fun(s1); //copy���죺 ���壺 myString ss = s1;
	fun("abc"); //���壺myString ss = "abc"; ��s1��������
	return 0;
}