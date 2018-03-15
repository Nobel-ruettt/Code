#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000050
string s[50005];
ll nextt[2][maxn];
ll created[maxn];
ll endmark[maxn];
ll sz,n,maxim;
void cle()
{
    for(ll i=0; i<2; i++)
    {
        for(ll j=0; j<maxn; j++)
        {
            nextt[i][j]=0;
            created[j]=0;
            endmark[j]=0;
        }
    }
    sz=0;
    maxim=0;
}
void insert(string &s)
{
    ll v=0;
    for(ll i=0; i<s.size(); i++)
    {
        ll id=s[i]-'0';
        if(created[nextt[id][v]]==0)
        {
            nextt[id][v]=++sz;
            created[nextt[id][v]]=1;
        }
        v=nextt[id][v];
        endmark[v]++;
        if((endmark[v]*(i+1))>maxim)
        {
            maxim=(endmark[v]*(i+1));
        }
//        cout<<v<<" "<<endmark[v]<<endl;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        cle();
        scanf("%lld",&n);
        for(ll i=1; i<=n; i++)
        {
            cin>>s[i];
            insert(s[i]);
        }
        cout<<maxim<<endl;
    }
    return 0;
}
