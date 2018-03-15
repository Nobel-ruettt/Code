#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tes,count1,scar,len;
    string field;
    char c;
    scanf("%lld",&tes);
    for(int i=1; i<=tes; i++)
    {
        scanf("%lld",&len);
        scanf("%*c",&c);
        cin>>field;
        count1=0;
        scar=0;
        while(1)
        {
            if(count1>(field.size()-1))
            {
                break;
            }
            if(field[count1]=='.')
            {
                scar++;
                count1+=3;
            }
            else if(field[count1]=='#')
            {
                count1++;
            }
        }
        printf("Case %d: %lld\n",i,scar);
    }
    return 0;
}
