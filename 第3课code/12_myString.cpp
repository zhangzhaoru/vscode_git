///myString.cpp
#include <string.h>
#include "myString.h"
//ע�⣬Ĭ�ϲ���Ҫд�ں���������
myString::myString(const char *str) {
	if (str == NULL) {
		ps = new char[1];
		ps[0] = '\0';
	}
	else {
		int len = strlen(str) + 1;
		ps = new char[len];
		strcpy(ps, str);
	}
}
myString::~myString() {
	delete[] ps;
}
const char* myString::c_str()const {
	return ps;
}