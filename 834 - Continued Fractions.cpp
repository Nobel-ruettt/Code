#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
  if ( a==0 )
  {
      return b;
  }
  else
  {
      return gcd(b%a,a);
  }
}
int main()
{
    int upor,niche,gcds,vagfol,vagsesh,temp;
    vector<int>fractions;
    while(scanf("%d%d",&upor,&niche)==2)
    {
        fractions.clear();
          while(1)
          {
              if(niche==1)
              {
                  fractions.push_back(upor);
                  break;
              }
              gcds=gcd(upor,niche);
              upor=upor/gcds;
              niche=niche/gcds;
              vagfol=(int)(upor/niche);
              fractions.push_back(vagfol);
              vagsesh=(upor%niche);
              upor=vagsesh;
              temp=upor;
              upor=niche;
              niche=temp;
          }
          printf("[%d;",fractions[0]);
          for(int i=1;i<fractions.size()-1;i++)
          {
                 printf("%d,",fractions[i]);
          }
          printf("%d]\n",fractions[fractions.size()-1]);
    }
    return 0;
}
