#include <iostream>
using namespace std;
class Person {
public:
	Person(int _age) :age(_age) { sum += _age; count++;	}
	static int get_count();
	static double get_avg() { return double(sum) / count; }
private:
	int age;         //����
	static int count;//������
public:
	//���� static int sum=0;
	static int sum;  //�����ܺ�
};

//�˴����ܼ� static
int Person::get_count() { return count; }
//�˴����ܼ� static
int Person::sum = 0;   //�����ʼ��
int Person::count = 0; //������(bss,rw?)

int main(){
	//�ⲿֱ�ӷ��ʷ�ʽ������::��̬������
	cout << Person::sum << endl; 
	//cout << Person::count; //����,ͬ����Ȩ�޿���
	//��̬��Ա������ռ�ö�����ڴ�ռ�
	cout << sizeof(Person) << endl; //4

	Person p1(10);
	//��̬������Ҳ����ͨ�� ����.������ ������
	//������ҪȨ�ޣ����ڲ�����
	cout << p1.sum << endl;
	Person p2(20);

	//��̬��Ա����������ͨ�� ����::������ ������
	cout << Person::get_avg() << endl;
	//Ҳ����ͨ�� ����.������ ������
	cout << p1.get_count() << endl; //2
	cout << p2.get_count() << endl; //���������һ��
	return 0;
}