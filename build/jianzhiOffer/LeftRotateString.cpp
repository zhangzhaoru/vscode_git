//左旋转字符串
//两种方法实现字符串循环左移
//1 使用substr提取子字符串重新组合
//2 对各个子字符串翻转在对字符串翻转
#include<iostream>
#include<string>

using namespace std;

void reserve(string &str,int begin,int end);
string LeftRotateString1(string str, int n);
string LeftRotateString2(string str, int n);

string LeftRotateString1(string str, int n){
    if(n==0 || str.size()<=1)
        return str;
    if(n>str.size())
        n = n%(str.size());
    string str1 = str.substr(0,n);
    //从第0位开始，截取n位
    string str2 = str.substr(n);
    //从下标为n开始截取到结束
    string res = str2+str1;
    return res;
}


string LeftRotateString2(string str, int n){
    int len = str.size();
    if(!str.empty() && n<=len){
        if(n>=0 && n<=len){
            reserve(str,0,n-1);
            reserve(str,n,len-1);
            reserve(str,0,len-1);
        }
    }
    return str;
}

void reserve(string &str,int begin,int end){
    while(begin<end){
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;
        begin++;
        end--;
    }
}

int main(){
    string str = "abcdefgh";
    int n = 2;
    string res1 = LeftRotateString1(str,n);
    string res2 = LeftRotateString2(str,n);
    cout<<str<<endl;
    cout<<res1<<endl;
    cout<<res2<<endl;

    system("pause");
    return 0;
}