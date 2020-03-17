/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-15 09:35:38
 * @LastTime: 2020-03-15 09:50:06
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\CopyWhenWrite.cpp
 * @Description:Ð´Ê±¸´ÖÆ
 */
#include <string.h>
#include <iostream>
using namespace std;

class String {
   public:
    String(const char *str = "") : _str(new char[strlen(str) + 1 + 4]) {
        cout << "String()" << endl;
        _str += 4;
        GetCount() = 1;
        strcpy(_str, str);
    }
    String(String &s) : _str(s._str) {
        cout << "String(String &)" << endl;
        GetCount()++;
    }
    String &operator=(String &s) {
        cout << "String &operator= " << endl;
        if (this != &s) {
            Release();
            _str = s._str;
            GetCount()++;
        }
        return *this;
    }
    ~String() {
        cout << "~String()" << endl;
        Release();
    }

   public:
    char &operator[](size_t index) {
        if (GetCount() == 1) {
            return _str[index];
        }
        GetCount()--;
        char *tmp = _str;
        _str = new char[strlen(tmp) + 1 + 4];
        _str += 4;
        strcpy(_str, tmp);
        GetCount() = 1;
        return _str[index];
    }

   private:
    int &GetCount() { return *(int *)(_str - 4); }
    void Release() {
        if (--GetCount() == 0) {
            cout << "Release()" << endl;
            delete[](_str - 4);
            _str = NULL;
        }
    }

   private:
    char *_str;
};