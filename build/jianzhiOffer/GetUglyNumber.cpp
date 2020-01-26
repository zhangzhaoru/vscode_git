//两种方法实现输出下标为index的最小丑数

#include<iostream>
#include<vector>
using namespace std;

bool isUglyNumber(int n);
vector<int> GetUglyNumber_Solution1(int index);
int GetUglyNumber_Solution(int index);
static int mymin(int a,int b,int c);


 vector<int> GetUglyNumber_Solution1(int index){
    vector<int> res;
    if(index<=0)
        return res;
    int number = 1;
    while(index){
        if(isUglyNumber(number)){
            res.push_back(number);
            index--;
        }
        number++;
    }
    return  res;
 }

int GetUglyNumber_Solution(int index){
    if(index<=0)
        return 0;
    vector<int> res(index,0);
    res[0] = 1;
    int i = 1;
    int m2 = 0;
    int m3 = 0;
    int m5 = 0;
    while(i<index){
        res[i] = mymin(res[m2]*2,res[m3]*3,res[m5]*5);
        if(res[i]/2==res[m2]){
            m2++;
        }
        if(res[i]/3==res[m3]){
            m3++;
        }
        if(res[i]/5==res[m5]){
            m5++;
        }
        i++;
    }
    return res[index-1];
}

static int mymin(int a,int b,int c){
    if(a<b){
        if(c<a){
            return c;
        }else{
            return a;
        }
    }else{
        if(c<b){
            return c;
        }else{
            return b;
        }
    }
}


 bool isUglyNumber(int n){
     if(n==1)
        return true;
     while((n%2)==0){
         n/=2;
     }
     while((n%3)==0){
         n/=3;
     }
     while((n%5)==0){
         n/=5;
     }
     if(n==1){
         return true;
     }else{
         return false;
     }
 }

int main(){
    int index;
    cin>>index;
    cout<<"The first"<<index<<" uglynumbers are "<<endl;
    for(int i = 0;i<GetUglyNumber_Solution1(index).size();i++){
        cout<<GetUglyNumber_Solution1(index)[i];
    }
    cout<<endl;
    // if(isUglyNumber(index)){
    //     cout<<"the number "<<index<<" is uglynumber!"<<endl;
    // }else{
    //    cout<<"the number "<<index<<" is not uglynumber!"<<endl;
    // }
    cout<<"The "<<index<<" th uglynumber is "<<
    GetUglyNumber_Solution(index)<<endl;
        
    system("pause");
    return 0;
}