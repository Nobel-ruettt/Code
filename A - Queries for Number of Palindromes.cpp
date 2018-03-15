#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long int ull;
# define mx 1000005
struct simplehash
{
    int len;
    long long base, mod;
    vector <int> P, H, R;

    simplehash() {}
    simplehash(const char* str, long long b, long long m)
    {
        base = b, mod = m, len = strlen(str);
        P.resize(len + 3, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r)
    {
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r)
    {
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};
struct stringhash
{
    simplehash sh1, sh2;
    stringhash() {}
    stringhash(const char* str)
    {
        sh1 = simplehash(str, 1949313259, 2091573227);
        sh2 = simplehash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r)
    {
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }

    inline long long reverse_hash(int l, int r)
    {
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
} S;

char str[mx];
struct node
{
    ll l,r,id;
    node(ll _l,ll _r,ll _id)
    {
        l=_l;
        r=_r;
        id=_id;
    }
};
bool cmp(node aa,node bb)
{
    if(aa.r<bb.r)
    {
        return 1;
    }
    else if(aa.r==bb.r)
    {
        if(aa.l<bb.l)
        {
            return 1;
        }
    }
    return 0;
}
ll ans[1000005];
ll cumsum[1000005];
ll cumsum2[100005];
ll q;
vector<node>query;
int main()
{
    scanf(" %s",str);
    ll len=strlen(str);
    S = stringhash(str);
    scanf("%d",&q);
    for(ll i=1;i<=q;i++)
    {
        ll l,r;
        scanf("%d %d",&l,&r);
        l--;
        r--;
        query.push_back(node(l,r,i));
    }
    sort(query.begin(),query.end(),cmp);
    ll now=-1;
    for(ll i=0;i<query.size();i++)
    {
//        cout<<query[i].l<<" "<<query[i].r<<" "<<query[i].id<<endl;
        bool f=0;
        while(now<query[i].r)
        {
            f=1;
            now++;
//            cout<<now<<endl;
            for(ll j=0;j<=now;j++)
            {
                if(S.range_hash(j,now)==S.reverse_hash(j,now))
                {
                    cumsum[j]++;
                }
            }
        }
        if(f)
        {
            for(ll j=0;j<=query[i].r;j++)
            {
                if(j==0)
                {
                    cumsum2[j]=cumsum[j];
                }
                else
                {
                    cumsum2[j]=cumsum[j]+cumsum2[j-1];
                }
            }
            if(query[i].l>0)
            {
                ans[query[i].id]=cumsum2[query[i].r]-cumsum2[query[i].l-1];
            }
            else
            {
                ans[query[i].id]=cumsum2[query[i].r];
            }
        }
        else
        {
            if(query[i].l>0)
            {
                ans[query[i].id]=cumsum2[query[i].r]-cumsum2[query[i].l-1];
            }
            else
            {
                ans[query[i].id]=cumsum2[query[i].r];
            }
        }
    }
    for(ll i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
aaaa
10
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
*/
