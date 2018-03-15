#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll k;
ll visited[30];
int main()
{
    cin>>s;
    cin>>k;
    if(k>s.size())
    {
        printf("impossible\n");
        return 0;
    }
    ll count1=0;
    for(ll i=0;i<s.size();i++)
    {
        if(visited[s[i]-'a']==0)
        {
            visited[s[i]-'a']=1;
            count1++;
        }
    }
    if(count1>=k)
    {
        printf("0\n");
        return 0;
    }
    else
    {
        printf("%lld\n",k-count1);
    }
    return 0;
}
