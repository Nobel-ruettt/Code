#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&n)
#define maxn 7000006
ll next[11][maxn];
ll created[maxn];
ll endmark[maxn];
ll visit[maxn];
ll sz;
ll n,arr[1000005];
vector<ll>visited_nodes;
vector<string>numbers;
void insert(string &s)
{
    ll v=0;
    for(ll i=0;i<s.size();i++)
    {
        ll id=s[i]-'0';
        if(created[next[id][v]]==0)
        {
            next[id][v]=++sz;
            created[next[id][v]]=1;
        }
        v=next[id][v];
        endmark[v]++;
    }
}
ll search_1(string &s)
{
    ll v=0;
    ll num=0;
    for(ll i=0;i<s.size();i++)
    {
        ll id=s[i]-'0';
        ll maximum=-1;
        ll numm=-1;
        for(ll j=0;j<=9;j++)
        {
            if(created[next[j][v]]==1)
            {
                if((j+id)%10>maximum)
                {
                    if(visit[next[j][v]]==1 &&  endmark[next[j][v]]==1)
                    {
                        continue;
                    }
                    maximum=(j+id)%10;
                    numm=j;
                }
            }
        }
        num=num*10+((id+numm)%10);
        v=next[numm][v];
    }
    return num;
}
ll search_2(string &s)
{
    ll v=0;
    ll is_divert=1;
    ll num=0;
    for(ll i=0;i<s.size();i++)
    {
        ll id=s[i]-'0';
        ll minimum=10;
        ll numm=-1;
        for(ll j=0;j<=9;j++)
        {

            if(created[next[j][v]]==1)
            {
                if((j+id)%10<minimum)
                {
                    if(visit[next[j][v]]==1 &&  endmark[next[j][v]]==1)
                    {
                        continue;
                    }
                    minimum=(j+id)%10;
                    numm=j;
                }
            }
        }
        num=num*10+((id+numm)%10);
        v=next[numm][v];
    }
    return num;
}
void visited(string &s)
{
    ll v=0;
    visit[v]=1;
    visited_nodes.push_back(v);
    for(ll i=0;i<s.size();i++)
    {
        ll id=s[i]-'0';
        v=next[id][v];
        visit[v]=1;
        visited_nodes.push_back(v);
    }
}
string convert(ll num)
{
    string s;
    vector<ll>dig;
    while(num!=0)
    {
        dig.push_back(num%10);
        num/=10;
    }
    for(ll i=1;i<=(19-dig.size());i++)
    {
        s.push_back('0');
    }
    reverse(dig.begin(),dig.end());
    for(ll i=0;i<dig.size();i++)
    {
        s.push_back(dig[i]+'0');
    }
    return s;
}
int main()
{
    sz=0;
    sc(n);
    for(ll i=1;i<=n;i++)
    {
        sc(arr[i]);
        string s=convert(arr[i]);
        insert(s);
        numbers.push_back(s);
    }
//    for(ll i=0;i<numbers.size();i++)
//    {
//        cout<<numbers[i]<<endl;
//    }
    ll maximum=-1;
    for(ll i=0;i<numbers.size();i++)
    {
        visited_nodes.clear();
        visited(numbers[i]);
        ll ans=search_1(numbers[i]);
        if(ans>maximum)
        {
            maximum=ans;
        }
        for(ll i=0;i<visited_nodes.size();i++)
        {
            visit[visited_nodes[i]]=0;
        }
    }
    ll minimum=4000000000000000000;
    for(ll i=0;i<numbers.size();i++)
    {
        visited_nodes.clear();
        visited(numbers[i]);
        ll ans=search_2(numbers[i]);
        if(ans<minimum)
        {
            minimum=ans;
        }
        for(ll i=0;i<visited_nodes.size();i++)
        {
            visit[visited_nodes[i]]=0;
        }
    }
    cout<<minimum<<" "<<maximum<<endl;
    return 0;
}

