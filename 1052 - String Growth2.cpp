#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
const int mod=1e9+7;
struct matrix{
    LL f[2][2];
 };
LL flag,mark,dp[100];
void init()
{
    LL i,j,k;
    dp[0]=0;
    dp[1]=1;
    for(i=2;;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        if(dp[i]>=1e9)break;
    }
    mark=i;
}
matrix mul(matrix a,matrix b)
{
    LL i,j,k;
    matrix c;
    memset(c.f,0,sizeof(c.f));
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                c.f[i][j]=c.f[i][j]+a.f[i][k]*b.f[k][j];
                if(c.f[i][j]>=mod||c.f[i][j]<=-mod)
                {
                    flag=1;
                    c.f[i][j]%=mod;
                }
            }
        }
    }
    return c;
}
matrix pow_mod(matrix a,LL b)
{
    matrix s;
    s.f[0][0]=s.f[1][1]=1;
    s.f[0][1]=s.f[1][0]=0;
    while(b)
    {
        if(b&1)s=mul(s,a);
        a=mul(a,a);
        b=b>>1;
    }
    return s;
}
int main()
{
    init();

    LL T,tt=0;
    cin>>T;
    while(T--)
    {
        LL n,m,x,y,k,i,j;
        flag=0;
        cin>>n>>x>>m>>y>>k;
        if(n>m)
        {
            swap(n,m);
            swap(x,y);
        }
        cout<<"Case "<<++tt<<": ";
        if(y<x||m>=mark||x<dp[n]||y<dp[m]){cout<<"Impossible"<<endl;continue;}
        matrix e,g,gg;
        e.f[0][0]=0;e.f[1][0]=e.f[0][1]=e.f[1][1]=1;
        g=pow_mod(e,n-1);
        gg=pow_mod(e,m-1);
        /*cout<<"******"<<endl;
        cout<<g.f[0][0]<<" "<<g.f[0][1]<<endl;
        cout<<g.f[1][0]<<" "<<g.f[1][1]<<endl;
        cout<<"******"<<endl;
        */
        LL a,b,c,d,p,q;
        a=g.f[0][0]+g.f[1][0];
        b=g.f[0][1]+g.f[1][1];
        c=gg.f[0][0]+gg.f[1][0];
        d=gg.f[0][1]+gg.f[1][1];
        //cout<<"*"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(flag||(c*x-a*y)%(b*c-a*d)||(d*x-b*y)%(a*d-b*c)){cout<<"Impossible"<<endl;continue;}
        p=(d*x-b*y)/(a*d-b*c);
        q=(c*x-a*y)/(b*c-a*d);
        //cout<<"***"<<p<<" "<<q<<endl;
        if(p<0||q<0){cout<<"Impossible"<<endl;continue;}
        g=pow_mod(e,k-1);
        cout<<(p*(g.f[0][0]+g.f[1][0])+q*(g.f[0][1]+g.f[1][1]))%mod<<endl;
    }
    return 0;
}
