#include <bits/stdc++.h>
/*************************** START OF TEMPLATE ****************************/
#define ll                       long long
#define ull                     unsigned long long
#define foor(i,n)             for( long long i=0 ; i < n ; i++ )
#define loop(i,a,b)          for( long long i = (a) ; i < (b) ; i++)
#define lop(i,n)               for(long long i=1;i<=n;i++)
#define mp(i,j)                make_pair(i,j)
#define pb(a)                  push_back((a))
#define inf                     1<<30
#define sc(n)                  scanf("%lld",&(n))
/*************************** END OF TEMPLATE ****************************/
using namespace std;
ll tes,num_of_coins,make,lim;
ll coins[20];
vector<ll>l;
vector<ll>r;
void cle()
{
    l.clear();
    r.clear();
}
void solve1(ll pos,ll taken,ll cur_amount,bool falsee)
{
    //cout<<pos<<" "<<taken<<" "<<cur_amount<<" "<<falsee<<endl;
    if(pos>=lim)
    {
        if(cur_amount<=make)
        {
            l.pb(cur_amount);
        }
        return ;
    }
    if(cur_amount>make)
    {
        return ;
    }
    if(taken>2)
    {
        return ;
    }
    if(cur_amount<=make)
    {
        if(falsee==1)
        {
            l.pb(cur_amount);
        }
        solve1(pos,taken+1,cur_amount+coins[pos],1);
        solve1(pos+1,0,cur_amount,0);
    }
}
void solve2(ll pos,ll taken,ll cur_amount,bool falsee)
{
    //cout<<pos<<" "<<taken<<" "<<cur_amount<<" "<<falsee<<endl;
    if(pos>=lim)
    {
        if(cur_amount<=make)
        {
            r.pb(cur_amount);
        }
        return ;
    }
    if(cur_amount>make)
    {
        return ;
    }
    if(taken>2)
    {
        return ;
    }
    if(cur_amount<=make)
    {
        if(falsee==1)
        {
            r.pb(cur_amount);
        }
        solve2(pos,taken+1,cur_amount+coins[pos],1);
        solve2(pos+1,0,cur_amount,0);
    }
}
ll binary_searc(ll key)
{
    ll low=0;
    ll high=r.size()-1;
    ll mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(r[mid]==key)
        {
            return 1;
        }
        if(r[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return 0;
}
int main()
{
    sc(tes);
    lop(i,tes)
    {
        sc(num_of_coins);
        sc(make);
        cle();
        lop(j,num_of_coins)
        {
            sc(coins[j]);
        }
        lim=(num_of_coins/2)+1;
        solve1(1,0,0,1);
        lim=(num_of_coins)+1;
        solve2(((num_of_coins/2)+1),0,0,1);
        sort(r.begin(),r.end());
        ll sum=0;
        ll falsee=0;
        foor(j,l.size())
        {
            ll ans=binary_searc(make-l[j]);
            if(ans!=0)
            {
                printf("Case %lld: YES\n",i);
                falsee=1;
                break;
            }
        }
        if(falsee==0)
        {
            printf("Case %lld: NO\n",i);
        }
    }
    return 0;
}
