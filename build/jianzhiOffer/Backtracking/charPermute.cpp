/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-04-04 17:55:31
 * @LastTime: 2020-04-04 18:40:25
 * @LastAuthor: Zhang Zhaoru
 * @FilePath: \vscode_git\build\jianzhiOffer\Backtracking\charPermute.cpp
 * @Description: 字符全排列
 */

#include <bits/stdc++.h>
using namespace std;
 
void swap(int &a,int &b){				//交换a,b值
	int temp=a;
	a=b;
	b=temp;
}

vector<string>  res;
void full_permutation(string a,int m){
	if(m==a.length()-1)
	{
		for(int i=0;i<a.length();i++)
		{
			cout<<a[i];
		}
		res.push_back(a);
		cout<<endl; 
	}
	else{
		for(int i=m;i<a.length();i++){
			swap(a[i],a[m]);				
			full_permutation(a,m+1);		
			swap(a[i],a[m]);				
		}						
	}	
}
 
int main()
{
	int m=0;								
	string a = "abc";
	full_permutation(a,m);

	cout<<"-----------------res----------------"<< endl;
	for(int i = 0;i<res.size(); i++){
		cout<< res[i]<< endl;
	}
	return 0;
}