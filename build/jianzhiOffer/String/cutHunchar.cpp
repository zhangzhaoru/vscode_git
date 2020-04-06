/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-06 17:02:22
 * @LastTime: 2020-04-06 17:36:09
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\cutHunchar.cpp
 * @Description: ��ȡ���к��ֵ��ַ���
 */
#include<iostream>
#include<string>
using namespace std;

string curHanChar1(string str,int num){
    return str.substr(0,num);
} 
//string����ͻ��ж����һ���ֽ��Ƿ�Ϊ����İ�����֣��ǵĻ���������ֽڡ�

// ����ռ�����ֽڣ�ÿ���ֽڵ�ASCII�����λ��Ϊ1������charĬ��Ϊ���������ͣ���
// �Ժ��ֵ�ASCII��С��0����Ӣ�����ֵ������ַ�ռһ���ֽڣ�ASCII�����λΪ0��ֵ
// ��0~127֮�䡣��ˣ�ֻ��Ҫ�жϸ��ֽ��Ƿ�С��0�����ƶϳ��Ƿ�Ϊ������֡�����ǰ
// ��������������������֣�����ż�������������������֣����������

string curHanChar2(string str,int num){
    int temp = num-1;
    while(temp>=0&&str[temp]<0){
        temp--;
    }
    if((num-temp)%2==0){
        num--;
    }
    return str.substr(0,num);
}

int countHunChar(string s){
    int count = 0;
    for(int i = 0;i<s.length(); i++){
        if(s[i]<0){
            count++;
        }
    }
    return count/2;
}

int main() {
    string str = "��ABC��DEF������";
    int num = 6;
    cout<<curHanChar2(str,num)<<endl;
    cout<<countHunChar(str)<<endl;
    return 0;
}