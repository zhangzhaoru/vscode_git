#include<iostream>
#include<vector>
#include<map>

using namespace std;
//map实现计数器
int MoreThanHalfNum(vector<int> input){
    map<int,int> numCount;
    vector<int>::iterator iter1 = input.begin();
    while(iter1!=input.end()){
        numCount[*iter1++]++;
    }
    int len = input.size();
    int half = len>>1;
    map<int,int>::iterator iter2 = numCount.begin();
    while(iter2!=numCount.end()){
        if((*iter2).second>half){
            return (*iter2).first;
        } 
        iter2++;
    }
    return 0;
}



int main(){
    vector<int> input = {1,2,2,2,2,2,2,2,3,4,5};
    cout<<"the number witch count more than half is:";
    cout<<MoreThanHalfNum(input)<<endl;
    system("pause");
    return 0;
}