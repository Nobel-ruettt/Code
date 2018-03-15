#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[10000];
vector<ll>baki;
int main()
{
    ll tes,N,P;
    string s;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        cin>>N>>s>>P;
        for(ll j=1;j<=N;j++)
        {
            arr[j]=1;
        }
        baki.clear();
        if(s=="odd")
        {
            for(ll j=1;j<=N;j+=2)
            {
                arr[j]=0;
            }
        }
        else if(s=="even")
        {
            for(ll j=2;j<=N;j+=2)
            {
                arr[j]=0;
            }
        }
        for(ll j=1;j<=N;j++)
        {
            if(arr[j]==1)
            {
                baki.push_back(j);
            }
        }
        cout<<baki[P-1]<<endl;
    }
    return 0;
}
