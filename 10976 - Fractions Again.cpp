#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >pira;
int gcd(int n1, int n2)
{
    if (n2 != 0)
       return gcd(n2, n1%n2);
    else
       return n1;
}
int main()
{
    int k,gcds,lcms,count1=0,first,sec_first,sec_second,sec_upor,sec_niche;
    while(scanf("%d",&k))
    {
        pira.clear();
        first=k;
        while(1)
        {
            first=first+1;
            gcds=gcd(k,first);
            lcms=(k*first)/gcds;
            sec_niche=lcms;
            sec_first=(lcms/k);
            sec_second=(lcms/first);
            sec_upor=sec_first-sec_second;
            if(sec_upor==1)
            {
                pira.push_back(make_pair(first,lcms));
                ///printf("%d/%d = %d/%d + %d/%d\n",1,k,1,first,1,sec_niche);
            }
            if(sec_niche==first)
            {
                break;
            }
        }
        printf("%d\n",pira.size());
        for(int i=0;i<pira.size();i++)
        {
            printf("%d/%d = %d/%d + %d/%d\n",1,k,1,pira[i].second,1,pira[i].first);
        }
    }
    return 0;
}
