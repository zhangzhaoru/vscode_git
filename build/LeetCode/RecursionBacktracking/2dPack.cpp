//二维费用背包问题
//第i件物品存在两种代价a[i]b[i]
//状态转移方程：f [i][v][u]=max{f[i-1][v][u],f[i-1][v-a[i]][u-b[i]]+c[i]}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[401][401],w[401],u[401],k[401];
int main()
{
    int v,m,n;
    scanf("%d%d%d",&v,&m,&n);//v是体积，m是质量 
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",w+i,u+i,k+i);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=v;j>=w[i];--j)
        {
            for(int q=m;q>=u[i];--q)
            {
                f[j][q]=max(f[j][q],f[j-w[i]][q-u[i]]+k[i]);
            }
        }
    }
    cout<<f[v][m];
} 