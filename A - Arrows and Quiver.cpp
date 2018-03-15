#include <bits/stdc++.h>
using namespace std;
#define ll long long
deque<ll>qu;
ll n,m,c;
ll targets[100005];
ll usingg[100005];
ll timee[100005];
ll type[100005];
void cle()
{
    qu.clear();
}
bool can(ll max_size)
{
    ll now_sizee=0;
    for(ll i=1;i<=n;i++)
    {
        usingg[i]=0;
        type[i]=0;
    }
    for(ll i=1;i<=m;i++)
    {
        timee[i]=0;
    }
    ll sizee=0;
    ll lagbe=0;
    ll left_pointer=0;
    for(ll i=1;i<=m;i++)
    {
        ll now_type=targets[i];
        if(usingg[now_type]==0)
        {
            if(sizee<max_size)
            {
                timee[i]=now_type;
                type[now_type]=i;
                sizee++;
                lagbe++;
                usingg[now_type]=1;
            }
            else if(sizee==max_size)
            {
                while(timee[left_pointer]==0)
                {
                    left_pointer++;
                }
                usingg[timee[left_pointer]]=0;
                timee[left_pointer]=0;
                timee[i]=now_type;
                type[now_type]=i;
                lagbe++;
                usingg[now_type]=1;
            }
        }
        else if(usingg[now_type]==1)
        {
            timee[type[now_type]]=0;
            timee[i]=now_type;
            type[now_type]=i;
        }
    }
    if(lagbe>c)
    {
        return 0;
    }
    return 1;
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        scanf("%lld%lld%lld",&n,&m,&c);
        cle();
        for(ll i=1;i<=m;i++)
        {
            scanf("%lld",&targets[i]);
        }
        ll check=0;
        for(ll i=1;i<=m;i++)
        {
            if(targets[i]>n)
            {
                check=1;
            }
        }
        if(check==1)
        {
            printf("-1\n");
            continue;
        }
        ll low=1;
        ll high=m;
        ll ans=-1;
        while(low<=high)
        {
            ll mid=(low+high)/2;
            cle();
            if(can(mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(ans==-1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n",ans);
        }
    }
    return 0;
}
