#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s;
ll n;
ll al_cnt[30];
ll factorial[21];
void cle()
{
    memset(al_cnt,0,sizeof  al_cnt);
}
void fac()
{
    factorial[0]=1;
    for(ll i=1;i<=20;i++)
    {
        factorial[i]=factorial[i-1]*i;
    }
}
ll count_permutation(ll length)
{
    ll upore=factorial[length];
    ll niche=1;
    for(ll i=0;i<26;i++)
    {
        niche*=factorial[al_cnt[i]];
    }
    return (upore/niche);
}
void solve(ll cur_pos,ll per_rem)
{
    if(cur_pos>s.size())
    {
        printf("\n");
        return ;
    }
    ll i;
    for(i=0;i<26;i++)
    {
        if(al_cnt[i])
        {
            al_cnt[i]--;
            ll use=count_permutation(s.size()-cur_pos);
            if(use<per_rem)
            {
                al_cnt[i]++;
                per_rem-=use;
            }
            else
            {
                break;
            }
        }
    }
    printf("%c",char(i+'a'));
    solve(cur_pos+1,per_rem);
}
int main()
{
    fac();
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        cle();
        cin>>s>>n;
        for(ll i=0;i<s.size();i++)
        {
            al_cnt[s[i]-'a']++;
        }
        if(count_permutation(s.size())<n)
        {
            printf("Case %lld: Impossible\n",cas);
        }
        else
        {
            printf("Case %lld: ",cas);
            solve(1,n);
        }
    }
    return 0;
}

