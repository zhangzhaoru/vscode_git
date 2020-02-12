//√∞≈›≈≈–Ú∑®
#include<iostream>
#include<vector>
#include<sstream>

using namespace std;
void Swap(int *&pointer1,int *&pointer2);
void Bubble(vector<int> &input );


void Bubble(vector<int> &input ){
    if(input.size()<=1)
        return;
    for(int i = 0;i<input.size()-1;i++){
        for(int j = 0;j<input.size()-i-1;j++){
            if(input[j]>input[j+1]){
                int *pointer1 = &input[j];
                int *pointer2 = &input[j+1];
                Swap(pointer1,pointer2);
            }
        }
    }
}

void Swap(int *&pointer1,int *&pointer2){
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
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
    Bubble(input);
    cout<<input;
    cout<<endl;
    system("pause");
    return 0;

}

