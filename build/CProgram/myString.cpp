//自定义MyString函数
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class myString {
public:
	myString(const char *str = NULL);
	~myString();
	const char* c_str()const;
private:
	char *ps;
};


myString::myString(const char *str) {
	if (str == NULL) {
		ps = new char[1];
        cout<<"无参构造"<<endl;
		ps[0] = '\0';
	}
	else {
		int len = strlen(str) + 1;
		ps = new char[len];
        cout<<"有参构造"<<endl;
		strcpy(ps, str);
	}
}

myString::~myString() {
	delete[] ps;
}
const char* myString::c_str()const {
	return ps;
}


int main(){
    myString s1;
    myString s2("abc");
    cout<<"-"<<s1.c_str()<<"-"<<endl;
    cout<<s2.c_str()<<endl;
    system("pause");
    return 0;
}