#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200004
struct node
{
    string s;
    node(string s1)
    {
        s=s1;
    }
    bool operator<(const node &p)const
    {
        return p.s.size()>s.size();
    }
};
ll n;
string s;
vector<node>em;
ll nextt[11][maxn];
ll created[maxn];
ll endmark[maxn];
ll sz,is_consistent;
void cle()
{
    for(ll i=0; i<11; i++)
    {
        for(ll j=0; j<maxn; j++)
        {
            nextt[i][j]=0;
            created[j]=0;
            endmark[j]=0;
        }
    }
    sz=0;
    em.clear();
}
void insert(string &s)
{
    ll v=0;
    is_consistent=1;
    for(ll i=0; i<s.size(); i++)
    {
        ll id=s[i]-'0';
        if(created[nextt[id][v]]==0)
        {
            nextt[id][v]=++sz;
            created[sz]=1;
        }
        if(endmark[v]==1)
        {
            //cout<<v<<" "<<endmark[v]<<endl;
            is_consistent=0;
        }
        v=nextt[id][v];
    }
    endmark[v]=1;
}
int main()
{
    ll tes,ans;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld",&n);
        cle();
        ll ans=1;
        for(ll i=0; i<n; i++)
        {
            cin>>s;
            em.push_back(node(s));
        }
        sort(em.begin(),em.end());
        for(ll i=0;i<em.size();i++)
        {
            //cout<<em[i].s<<endl;
            insert(em[i].s);
            if(is_consistent==0)
            {
                 ans=0;
            }
        }
        if(ans==0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
