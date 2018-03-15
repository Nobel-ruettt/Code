#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool dis[1000010];
ll gcd(ll a, ll b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b%a, a);
}
int main()
{
    ll N,sq,m,n,count_prim,a,b,c,count1,a1,b1,c1,not_tri;
    double sq1;
    while(scanf("%lld",&N)==1)
    {
        for(int j=0;j<=N;j++)
        {
            dis[j]=0;
        }
        sq1=sqrt(N)+0.0000001;
        sq=(long long)sq1;
        count_prim=0;
        for(ll i=sq; i>=2; i--)
        {
            m=i;
            for(ll j=m-1; j>=1; j--)
            {
                n=j;
                if(((m%2)!=(n%2)) && (gcd(m,n))==1)
                {
                    a=(m*m)-(n*n);
                    b=2*m*n;
                    if(a>b)
                    {
                        swap(a,b);
                    }
                    c=(m*m)+(n*n);
                    if(c<=N)
                    {
                        count_prim++;
                        count1=1;
                        a1=a*count1;
                        b1=b*count1;
                        c1=c*count1;
                        while(c1<=N)
                        {
                            dis[a1]=1;
                            dis[b1]=1;
                            dis[c1]=1;
                            count1++;
                            a1=a*count1;
                            b1=b*count1;
                            c1=c*count1;
                        }
                    }
                }
            }
        }
        not_tri=0;
        for(int j=1;j<=N;j++)
        {
            if(dis[j]==0)
            {
                not_tri++;
            }
        }
        cout<<count_prim<<" "<<not_tri<<endl;
    }
    return 0;
}
