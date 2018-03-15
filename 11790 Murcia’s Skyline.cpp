#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct doll
{
    ll weidth;
    ll height;
};
bool operator <(doll a,doll b)
{
    return a.weidth > b.weidth || a.weidth == b.weidth && a.height < b.height;
}
vector<doll>main_arr;
ll I[20005];
ll L[20005];
ll tes,n,a,b;
ll LongestIncreasingSubsequenceLength()
{
    ll key,low,high,mid;
    I[0]=LLONG_MIN;
    for(ll i=1;i<=n;i++)
    {
        I[i]=LLONG_MAX;
    }
    ll lis_length=0;
    for(ll i=0;i<n;i++)
    {
        key=main_arr[i].height;
        low=0;
        high=lis_length;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(I[mid]<=key)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        I[low]=key;
        L[i]=low;
        if(lis_length<low)
        {
            lis_length=low;
        }
    }
    return lis_length;
}
int main()
{
    doll s;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        main_arr.clear();
        scanf("%lld",&n);
        for(ll j=0;j<n;j++)
        {
            scanf("%lld%lld",&a,&b);
            s.height=a;
            s.weidth=b;
            main_arr.push_back(s);
        }
        sort(main_arr.begin(),main_arr.end());
        cout<<LongestIncreasingSubsequenceLength()<<endl;
    }
    return 0;
}
