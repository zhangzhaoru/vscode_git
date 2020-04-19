/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-11 12:20:46
 * @LastTime: 2020-04-11 16:55:17
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\CProgram\Class\copyOnWrite.cpp
 * @Description: 写时复制
 */
#include <string.h>

#include <iostream>
using namespace std;

class String {
   public:
    String(char *str = "\0") : _capacity(strlen(str)) {
        _size = _capacity;
        _str = new char[_capacity + 5];  //多开辟了4个字节
        *(int *)_str = 1;               //前4个自己存放计数器
            _str += 4;      //使_str指向开辟的4个字节后的空间
        strcpy(_str, str);  //拷贝字符串
    }
    String(String &s)   //拷贝构造
        : _str(s._str)  //直接浅拷贝
          ,
          _capacity(s._capacity),
          _size(s._size) {
        ++(*(int *)(_str - 4));  //（str前的4个字节为计数器） ++
    }
    ~String()  //析构
    {
        Release();
    }
    void Release() {
        if (--(*(int *)(_str - 4)) == 0)  //计数器-1判断是否为零
        {
            cout << "~String " << _str << endl;
            delete[](_str - 4);
        }
    }
    String &operator=(String &s)  //赋值重载
    {
        if (_str != s._str)  //判断是否为自己为自己赋值
        {
            Release();  //处理原指针（释放空间，或者计数器-1）
            _str = s._str;
            _size = s._size;
            _capacity = s._capacity;  //赋值
            ++(*(int *)(_str - 4));   //改变先指针的计数器
        }
        return *this;
    }
    String &operator+=(char ch)  //重载，会改变，会深拷贝
    {
        char *str = new char[_capacity * 2 + 6];
        strcpy(str + 4, _str);  //先保存原字符串
        Release();  //因为要重新开辟空间，所以需要处理以前的空间
        *(int *)str = 1;  //新开辟的计数器置1
        _str = str + 4;
        _str[_size++] = ch;
        _str[_size] = '\0';
        _capacity *= 2;
        return *this;
    }
    String &append(const char *str)  //追加字符串
    {
        size_t len = strlen(str);  //方法同+=的重载
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
    char *_str;  //开辟多4个，指向4个字节后的地址
    size_t _size;
    size_t _capacity;
};
