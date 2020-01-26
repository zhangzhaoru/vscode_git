//·­×ªµ¥´ÊË³ĞòÁĞ
#include<iostream>
#include<string>

using namespace std;
string ReverseSentence(string str);
void Reserve(string &substr,int begin,int end);

void Reserve(string &substr,int begin,int end){
    while(begin<end){
        char temp = substr[begin];
        substr[begin] = substr[end];
        substr[end] = temp;
        begin++;
        end--; 
    }
}

string ReverseSentence(string str){
    if(str.empty())
        return "";
    int len = str.size();
    Reserve(str,0,len-1);
    int pointer1 = 0;
    int pointer2 = 0;
    while(pointer1<len){
        if(str[pointer2]!=' '){
            pointer2++;
        }
        if(str[pointer2]==' '|| pointer2==len){
            Reserve(str,pointer1,pointer2-1);
            pointer1 = pointer2+1;
            pointer2++;
        }
    }
    return str;
}

int main(){
    string str = "I am a student";
    string res = ReverseSentence(str);
    cout<<str<<endl;
    cout<<res<<endl;
    system("pause");
    return 0;
}