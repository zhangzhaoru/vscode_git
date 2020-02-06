//动态维护数据流中的中位数
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int,vector<int>,less<int>> p;
//最大堆
priority_queue<int,vector<int>,greater<int>> q;
//最小堆

void Insert(int num ){
    if(p.empty() || num<=p.top())
            p.push(num);
        else
            q.push(num);
        if(p.size()==q.size()+2){
            q.push(p.top());
            p.pop();
        }
        if(p.size()==q.size()-1){
            p.push(q.top());
            q.pop();
        }
}

double GetMeddian(){
    if(p.size()==q.size()){
        return (p.top()+q.top())/2.0;
    }else{
        return p.top();
    }
}

int main(){
    
    cout<<"Please input the Count : ";
    int count;
    cin>>count;

    for(int i=0;i<count;i++){
        int tempNum;
        cout<<"Please input a new number: ";
        cin>>tempNum;
        Insert(tempNum);
        cout<<"the current data stream 's meddian is : "
        <<GetMeddian()<<endl;
        cout<<endl;
        cout<<endl;
    }
    system("pause");
    return 0;
}