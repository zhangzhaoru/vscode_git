#include <iostream>
#include <string.h>
using namespace std;
class B {
public:
	B() {}
	void show() {
		cout << num << endl;
		cout << fd << endl;
	}
private:
	int num = 10;
	//�����ΪĬ��ֵ,���� int num(10);
	double fd = 1.2;
};
int main() {
	B b;
	b.show(); //10 1.2
	return 0;
}