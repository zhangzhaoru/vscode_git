/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-03-13 17:57:01
 * @LastTime: 2020-03-13 18:01:53
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\C\vectorAdd.cpp
 * @Description: vector扩容机制
 */


#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec;
    cout<<vec.capacity()<<endl;
    for(int i = 0;i<10;i++){
        vec.push_back(i);
        cout<<"size : "<<vec.size()<<endl;
        cout<<"capatcity : "<<vec.capacity()<<endl;
    }
    return 0;
}
//vector分配连续的空间存取
//超出空间范围则需对于空间进行扩容，将数据赋值到新空间
//以2倍的方式进行扩容
 
