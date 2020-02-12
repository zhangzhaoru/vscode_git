//智能输入
#include<iostream>
#include<stdarg.h>
#include<string>

using namespace std;



void print_int(int value){
	char temp[30] = {0};
	int count = 0;
	while(value){
		temp[count++] = value%10;
		//从小到大依次记录各位数字至字符数组
		value = value/10;
	}
	while(count){
		count--;
		putchar(temp[count]+'0');
		//向终端输出一个字符
	}
}

void print_string(const char * value){
	while(*value){
		putchar(*value);
		value++;
	}
}

void smart_print(const char* control,...){
	va_list parm;
	va_start(parm,control);
	while(*control){
		if(*control=='%'){
			char type = *(control+1);
			if(type=='d'){
				int value = va_arg(parm,int);
				print_int(value);
			}
			else if(type == 'c'){
				int value = va_arg(parm,int);
				putchar(value);
			}
			else if (type == 's'){
				const char *value = va_arg(parm, const char *);
				print_string(value);
			}
			if (type == 'd' || type == 'c' || type == 's'){
				control++;
			}
		}
		else{
			putchar(*control);
		}
		control++;
	}
	va_end(parm);
}

int main(){
	char name[20] = "LinMu";
	int age = 28;
	smart_print("My name is %s, I'm %d years old.\n", name, age);
	smart_print("My name is spelled:\n");
	int i = 0;
	while(name[i]){
		smart_print("%c\n", name[i]);
		i++;
	}
	system("pause");
	return 0;
}









