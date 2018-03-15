#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll tes,m,k,n,num;
vector<ll>best,now;
int main()
{
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld",&m,&k);
        scanf("%lld",&n);
        now.clear();
        best.clear();
        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&num);
            best.push_back(num);
        }
        sort(best.begin(),best.end());
        for(ll i=1; i<m; i++)
        {
            scanf("%lld",&n);
            ll v_size=best.size();
            for(ll i=1; i<=n; i++)
            {
                scanf("%lld",&num);
                for(ll i=0;i<(min(v_size,k));i++)
                {
                    ll now_ans=num+best[i];
                    now.push_back(now_ans);
                }
            }
            sort(now.begin(),now.end());
            best=now;
            now.clear();
        }
        for(ll i=0;i<k;i++)
        {
            printf("%lld ",best[i]);
        }
        printf("\n");
    }
    return 0;
}
