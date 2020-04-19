/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-09 21:34:35
 * @LastTime: 2020-04-10 00:35:51
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Queue_Stack\test.cpp
 * @Description: 实现多线程
 */

#include<condition_variable>
#include<string>
#include<mutex>
#include<thread>
#include<iostream>
using namespace std;
string res("");
mutex mtx;
bool done = false;
condition_variable A, B, C, D;
void fun_A(int times) 
{
	while (times--)
	{
		unique_lock<mutex> locker(mtx);
		A.wait(locker);
		res += 'A';
		B.notify_one();
	}
	done = true;
}
void fun_B() 
{
	while (!done) 
	{
		unique_lock<mutex> locker(mtx);
		B.wait(locker);
		res += 'B';
		C.notify_one();
	}
}
void fun_C() 
{
	while (!done) 
	{
		unique_lock<mutex> locker(mtx);
		C.wait(locker);
		res += 'C';
		D.notify_one();
	}
}
void fun_D() 
{
	while (!done) 
	{
		unique_lock<mutex> locker(mtx);
		D.wait(locker);
		res += 'D';
		A.notify_one();
	}
}
int main() 
{
	int num;
	while (cin >> num) 
	{
		res = "";
		thread t1(fun_A, num);
		thread t2(fun_B);
		thread t3(fun_C);
		thread t4(fun_D);
		A.notify_one();
		t1.join();
		t2.join();
		t3.join();
		t4.join();
		cout << res << endl;
		done = false;
	}
	return 0;
}
