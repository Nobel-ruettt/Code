#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[10][100][100][2];
ll a,b,k,maximum;
vector<ll>numbers;
void do_the_things(ll number)
{
    numbers.clear();
    while(1)
    {
        if(number<10)
        {
            numbers.push_back(number);
            break;
        }
        numbers.push_back(number%10);
        number/=10;
    }
    reverse(numbers.begin(),numbers.end());
}
ll solve(ll pos,ll remainder1,ll remainder2,ll is_big)
{
    if(pos==numbers.size())
    {
        if(remainder1==0 && remainder2==0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[pos][remainder1][remainder2][is_big]!=-1)
    {
        return dp[pos][remainder1][remainder2][is_big];
    }
    if(is_big==1)
    {
        ll sum=0;
        for(ll i=0; i<=numbers[pos]; i++)
        {
            ll now_remainder1=remainder1*10+i;
            now_remainder1=(now_remainder1%k);
            ll now_remainder2=(((i%k)+(remainder2%k))%k);
            if(i==numbers[pos])
            {
                sum+=solve(pos+1,now_remainder1,now_remainder2,1);
            }
            else
            {
                sum+=solve(pos+1,now_remainder1,now_remainder2,0);
            }
        }
        return dp[pos][remainder1][remainder2][is_big]=sum;
    }
    else
    {
        ll sum=0;
        for(ll i=0; i<=9; i++)
        {
            ll now_remainder1=remainder1*10+i;
            now_remainder1%=k;
            ll now_remainder2=(((i%k)+(remainder2%k))%k);
            sum+=solve(pos+1,now_remainder1,now_remainder2,0);
        }
        return dp[pos][remainder1][remainder2][is_big]=sum;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1; cas<=tes; cas++)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        if(k>=100)
        {
            cout<<"Case "<<cas<<": ";
            cout<<0<<endl;
            continue;
        }
        memset(dp,-1,sizeof dp);
        ll maximum=a-1;
        do_the_things(maximum);
        ll ans1=solve(0,0,0,1);
        memset(dp,-1,sizeof dp);
        maximum=b;
        do_the_things(maximum);
        ll ans2=solve(0,0,0,1);
        printf("Case %lld: %lld\n",cas,ans2-ans1);
    }
    return 0;
}
