#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test,length;
    string s;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        getchar();
        cin>>s;
        if((s.size())==1)
        {
            printf("YES\n");
            continue;
        }
        length=s.size();
        if(length%2==1)
        {
            printf("NO\n");
            continue;
        }
        int power,flag;
        flag=0;
        power=length;
        while(power%2==0)
        {
            power/=2;
        }
        if(power!=1)
        {
            printf("NO\n");
            continue;
        }
        for(int j=0; j<length; j+=2)
        {
            if(s[j]=='A'&&s[j+1]=='A')
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
