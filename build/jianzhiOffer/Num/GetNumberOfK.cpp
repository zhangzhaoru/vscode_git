//统计一个数字在排序数组中出现的次数。
#include<iostream>
#include<vector>

using namespace std;
int GetNumberOfK(vector<int> data ,int k);
int getlast(vector<int> data,int left,int right,int k);
int getfirst(vector<int> data,int left,int right,int k);


  int GetNumberOfK(vector<int> data ,int k){
    if(data.size()==0)
        return 0;
    int first = getfirst(data,0,data.size()-1,k);
    int last = getlast(data,0,data.size()-1,k);
    if(first>-1 && last>-1){
        return last-first+1;
    }else{
        return 0;
    }
  }
int getfirst(vector<int> data,int left,int right,int k){
    if(left>right){
        return -1;
    }
    int mid = ((right-left)>>1)+left;
    int middata = data[mid];
    if(k==middata){
        if(mid==left || data[mid-1]!=k){
            return mid;
        }else{
            right = mid-1;
        }
    }else if(k>middata){
        left = mid+1;
    }else if(k<middata){
        right = mid-1;
    }
    return getfirst(data,left,right,k);
}

int getlast(vector<int> data,int left,int right,int k){
    if(left>right)
        return -1;
    int mid = ((right-left)>>1)+left;
    int middata = data[mid];
    if(k==middata){
        if(mid==right || data[mid+1]!=k){
            return mid;
        }else{
            left = mid+1;
        }
    }else if(k>middata){
        left = mid+1;
    }else if(k<middata){
        right = mid-1;
    }
    return getlast(data,left,right,k);
}

int main(){
    vector<int> data = {1,2,2,2,2,2,3,3,3,4};
    int k = 3;
    int len = GetNumberOfK(data,k);
    cout<<"The count of k is: "<<len<<endl;
    system("pause");
    return 0;
}