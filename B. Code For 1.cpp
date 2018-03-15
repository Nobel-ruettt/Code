#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll find_total_elements(ll number)
{
    if(number==2||number==3)
    {
        return 3;
    }
    return (2*find_total_elements((long long)number/2))+1;
}
ll n,l,r,total_elements;
ll solve(ll number,ll left,ll right)
{
    if(left>r||right<l)
    {
        return 0;
    }
    if(left==right)
    {
        return number;
    }
    ll mid=(left+right)/2;
    return solve(number/2,left,mid-1)+solve(number%2,mid,mid)+solve(number/2,mid+1,right);
}
int main()
{
    scanf("%lld%lld%lld",&n,&l,&r);
    if(n==0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    total_elements=find_total_elements(n);
    ll ans=solve(n,1,total_elements);
    cout<<ans<<endl;
    return 0;
}
