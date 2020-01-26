//找到字符串中只出现第一个一次的字符的位置
#include<iostream>
#include<string>
#include<map>
using namespace std;


int FirstNotRepeatintChar(string str){
    int len = str.size();
    if(len==0)
        return -1;
    map<int,int> hashtable;
    const int tablesize = 256;
    for(int i = 0;i<tablesize;i++){
        hashtable.insert(pair<int,int>(i,0));
    }
    
    for(int i = 0;i<len;i++){
        hashtable[str[i]]++;
    }
    for(int i=0;i<len;i++){
        if(hashtable[str[i]]==1)
            return i;
    }
    return -1;
}


int main(){
    string str = "absdafaffafcb";
    int res = FirstNotRepeatintChar(str);
    cout<<res<<endl;
    system("pause");
    return 0;
}