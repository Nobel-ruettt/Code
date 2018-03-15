#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i, l, v, cur;

    char s1[300], s2[300], g[]="a", d;

    while(scanf("%s", s1)==1)
    {
        l=strlen(s1);
        strcpy(s2,"");

        for(i=0; i<l; i++)
        {
            if('0'<=s1[i] && s1[i]<='9')
            {
                if(i%2==0)
                    v=(s1[i]-'0')*16;
                else
                    v=(s1[i]-'0');
            }
            else
            {
                if(i%2==0)
                v=(s1[i]-'A'+10)*16;
                else
                v=(s1[i]-'A'+10);
            }

            if(i%2==0)
                cur=v;
            else
            {
                cur+=v;
                g[0]=cur;
                strcat(s2, g);
                cur=0;
            }
        }
        printf("%s\n", s2);
        scanf("%c", &d);

    }
    return 0;
}
