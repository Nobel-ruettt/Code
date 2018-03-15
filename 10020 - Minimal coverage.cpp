#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if(p1.first > p2.first)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
vector<pair<ll,ll> >lis;
deque<pair<ll,ll> >lisi;
int main()
{
    ll tes,co_l,co_r,m,l_r,r_r,count1,now_l,now_r,prev_l;
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld",&m);
        while(scanf("%lld%lld",&co_l,&co_r))
        {
            if(co_l==0&&co_r==0)
            {
                break;
            }
            if(co_l<0 && co_r<0)
            {
                continue;
            }
            lis.push_back(make_pair(co_l,co_r));
        }
        sort(lis.begin(),lis.end(),compare);
        l_r=lis[0].first;
        r_r=lis[0].second;
        lisi.push_front(make_pair(l_r,r_r));
        prev_l=l_r;
        count1=1;
        while(1)
        {

            if(r_r>=m || count1==lis.size())
            {
                printf("break e dhukse  r_r %lld and  count1 %lld\n",r_r,count1);
                break;
            }
            now_l=lis[count1].first;
            now_r=lis[count1].second;
            printf("%lld  %lld",now_l,now_r);
            if(now_r>r_r)
            {
                 if(now_l==0)
                 {
                     lisi.clear();
                     lisi.push_front(make_pair(now_l,now_r));
                     r_r=now_l;
                     l_r=0;
                     prev_l=0;
                 }
                 else if(now_l==prev_l)
                 {
                     lisi.pop_front();
                     lisi.push_front(make_pair(now_l,now_r));
                     r_r=now_r;
                     prev_l=now_l;
                 }
                 else if(now_l>prev_l && now_l<=r_r)
                 {
                     lisi.push_front(make_pair(now_l,now_r));
                     r_r=now_r;
                     prev_l=now_l;
                 }
            }
            printf("%lld r_r\n",r_r);
            count1++;
        }
        while(!lisi.empty())
        {
            printf("%lld %lld\n",lisi.back().first,lisi.back().second);
            lisi.pop_back();
        }
    }
    return 0;
}
