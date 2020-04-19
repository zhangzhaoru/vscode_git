/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-11 12:20:46
 * @LastTime: 2020-04-11 16:55:17
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\Class\copyOnWrite.cpp
 * @Description: дʱ����
 */
#include <string.h>

#include <iostream>
using namespace std;

class String {
   public:
    String(char *str = "\0") : _capacity(strlen(str)) {
        _size = _capacity;
        _str = new char[_capacity + 5];  //�࿪����4���ֽ�
        *(int *)_str = 1;               //ǰ4���Լ���ż�����
            _str += 4;      //ʹ_strָ�򿪱ٵ�4���ֽں�Ŀռ�
        strcpy(_str, str);  //�����ַ���
    }
    String(String &s)   //��������
        : _str(s._str)  //ֱ��ǳ����
          ,
          _capacity(s._capacity),
          _size(s._size) {
        ++(*(int *)(_str - 4));  //��strǰ��4���ֽ�Ϊ�������� ++
    }
    ~String()  //����
    {
        Release();
    }
    void Release() {
        if (--(*(int *)(_str - 4)) == 0)  //������-1�ж��Ƿ�Ϊ��
        {
            cout << "~String " << _str << endl;
            delete[](_str - 4);
        }
    }
    String &operator=(String &s)  //��ֵ����
    {
        if (_str != s._str)  //�ж��Ƿ�Ϊ�Լ�Ϊ�Լ���ֵ
        {
            Release();  //����ԭָ�루�ͷſռ䣬���߼�����-1��
            _str = s._str;
            _size = s._size;
            _capacity = s._capacity;  //��ֵ
            ++(*(int *)(_str - 4));   //�ı���ָ��ļ�����
        }
        return *this;
    }
    String &operator+=(char ch)  //���أ���ı䣬�����
    {
        char *str = new char[_capacity * 2 + 6];
        strcpy(str + 4, _str);  //�ȱ���ԭ�ַ���
        Release();  //��ΪҪ���¿��ٿռ䣬������Ҫ������ǰ�Ŀռ�
        *(int *)str = 1;  //�¿��ٵļ�������1
        _str = str + 4;
        _str[_size++] = ch;
        _str[_size] = '\0';
        _capacity *= 2;
        return *this;
    }
    String &append(const char *str)  //׷���ַ���
    {
        size_t len = strlen(str);  //����ͬ+=������
        _capacity = len + _size;
        char *tmp = new char[_capacity + 6];
        strcpy(tmp + 4, _str);
        Release();
        *(int *)tmp = 1;
        _str = tmp + 4;
        strcpy(_str + _size, str);
        _size = _capacity;
        return *this;
    }

   private:
    char *_str;  //���ٶ�4����ָ��4���ֽں�ĵ�ַ
    size_t _size;
    size_t _capacity;
};
