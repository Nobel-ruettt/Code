#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.14159265358979324
int main()
{
    ll tes,n;
    double R,N,ans,degree;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        cin>>R>>n;
        N=(double)n;
        degree=pi/N;
        degree=sin(degree);
        ans=(R*degree)/(1+degree);
        printf("Case %lld: %0.10lf\n",i,ans);
    }
    return 0;
}
