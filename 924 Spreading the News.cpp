#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>lis[2505];
ll level[2505];
map<ll,ll>maxi_day;
deque<ll>lisi;
void clearr(ll siz)
{
    for(int i=0;i<siz;i++)
    {
        level[i]=-1;
    }
}
int main()
{
    ll emp,fri,friends,tes,so,source,count,day,maxi;
    scanf("%lld",&emp);
    for(int i=0;i<emp;i++)
    {
        scanf("%lld",&fri);
        for(int j=0;j<fri;j++)
        {
            scanf("%lld",&friends);
            lis[i].push_back(friends);
        }
    }
    scanf("%lld",&tes);
    for(int i=0;i<tes;i++)
    {
        scanf("%lld",&so);
        clearr(emp);
        level[so]=0;
        lisi.push_back(so);
        while(!lisi.empty())
        {
            source=lisi.front();
            lisi.pop_front();
            maxi_day[level[source]]++;
            for(int i=0;i<lis[source].size();i++)
            {
                if(level[lis[source][i]]==-1)
                {
                    level[lis[source][i]]=level[source]+1;
                    lisi.push_back(lis[source][i]);
                }
            }
        }
        map<ll,ll>:: iterator it;
        maxi=0;
        for(it=maxi_day.begin();it!=maxi_day.end();it++)
        {
            if(it->second>maxi)
            {
                day=it->first;
                maxi=it->second;
            }
            else if(it->second==maxi)
            {
                if(day==0)
                {
                    day=it->first;
                    maxi=it->second;
                }
            }
        }
        if(day==0)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld %lld\n",maxi,day);
        }
        maxi_day.clear();
        lisi.clear();
    }
    return 0;
}
