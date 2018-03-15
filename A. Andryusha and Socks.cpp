#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ase[100005];
ll arr[200010];
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1; i<=2*n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    ll maximum=LLONG_MIN;
    ll count1_table=0;
    for(ll i=1; i<=2*n; i++)
    {
        if(ase[arr[i]]==0)
        {
            count1_table++;
            if(count1_table>maximum)
            {
                maximum=count1_table;
            }
            ase[arr[i]]++;
        }
        else if(ase[arr[i]]==1)
        {
            count1_table--;
            if(count1_table>maximum)
            {
                maximum=count1_table;
            }
            ase[arr[i]]++;
        }
    }
    cout<<maximum<<endl;
    return 0;
}
