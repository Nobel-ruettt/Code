#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2;
ll al[30];
void cle()
{
    for(ll i=0;i<30;i++)
    {
        al[i]=0;
    }
}
int main()
{
    ll tes;
    scanf("%lld",&tes);
    for(ll cas=1;cas<=tes;cas++)
    {
        cle();
        cin>>s1>>s2;
        for(ll i=0;i<s2.size();i++)
        {
            al[s2[i]-'a']++;
        }
        ll count1=0;
        for(ll i=0;i<s1.size();i++)
        {
            ll askii=s1[i]-'a';
            if(al[askii]>0)
            {
                count1++;
                al[askii]--;
            }
            else
            {
                break;
            }
        }
        printf("%lld\n",count1);
    }
    return 0;
}
