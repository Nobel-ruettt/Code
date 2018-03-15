#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll rat;
int main()
{
    ll tes;
    cin>>tes;
    for(ll cas=1;cas<=tes;cas++)
    {
        ll n,r;
        cin>>n>>r;
        ll sum=1500;
        for(ll i=1;i<=n;i++)
        {
            cin>>rat;
            sum+=rat;
        }
        if(sum==r)
        {
            printf("Correct\n");
        }
        else
        {
            printf("Bug\n");
        }
    }
    return 0;
}
