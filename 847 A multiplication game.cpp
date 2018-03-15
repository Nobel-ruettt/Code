#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll orginal,p,count,count2,check;
    while(scanf("%lld",&orginal)!=EOF)
    {
        p=1;
        check=1;
        while(p<orginal)
        {
            if(check==1)
            {
                p=p*9;
                check=0;
            }
            else if(check==0)
            {
                p=p*2;
                check=0;
            }
        }
        if(check==1)
        {
             printf("Ollie wins.\n");
        }
        else
        {
             printf("Stan wins.\n");
        }
    }
    return 0;
}
