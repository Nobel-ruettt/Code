#include <bits/stdc++.h>
using namespace std;
/***template***/
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define sci(n)               scanf("%d",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define maxn                 500004
#define pii                  3.1415926536
#define mod                  1000000007
/***template***/
ll n,des;
ll temp[maxn];
int main()
{
    scl(n);
    scl(des);
    FOR(i,n)
    {
        scl(temp[i]);
    }
    bool flag=0;
    FOR(i,n)
    {
        if(temp[i]==des)
        {
            flag=1;
        }
    }
    if(flag==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    sort(temp+1,temp+1+n);
    if(temp[n]<des)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(temp[1]>des)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    cout<<"2"<<endl;
    return 0;
}
