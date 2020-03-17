/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 09:47:03
 * @LastTime: 2020-03-13 10:08:00
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\ShadowDeepCopy\shadowDeepCopy.cpp
 * @Description: ǳ���������
 */
#include<iostream>
#include<string.h>
using namespace std;


class String
{
 
public:
	const char* c_str()
	{
		return _str;
	}
 
	String(const char* str = "")
		:_str(new char[strlen(str) + 1])
	{
		strcpy(_str, str);
	}
	String(const String &s)//�������캯��
		:_str(NULL)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}
	~String()
	{
		if (_str)
		{
			delete[]_str;
		}
	}
    String& operator=(const String& s){
        if(this!=&s){
            String tmp(s._str);// ���ù��캯��
            swap(tmp._str,_str);
            return *this;
        }
    }
 
private:
	char* _str;
};

int main() {
    String s1("asdasfd");
    String s2(s1);// ��������¿��ٿռ�
    cout<<s2.c_str()<<endl;
    String s3 = s1;// ��������¿��ٿռ�
    s3 = s2;//ǳ���������ø�ֵ����
    cout<<s3.c_str()<<endl;
    return 0;
}