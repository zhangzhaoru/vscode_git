#include <iostream>
using namespace std;
class A {
private:
	A() {}; //���������˽��
	~A() {};
public:
	static A * GetInstance() {//���о�̬���������Ի�ȡ��Ψһʵ��
		if (NULL == m_pInstance) m_pInstance = new A; //(���߳���Ҫ����)
		return m_pInstance;
	}
	static void DeleteInstance() {//���о�̬����������ɾ����ʵ��
		if (m_pInstance != NULL)
			delete m_pInstance;
		m_pInstance = NULL;
	}
private:
	static A *m_pInstance; //˽�о�ָ̬�������ָ�����Ψһʵ��
	int count; //������Ա����...
};

A *A::m_pInstance = NULL;    //����ʽ
//A *A::m_pInstance = new A; //����ʽ

int main() {
	//A a; //�����ⲿ�޷������������
	A *pa = A::GetInstance(); //ͨ������ �ྲ̬��Ա���� ����ȡ�����
	A *pb = A::GetInstance(); //�ɶ�ε���
	cout << pa << pb << endl; //��ַ��ͬ��pa,pbָ�����ͬһ������
	//delete pa; //�����ⲿ�޷�ֱ�����ٸ������
	A::DeleteInstance(); //ͨ������ �ྲ̬��Ա���� �����������
	return 0;
}