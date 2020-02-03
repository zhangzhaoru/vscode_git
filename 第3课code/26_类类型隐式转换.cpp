#include <iostream>
using namespace std;
class A{};
class myString {
public:
	myString(const ch
	) { cout << "myString(const char* s)" << endl; }
	myString(int size, char c = ' ') { cout << "����size��c��ɵ��ַ���" << endl; }
	explicit myString(A a) { cout << "explicit myString(A a)" << endl; }
	myString(const myString& other) { cout << "copy��ʼ��" << endl; }
	myString &operator=(const myString& other) { cout << "��ֵ����" << endl; return *this; }
};

int main() {
	//int a{ 1.2 }; //����,�б��ʼ��
	//�۲��������ʽ����ת��
	int a1(1.2);  //ֱ�ӳ�ʼ��
	int a2 = 1.2; //������ʼ��
	int a3;
	a3 = 1.2;     //��ֵ

	//�Լ�����������ʵ����Щ��
	myString s1("abc"); //ֱ�ӳ�ʼ��
	cout << "--------" << endl;
	//������ʼ��[����ǰ����ʽ����ת��](���������ܻ��Ż�)
	myString s2 = "abc"; 
	cout << "========" << endl;
	s2 = "abc"; //����ʽת��Ϊ myString,�� ��ֵ
	//���� myString(const char*) �������� ��ʽת��
	cout << "--------" << endl;
	myString s3 = 20; //������Ҳ�У�
	//������ myString(int size,char c=' ')
	//ʵ���ϣ��Ǵ���һ�� 20���ո���ɵ��ַ���
	//���ǣ����ǿ��������� ����20 ��ֵ ���� myString
	//����������ң����������Ĺ��캯����ǰ��Ҫ�� explicit
	cout << "========" << endl;
	A a;
	//s3 = a; //��������explicit���Σ�A�����޷���ʽת��ΪmyString
	s3 = myString(a); 
	s3 = (myString)a;			   //ֻ����ʽ��ת��
	s3 = static_cast<myString>(a); //ֻ����ʽ��ת��
	cout << "--------" << endl;

	// Ҫʵ�� A -> B ����ʽת����B�б����з�explicit���캯��,������A
	// 1. explicit: ���ƹ��캯���������ʽת��
	// 2. explicit���캯����ֻ������ֱ�ӳ�ʼ��
	// 3. explicit�ؼ��֣�ֻ������������ʹ�ã����ⲻ�ܼ�

	// ������explicit���캯����ʵ�� myString s = xxx;�����Ŀ�������
	// Ҳ����˵������ explicit myString(const char* s = NULL)
	// ��ô��myString S("abc"); //ok  myString S = "abc"; //error

	return 0;
}