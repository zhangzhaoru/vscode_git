#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class myString {
public:
	myString(const char *str = NULL) {
		if (str == NULL) {
			ps = new char[1];
			ps[0] = '\0';
		}
		else {
			int len = strlen(str) + 1;
			ps = new char[len];
			strcpy(ps, str);
		}
		cout << "myString����" << endl;
	}
	~myString() {
		if (ps) delete[] ps;
		cout << "myString����" << endl;
	}
private:
	char *ps;
};
class Stu {
public:
	Stu() {	cout << "Stu����" << endl;	}
	~Stu() { cout << "Stu����" << endl; } 
private:
	myString name;
	int age;
};
int main() {
	Stu st1;
	return 0;
}