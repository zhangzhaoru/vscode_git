#include<iostream>
#include<vector>
#include<sstream>

using namespace std;


void Swap(int*& pointer1,int *&pointer2){
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

void qSort(int left,int right,vector<int> &v){
    if(left>right)
        return;
    int i,j,base;
    i = left;
    j = right;
    base = v[left];
    while(i<j){
        while(v[j]>=base && i<j){
            j--;
        }
        while(v[i]<=base && i<j){
            i++;
        }
        if(i<j){
            int *pointer1 = &v[i];
            int *pointer2 = &v[j];
            Swap(pointer1,pointer2);
        }

    }
    v[left] = v[i]; 
    v[i] = base;
    qSort(left,i-1,v);
    qSort(i+1,right,v);
}



istream& operator >>(istream &input1,vector<int> &v){
    string s;
    getline(input1,s);
    stringstream ss(s);
    int x;
    while(ss>>x){
        v.push_back(x);
    }
    return input1;
}

ostream &operator<<(ostream &output,vector<int> &v){
    for(auto i = v.begin();i<v.end();i++){
        output<<*i;
        if(i<v.end()-1){
            output<<" ";
        }
    }
    return output;
}



int main(){
    vector<int> input = {1,2,3,4,5,6,3,2,1};
    vector<int> output1;
      for(int i = 0;i<input.size();i++){
        cout<<input[i]<<" ";
    }
    cout<<endl;
    qSort(0,input.size()-1,input);
    cout<<input;
    cout<<endl;
    system("pause");
    return 0;

}

