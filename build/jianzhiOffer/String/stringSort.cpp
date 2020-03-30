/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-28 19:21:35
 * @LastTime: 2020-03-28 20:18:33
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\String\stringSort.cpp
 * @Description: �ַ�������
 *  ���� 1 ��Ӣ����ĸ�� A �� Z ���У������ִ�Сд��
    ���� 2 ��ͬһ��Ӣ����ĸ�Ĵ�Сдͬʱ����ʱ����������˳�����С�
    ���� 3 ����Ӣ����ĸ�������ַ�����ԭ����λ�á�
 */


#include <iostream>
#include <vector>
#include<string>
using namespace std;
string String_Sorting(string str) {
    vector<char> temp;  
    for(int i = 0;i<26;i++){
        for(int j = 0;j<str.size();j++){
            if(str[j]-'a'==i||str[j]-'A'==i){
                temp.push_back(str[j]);
            }
        }
    }
    for(int i = 0,k = 0;i<str.size(),k<temp.size();i++){
        if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')){
            str[i] = temp[k++];
        }
    }
    return str;
}
//������
int main() {
    string str;
    //���ܶ�ȡ�ո񣬶�ȡ�ո��Ʊ�����з�ֹͣ��ȡ   
    while (getline(cin, str)) {
        cout << String_Sorting(str) << endl;
    }
    return 0;
}