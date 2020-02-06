//分糖果,尽可能多的满足孩子
#include<iostream>
#include<vector>
using namespace std;
void Sort(vector<int> &data);
int findCountChilder1(vector<int>& g,vector<int> &s);
int findCountChild2(vector<int> &g,vector<int> &s);

int findCountChilder1(vector<int>& g,vector<int> &s){
    Sort(g);
    Sort(s);
    int childCount = s.size();
    int sweetCount = g.size();
    int j = 0;
    int res = 0;
    for(int i = 0;i<childCount;i++){
        while(g[j]<s[i] && j<sweetCount){
            j++;
        }
        if(g[j]>=s[i] && j<sweetCount){
            res++;
            j++;
            cout<<i<<" "<<j<<endl;
        }
    }
    return res;
}

int findCountChild2(vector<int> &g,vector<int> &s){
    Sort(g);
    Sort(s);
    int child = 0;
    int cookie = 0;
    while(child<g.size() && cookie<s.size()){
        if(g[child]<=s[cookie]){
            child++;
        }
        cookie++;
    }
    return child;
}

void Sort(vector<int> &data){
    for(int i=0;i<data.size();i++){
        for(int j = i+1;j<data.size();j++){
            if(data[i]>data[j]){
                int temp = data[j];
                data[j] = data[i];
                data[i] = temp;
            }
        }
    }
}

int main(){
    vector<int> g = {1,3,6,8,20};
    vector<int> s = {2,5,9,9,10,15};
    int res = findCountChild2(s,g);
    cout<<res<<endl;
    cout<<endl;
    system("pause");
    return 0;
}
