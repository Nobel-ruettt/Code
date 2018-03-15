#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v;
vector<ll>tail;
ll CeilIndex(ll l, ll r, ll key)
{
    while (r-l > 1)
    {
        ll m = l + (r-l)/2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

ll LongestIncreasingSubsequenceLength()
{
    if (v.size() == 0)
        return 0;
    tail.push_back(v[0]);
    for (ll i = 1; i < v.size(); i++)
    {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[tail.size()-1])
            tail.push_back(v[i]);
        else
            tail[CeilIndex(-1,tail.size()-1, v[i])]=v[i];
    }
    return tail.size();
}

int main()
{
    ll N=1;
    while(1)
    {
        v.clear();
        tail.clear();
        ll value;
        scanf("%lld",&value);
        if(value==-1)
        {
            break;
        }
        v.push_back(value);
        while(1)
        {
            scanf("%lld",&value);
            if(value==-1)
            {
                break;
            }
            v.push_back(value);
        }
        reverse(v.begin(),v.end());
        if (N >1) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n",N++,LongestIncreasingSubsequenceLength());
    }
    return 0;
}
