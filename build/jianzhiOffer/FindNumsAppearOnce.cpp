//找到只出现一次的数组
#include<iostream>
#include<vector>
#include<map>

using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    map<int,int> numCount;
    vector<int>::iterator iter = data.begin();
    while(iter!=data.end()){
        numCount[*iter++]++;
    }
    for(int i = 0;i<numCount.size();i++){
        if(numCount[i]==1){
            if((*num1)==0){
                *num1 = i;
            }else{
                *num2 = i;
            }
        }
    }
}


int main(){
    vector<int> data = {1,1,1,1,1,1,2,3,4,4,4,4,4};
    int num1 = 0;
    int num2 = 0;
    FindNumsAppearOnce(data,&num1,&num2);
    cout<<"Only happen once's number is : "<<num1<<" and "<<num2<<endl;
    system("pause");
    return 0;
}