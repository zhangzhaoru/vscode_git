#include <iostream>
using namespace std;
class A {
public:
	A(int i = 0) :ci(i),num(i) {  }
	int get_ci()const {
		return ci;
	}
	void show()const {
		//set_num(0); //���󣬵��÷�const����
		//num = 0; //�����޸����ݳ�Ա
		cout << num*ci << endl; //��ȷ,���ò��޸�
		get_ci(); //��ȷ������const����
		cout << "show() const" << endl;
	}
	void show() { //����
		cout << "show()" << endl;
	}
	int set_num(int i) { num = i; }
private:
	const int ci;
	int num;
};

int main(){
	A a; //��ͨ����
	const A ca; //const����
	//ca.set_num(100); //����const����ֻ�ܵ���const����
	ca.show(); // show() const
	a.show(); //show() ��const [��const����Ҳ�ɵ���const����]
	return 0;
}