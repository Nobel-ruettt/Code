#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sc(n) scanf("%lld",&n)
vector<ll>graph[1000];
ll visited[1000];
string ans;
vector<ll>ab;
vector<ll>c;
vector<ll>a;
vector<ll>b;
ll u,v,count_a,count_b,count_c;
int main()
{
    ll n,m;
    sc(n);sc(m);
    for(ll i=1;i<=m;i++)
    {
        sc(u);
        sc(v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(ll i=0;i<1000;i++)
    {
        ans.push_back('z');
    }
    for(ll i=1;i<=n;i++)
    {
        if(graph[i].size()==(n-1))
        {
            visited[i]=2;
            ans[i]='b';
            count_b++;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            ans[i]='a';
            count_a++;
            for(ll j=0;j<graph[i].size();j++)
            {
                ll adj=graph[i][j];
                if(visited[adj]!=2)
                {
                    visited[adj]=1;
                    ans[adj]='a';
                    count_a++;
                }
            }
            break;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=3;
            ans[i]='c';
            count_c++;
        }
    }
    //cout<<count_a<<" "<<count_b<<" "<<count_c<<endl;
    bool flag=0;
    for(ll i=1;i<=n;i++)
    {
        if(visited[i]==1)
        {

            ll count1_a=0;
            ll count1_b=0;
            count1_a++;
            for(ll j=0;j<graph[i].size();j++)
            {
                ll adj=graph[i][j];
                if(visited[adj]==2)
                {
                    count1_b++;
                }
                else if(visited[adj]==1)
                {
                    count1_a++;
                }
                else if(visited[adj]==3)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                break;
            }

            if(count1_a==count_a && count1_b==count_b)
            {
                continue;
            }
            flag=1;
            break;
        }
        else if(visited[i]==2)
        {

            ll count1_a=0;
            ll count1_b=0;
            ll count1_c=0;
            count1_b++;
            for(ll j=0;j<graph[i].size();j++)
            {
                ll adj=graph[i][j];
                if(visited[adj]==2)
                {
                    count1_b++;
                }
                else if(visited[adj]==1)
                {
                    count1_a++;
                }
                else if(visited[adj]==3)
                {
                    count1_c++;
                }
            }

            if(count1_a==count_a && count1_b==count_b && count1_c==count_c)
            {
//                cout<<"dhukse"<<endl;
                continue;
            }
            flag=1;
            break;
        }
        else if(visited[i]==3)
        {
//            cout<<i<<" : ";
//            for(ll j=0;j<graph[i].size();j++)
//            {
//                cout<<graph[i][j]<<" ";
//            }
//            cout<<endl;
            ll count1_b=0;
            ll count1_c=0;
            count1_c++;
            for(ll j=0;j<graph[i].size();j++)
            {
                ll adj=graph[i][j];
                if(visited[adj]==2)
                {
                    count1_b++;
                }
                else if(visited[adj]==3)
                {
                    count1_c++;
                }
                else if(visited[adj]==1)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                break;
            }
            if(count1_b==count_b && count1_c==count_c)
            {
                continue;
            }
            flag=1;
            break;
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(ans[i]=='z')
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
        for(ll i=1;i<=n;i++)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
/*
5 8
1 2
1 4
1 5
2 4
4 5
2 5
2 3
5 3
*/
