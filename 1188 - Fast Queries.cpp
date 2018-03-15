#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxi 100005
struct ranges
{
    ll left;
    ll right;
    ll id;
    ranges(ll a,ll b,ll c)
    {
        left=a;
        right=b;
        id=c;
    }
    bool operator<(const ranges &p)const
    {

        return p.left>left;
    }
};
bool visited[maxi];
vector<ranges>range;
vector<ranges>range2;
vector<ll>numbers;
ll arr[maxi];
ll prev[maxi];
ll next[maxi];
ll n,q,tes;
ll seg_main[maxi+10];
ll seg[maxi+10];
ll ans[maxi];
void cle()
{
   range.clear();
   for(ll i=1;i<maxi;i++)
   {
       visited[i]=0;
   }
   numbers.clear();
}
void in_numbers()
{
    ll number;
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        if(visited[arr[i]]==0)
        {
            visited[arr[i]]=1;
            numbers.push_back(arr[i]);
        }
    }
    for(ll i=0;i<numbers.size();i++)
    {
        prev[numbers[i]]=-1;
    }
    for(ll i=1;i<=n;i++)
    {
        number=arr[i];
        if(prev[number]==-1)
        {
            next[i]=i;
            prev[number]=i;
        }
        else if(prev[number]!=-1)
        {
            next[prev[number]]=i;
            next[i]=i;
            prev[number]=i;
        }
    }
//    for(ll i=1;i<=n;i++)
//    {
//        cout<<next[i]<<endl;
//    }
}
void in_ranges()
{
    ll l,r;
    for(ll i=0;i<q;i++)
    {
        scanf("%lld%lld",&l,&r);
        range.push_back(ranges(l,r,i));
    }
    sort(range.begin(),range.end());
//    for(ll i=0;i<range2.size();i++)
//    {
//        cout<<range2[i].left<<" "<<range2[i].right<<endl;
//    }
}
void build(ll node, ll b, ll e)
{
    if (b == e) {
        seg[node] =seg_main[b];
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    build(Left, b, mid);
    build(Right, mid + 1, e);
    seg[node] = seg[Left] + seg[Right];
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return seg[node]; //রিলেভেন্ট সেগমেন্ট
    ll Left = node * 2; //আরো ভাঙতে হবে
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল
}
void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        seg[node] = newvalue;
        return;
    }
    ll Left = node * 2; //আরো ভাঙতে হবে
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    seg[node] = seg[Left] + seg[Right];
}

void lets_begin_the_segment_show()
{
    for(ll i=0;i<numbers.size();i++)
    {
        //cout<<numbers[i]<<endl;
        visited[numbers[i]]=0;
    }
    for(ll i=1;i<=n;i++)
    {
        if(visited[arr[i]]==0)
        {
            visited[arr[i]]=1;
            seg_main[i]=1;
        }
    }
    ll pointer=1;
    ll lef;
    ll righ;
    build(1,1,n);
    for(ll i=0;i<range.size();i++)
    {
        lef=range[i].left;
        righ=range[i].right;
        for(ll j=pointer;j<lef;j++)
        {
            if(seg_main[j]==1)
            {
               update(1,1,n,next[j],1);
            }
        }
        pointer=lef;
        ll ans1=query(1,1,n,lef,righ);
        ans[range[i].id]=ans1;
    }
}
int main()
{
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%lld%lld",&n,&q);
        cle();
        in_numbers();
        in_ranges();
        printf("Case %lld:\n",i);
        lets_begin_the_segment_show();
        for(ll j=0;j<range.size();j++)
        {
            printf("%lld\n",ans[j]);
        }
    }
    return 0;
}
