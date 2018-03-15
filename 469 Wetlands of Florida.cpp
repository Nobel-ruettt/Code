#include <bits/stdc++.h>
using namespace std;
#define ll long long
string plot[110];
int main()
{
    ll tes,sesh;
    char c;
    scanf("%lld",&tes);
    for(ll i=1;i<=tes;i++)
    {
        scanf("%c",&c);
        ll j=0;
        while(1)
        {
            getline(cin,plot[j]);
            if(plot[j][0]!='W' && plot[j][0]!='L')
            {
                break;
            }
            j++;
        }
        sesh=j-1;

    }
    return 0;
}
