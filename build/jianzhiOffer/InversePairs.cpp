#include<iostream>
#include<vector>

using namespace std;
int InversePairs(vector<int> data);
long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end);


 int InversePairs(vector<int> data) {
       int length=data.size();
        if(length<=0)
            return 0;
       //vector<int> copy=new vector<int>[length];
       vector<int> copy;
       for(int i=0;i<length;i++)
           copy.push_back(data[i]);
       long long count=InversePairsCore(data,copy,0,length-1);
       //delete[]copy;
       return count%1000000007;
    }
    long long InversePairsCore(vector<int> &data,vector<int> &copy,int start,int end)
    {
       if(start==end)
          {
            copy[start]=data[start];
            return 0;
          }
       int length=(end-start)/2;
       long long left=InversePairsCore(copy,data,start,start+length);
       long long right=InversePairsCore(copy,data,start+length+1,end); 
        
       int i=start+length;
       int j=end;
       int indexcopy=end;
       long long count=0;
       while(i>=start&&j>=start+length+1)
          {
             if(data[i]>data[j])
                {
                  copy[indexcopy--]=data[i--];
                  count=count+j-start-length;          //count=count+j-(start+length+1)+1;
                }
             else
                {
                  copy[indexcopy--]=data[j--];
                }          
          }
       for(;i>=start;i--)
           copy[indexcopy--]=data[i];
       for(;j>=start+length+1;j--)
           copy[indexcopy--]=data[j];       
       return left+right+count;
    }

int main(){
    vector<int> inputdata = {1,2,3,4,5,6,7,0};
    int res = InversePairs(inputdata);
    cout<<"the inverse pairs count is : "<<res<<endl;
    system("pause");
    return 0;
}

